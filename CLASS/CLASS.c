#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define length 1000
#define WEATHER "Rainy  26 degrees Celsius  78.8 degrees Fahrenheit"
struct Information* head = NULL;
int Turn(char* str)//数字字符串转整形函数
{
	while (*str == ' ') str++;//跳过前面空格
	int result = 0;
	while (*str >= '0' && *str <= '9')//将每个字符转化为int
	{
		int data = *str - '0';
		result = result * 10 + data;
		str++;
	}
	return result;
} 
struct Information//用户信息结构体
{
	char name[length];
	char rate[length];
	char destination[length];
	char departdate[length];
	char duration[length];
	char cost[length];
	struct Information* next;
};
struct City//城市信息结构体
{
	char cityname[length];
	char cityweather[length];
	float citylongitude;
}Allcity[78710];//城市信息结构体数组
void fgetspro(FILE* file,char* str)
{
	int i = 0;
	char tempchar = fgetc(file);
	while (tempchar != ',')
	{
		str[i] = tempchar;
		i ++;
		tempchar = fgetc(file);
	}
	str[i] = '\n';
}

int KMP(char* str1,char *str2)//快速查找
{
	int next[length];
	next[0] = 0;
	int j = 0;
	int size1 = 1;
	for (int i = 1; str1[i] != '\0'&&str1[i] != '\n'; i ++)
	{
		while (j > 0 && str1[i] != str1[j])  j = next[j - 1];
		if (str1[i] == str1[j]) j ++;
		next[i] = j;
		size1++;
	}
	j = 0;
	int size2 = 0;
	int ans = 0;
	for (int i = 0; str2[i] != '\0'&&str2[i]!='\n'; i ++)
	{
		size2++;
	}
	for (int i = 0; str2[i] != '\0'&&str2[i]!='\n'; i ++)
	{
		while (j > 0 && str2[i] != str1[j]) j = next[j - 1];
		if (str2[i] == str1[j]) j ++;
		if(j == size1)
		{
			if (size1 == size2) ans = 2;
			else ans = 1;
		}
	}
	return ans;
}

void CitySave()
{
	FILE* file = fopen("city.txt", "r");
	if (file != NULL)
	{
		int n; 
		for (int i = 0; i < 78707; i++)
		{
			char country[length];
			char mark[length];
			float latitude; 
			char next[length];
			fscanf(file, "%d,", &n);
			fgetspro(file, Allcity[i].cityname);
			fgetspro(file, country);
			fgetspro(file, mark);
			fscanf(file, "%f,", &latitude);
			fscanf(file, "%f,", &(Allcity[i].citylongitude));
			fgets(next,length,file);
		}
	}
}

int Leapyear(int year)//判断闰年
{
	int n = 0;
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
		{
			n ++;
		}
		else n = n;
	}
	else n = n;
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			n ++;
		}
		else n = n;
	}
	else n = n;
	if (n > 0) return 1;
	else return 0;
}

char Menu[7][length] =//主菜单
{
	"Order Entry",
	"Order Statistics",
	"Order Query",
	"Destination Time",
	"Destination Weather",
	"Travel Depareture Reminder",
	"Close Menu"
};
char Menu1[2][length] =//子菜单1
{
	"Sort by User Level",
	"Sort by Order Amount Size"
};
char Menu2[5][length] =//子菜单2
{
	"Enter user Rate.",
	"Enter user Departuredate and Rate.",
	"Enter user Name",
	"Enter Destination",
	"Enter Departuredate and Destination"
};

void Show()//打印菜单
{
	int k = 1;
	printf("=========MENU=========\n");
		for (int i = 0; i < 7; i++)
		{
			printf("(%d)%s\n", k + i, Menu[i]);
		}
}
void Savedata(struct Information* head)//数据文件保存函数
{
	if (head == NULL) printf("No List.\n");
	else 
	{
		struct Information* current = head;
		int n = 0;
		while (current != NULL)
		{
			current = current->next;
			n++;
		}
		FILE* file = fopen("data.txt", "w");
		current = head;
		if (file == NULL)
		{
			printf("ERROR!\n");
			return;
		}
		fprintf(file,"%d\n",n);
		while (current != NULL)
		{
		
			fprintf(file, "%s%s%s%s%s%s", current->name, current->rate, current->destination, current->departdate, current->duration, current->cost);//将链表中数据写入文件
			current = current->next;
		}
		fclose(file);
	}
}  
char* Name(char* username)//输入用户名函数
{
	fgets(username, length, stdin);
	while (username == NULL || username[0] == '\n')
	{
		memset(username, '\0', sizeof(username));
		printf("Please Enter in the Correct Form.  ");//错误输入报错
		scanf("%s", username);
	}
	return username;
}
void Rate(char* rate)//输入用户等级函数
{
	fgets(rate, length, stdin);
	while (rate[0] == '\n'|| Turn(rate) > 4 || Turn(rate) < 1)//四个等级
	{
		memset(rate, '\0', sizeof(rate));
		printf("Please Enter in the Correct Form.  ");
		fgets(rate, length, stdin);
	}
}
/*void Destination(char* destination)//输入用户目的地函数
{
	fgets(destination,length, stdin);
	while ( destination[0] == '\n')
	{
		printf("Please Enter in the Correct Form.  ");
		fgets(destination, length, stdin);
	}
}*/

char* CorrectCityName()//输入用户目的地函数
{
	while (1)
	{
		char cdestination[length];
		printf("Please Enter your Destination: ");
		char tempdestination[length];
		fgets(tempdestination, length, stdin);
		//system("cls");
		static char May[70000][length];//存放可能为目的地的名称
		int num = 0;
		for (int i = 0; i<78707; i ++)
		{
			if (KMP(tempdestination, Allcity[i].cityname) == 1)//KMP快速查找
			{
				strcpy(May[num], Allcity[i].cityname);
				//printf("%s %d\n",Allcity[i].cityname,i);
				num++;
			}
			if (KMP(tempdestination, Allcity[i].cityname) == 2)
			{
				strcpy(May[0], Allcity[i].cityname);
				return May[0];
			}
		}
		
		printf("You may seek:\n"); 
		for (int i = 0; i<num; i ++)
		{
			printf("%s\n", May[i]);//逐个打印
		}
	}
}
void DestinationTimeGeneration()//目的地时间生成函数
{
	if (head == NULL) printf("No List.\n");
	else 
	{
		char UserDestination[length];
		strcpy(UserDestination, CorrectCityName());
		printf("%s",UserDestination);
		float templongitude;
		for(int i = 0; i < 78707; i ++)
		{
			if (KMP(UserDestination, Allcity[i].cityname) == 2)
			{
				templongitude = Allcity[i].citylongitude;
				break;
			}
		}
		//时间生成
		time_t timep;
    	struct tm *p;
		time(&timep);
		p = gmtime(&timep);
		int hour = p->tm_hour;
		int minute = p->tm_min;
		int second = p->tm_sec;
		//经度判断时区加减
		if (templongitude > 0)
		{
			templongitude += 7.5;
		}
		hour += templongitude / 15;
		if (hour < 0) hour += 24;
		else if (hour >= 24) hour -=24;
		printf("The local time is %dhour %dminute %dsecond\n", hour, minute, second);
		memset(UserDestination, '\0', sizeof(UserDestination));
	}
}
void Departuredate(char* departdate)//输入用户出发日期函数
{
	int n;
	while (1)
	{
		n = 1;
		fgets(departdate, length, stdin);
		if (departdate[0] == '\n')
		{
			n = 0;
			printf("Please Enter your Departure Date:  (2024xxxx)");
			fgets(departdate, length, stdin);
		}
		else
		{
			int size = 0;
			for(int i = 0; departdate[i] != '\n'; i ++)
			{
				size++;
			}
			if (size != 8)
			{
				n = 0;
				printf("Please Enter in the Correct Form. ");
				continue;
			}
			if (Leapyear(Turn(departdate) / 10000) == 1)
			{
				if ((Turn(departdate) / 100 % 100) > 12 || (Turn(departdate) / 100 % 100) < 1) //月出错处理，如13月0月
				{
					n = 0;
					printf("Please Enter in the Correct Form. ");
					continue;
					//system("pause");
				}
				if ((Turn(departdate) /100 % 100) == 1 || (Turn(departdate) /100 % 100) == 3 || (Turn(departdate) /100 % 100) == 5 || (Turn(departdate) /100 % 100) == 7 || (Turn(departdate) /100 % 100) == 8 || (Turn(departdate) /100 % 100) == 10 || (Turn(departdate) /100 % 100) == 12)
				{
					if (Turn(departdate) % 100 > 31 || Turn(departdate) % 100 < 1) //日出错处理
					{
						n = 0;
						printf("Please Enter in the Correct Form. ");
						continue;
						//system("pause");
					}
				}
				if ((Turn(departdate) /100 % 100) == 2)
				{
					if ((Turn(departdate) % 100) > 29 || ((Turn(departdate) % 100) < 1))//闰年特判
					{
						n = 0;
						printf("Please Enter in the Correct Form. ");
						continue;
						//system("pause");
					}
				}
				if ((Turn(departdate) /100 % 100) == 4 || (Turn(departdate) /100 % 100) == 6 || (Turn(departdate) /100 % 100) == 9 || (Turn(departdate) /100 % 100) == 11)
				{
					if ((Turn(departdate) % 100) > 30 ||  ((Turn(departdate) % 100) < 1))
					{
						n = 0;
						printf("Please Enter in the Correct Form. ");
						continue;
						//system("pause");
					}
				}
			}
			else 
			{
				if ((Turn(departdate) / 100 % 100) > 12 || (Turn(departdate) / 100 % 100) < 1) 
				{
					n = 0;
					printf("Please Enter in the Correct Form. ");
					continue;
					//system("pause");
				}
				if ((Turn(departdate) /100 % 100) == 1 || (Turn(departdate) /100 % 100) == 3 || (Turn(departdate) /100 % 100) == 5 || (Turn(departdate) /100 % 100) == 7 || (Turn(departdate) /100 % 100) == 8 || (Turn(departdate) /100 % 100) == 10 || (Turn(departdate) /100 % 100) == 12)
				{
					if (Turn(departdate) % 100 > 31 || Turn(departdate) % 100 < 1) 
					{
						n = 0;
						printf("Please Enter in the Correct Form. ");
						continue;
						//system("pause");
					}
				}
				if ((Turn(departdate) /100 % 100) == 2)
				{
					if ((Turn(departdate) % 100) > 28 || ((Turn(departdate) % 100) < 1))
					{
						n = 0;
						printf("Please Enter in the Correct Form. ");
						continue;
						//system("pause");
					}
				}
				if ((Turn(departdate) /100 % 100) == 4 || (Turn(departdate) /100 % 100) == 6 || (Turn(departdate) /100 % 100) == 9 || (Turn(departdate) /100 % 100) == 11)
				{
					if ((Turn(departdate) % 100) > 30 ||  ((Turn(departdate) % 100) < 1))
					{
						n = 0;
						printf("Please Enter in the Correct Form. ");
						continue;
						//system("pause");
					}
				}
			}
		}
		if (n == 1) return ;//直至输入正确返回
	}
}
void Duration(char* duration)//输入用户旅游天数函数
{
	fgets(duration, length, stdin);
	while (duration[0] == '\n')
	{
		memset(duration, '\0', sizeof(duration));
		printf("Please Enter in the Correct Form.  ");
		fgets(duration, length, stdin);
	}
}
void Cost(char* cost)//输入用户订单金额函数
{
	fgets(cost, length, stdin);
	while (cost == NULL || cost[0] == '\n')
	{
		memset(cost, '\0', length);
		printf("Please Enter in the Correct Form.  ");
		fgets(cost, length, stdin);
	}
}
struct Information* OrderEntry()//用户信息录入函数
{
	struct Information* current, *tail;
	tail = head;
	while(tail != NULL && tail->next != NULL)  tail = tail->next;//每添加一个节点，遍历链表至最后一位

	current = (struct Information*)malloc(sizeof(struct Information));
	if (head == NULL)
	{
		head = current;
	}
	else
	{
		tail->next = current;//将上一个用户信息结构体的next指针指向当前结构体
	}
	current->next = NULL;
	//调用先前函数
	printf("Please Enter your Name:");
	Name(current->name);
	printf("Please Enter your Rate:  ");
	Rate(current->rate);
	strcpy(current->destination, CorrectCityName());
	printf("Please Enter your Departure Date:  ");
	Departuredate(current->departdate);
	printf("Please Enter your Travel Days:  ");
	Duration(current->duration);
	printf("Please Enter your Order Amount:  ");
	Cost(current->cost);
	return head;
}
struct Information* FileOrderEntry(FILE *file)//从文件中读取用户信息函数
{
	struct Information* current, *tail;
	tail = head;
	while(tail != NULL && tail->next != NULL)  tail = tail->next;//每添加一个节点，遍历链表至最后一位
	char username[length], userdestination[length];
	current = (struct Information*)malloc(sizeof(struct Information));
	fgets(current->name, length, file);
	
	if (head == NULL)
	{
		head = current;
	}
	else
	{
		tail->next = current;//将上一个用户信息结构体的next指针指向当前结构体
	}
	current->next = NULL;
	//将文件数据放入链表
	fgets(current->rate, length, file);
	fgets(current->destination, length, file); 
	fgets(current->departdate, length, file);
	fgets(current->duration, length, file);
	fgets(current->cost, length, file);
	return head;
}

void Print(struct Information* user, int n)//显示函数
{
	if (user == NULL || n == 0) printf("No List.\n");
	else
	{
		int sum = 0;
		while (user != NULL && sum < n)
		{
			printf("Name: %s", user->name);
			printf("Rate: %s", user->rate);
			printf("Destination: %s", user->destination);
			printf("Departuredate: %s", user->departdate);
			printf("Traveldays: %s", user->duration);
			printf("Amount: %s\n", user->cost);
			user = user->next;
			sum++;
		}
		Sleep(1000);
	}
}
void TempSave(struct Information* a, struct Information* b)//结构体信息交换函数
{
	struct Information* temp = (struct Information*)malloc(sizeof(struct Information));
	//将结构体a的数据复制到临时结构体temp中
	strcpy(temp->name, a->name);
	strcpy(temp->rate, a->rate);
	strcpy(temp->destination, a->destination);
	strcpy(temp->departdate, a->departdate);
	strcpy(temp->duration, a->duration);
	strcpy(temp->cost, a->cost);
	//将结构体b的数据复制到结构体a中
	strcpy(a->name, b->name);
	strcpy(a->rate, b->rate);
	strcpy(a->destination, b->destination);
	strcpy(a->departdate, b->departdate);
	strcpy(a->duration, b->duration);
	strcpy(a->cost, b->cost);
	//将临时结构体temp的数据复制到结构体b中
	strcpy(b->name, temp->name);
	strcpy(b->rate, temp->rate);
	strcpy(b->destination, temp->destination);
	strcpy(b->departdate, temp->departdate);
	strcpy(b->duration, temp->duration);
	strcpy(b->cost, temp->cost);
	free(temp);//释放temp
}
void RankSorting(struct Information* head)//排序函数1
{
	if (head == NULL) printf("No List.\n");
	else
	{
		struct Information* current1, *current2;
		current1 = NULL;
		current2 = NULL;
		//冒泡排序，不交换节点，交换节点中数据
		for (current1 = head; current1 != NULL; current1 = current1->next)
		{
			for (current2 = current1; current2 != NULL; current2 = current2->next)
			{
				if (Turn(current2->rate) > Turn(current1->rate))
				{
					TempSave(current2, current1);
				}
				if (Turn(current2->rate) == Turn(current1->rate))
				{
					if (Turn(current2->cost) > Turn(current1->cost))
					{
						TempSave(current2, current1);
					}
				}
			}
		}
	}
}
void AmountSorting(struct Information* head)//排序函数2
{
	if (head == NULL) printf("No List.\n");
	else
	{
		struct Information* current1, *current2;
		current1 = NULL;
		current2 = NULL;
		for (current1 = head; current1 != NULL; current1 = current1->next)
		{
			for (current2 = current1; current2->next != NULL; current2 = current2->next)
			{
				if (Turn(current2->cost) > Turn(current1->cost))
				{
					TempSave(current2, current1);
				}
				if (Turn(current2->cost) == Turn(current1->cost))
				{
					if (Turn(current2->rate) > Turn(current1->cost))
					{
						TempSave(current2, current1);
					}
				}
			}
		}
	}
	//Print(head,2147000000);
}

void OrderStatistics(struct Information* head)//用户信息统计函数
{
	if (head == NULL) printf("No List.\n");
	else
	{
		system("cls");
		printf("=========MENU1=========\n");
		int k = 1;
		for (int i = 0; i < 2; i ++)
		{
			printf("(%d)%s\n", k + i, Menu1[i]);
		} 
		int num;
		printf("Please Enter a Number(1 - 2)\n");
		scanf("%d", &num);
		getchar();
		switch (num)
		{
			case 1:
				RankSorting(head);//按等级排序功能
				break;
			case 2:
				AmountSorting(head);//按金额排序功能
				break;
		}
		Print(head,2147000000);
	}
}

void RateSearch(struct Information* head)//等级搜索函数
{
	if (head == NULL) printf("No List.\n");
	else
	{ 
		system("cls");
		struct Information* current1, *current2;
		current1 = (struct Information*)malloc(sizeof(struct Information));
		current2 = (struct Information*)malloc(sizeof(struct Information));
		printf("Please Enter a Rate.");
		int SearchRate;
		scanf("%d", &SearchRate);   
		getchar();//读取换行符
		int total = 0;
		RankSorting(head);//按等级排序
		for(current1 = head, current2 = head;current2 != NULL && current1 != NULL ; current2 = current2->next)//current1记录靠前位置，current2向下走，找到所需等级与current1换位，最后打印出前几位
		{
			if (Turn(current2->rate) == SearchRate)
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total记录所需打印个数
			}
		}
		Print(head, total);
	}
	
}

void DeparturedateAndRateSearch(struct Information* head)//出发日期及等级搜索函数
{
	if (head == NULL) printf("No List.\n");
	else 
	{
		system("cls");
		struct Information* current1, *current2;
		current1 = (struct Information*)malloc(sizeof(struct Information));
		current2 = (struct Information*)malloc(sizeof(struct Information));
		printf("Pleasa Enter a Departuredate. \n");
		char SearchDepartdate[length];
		Departuredate(SearchDepartdate);
		//getchar();
		printf("Please Enter a Rate. \n");
		int SearchRate;
		scanf("%d", &SearchRate);
		getchar();
		int total = 0;
		RankSorting(head);
		for(current1 = head, current2 = head;current2 != NULL && current1 != NULL; current2 = current2->next)
		{
			if (Turn(current2->rate) == SearchRate && Turn(current2->departdate) == Turn(SearchDepartdate))//current1记录靠前位置，current2向下走，找到所需等级及出发日期与current1换位，最后打印出前几位
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total记录所需打印个数
			}
		}
		Print(head, total);
	}
}

void NameSearch(struct Information* head)//姓名搜索函数
{
	if (head == NULL) printf("No List.\n");
	else
	{
		system("cls");
		struct Information* current1, *current2;
		current1 = (struct Information*)malloc(sizeof(struct Information));
		current2 = (struct Information*)malloc(sizeof(struct Information));
		printf("Please Enter a Username. \n");
		char Username[length];
		fgets(Username, length, stdin);
		int total = 0;
		for(current1 = head, current2 = head;current2 != NULL && current1 != NULL; current2 = current2->next)
		{
			if (strcmp(current2->name, Username) == 0)//比较
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total记录所需打印个数
			}
		}
		Print(head, total);
	}
}

void DestinationSearch(struct Information* head)//目的地搜索函数
{
	if (head == NULL) printf("No List.\n");
	else
	{
		system("cls");
		struct Information* current1, *current2;
		current1 = (struct Information*)malloc(sizeof(struct Information));
		current2 = (struct Information*)malloc(sizeof(struct Information));
		//printf("Please Enter a Destination. \n");
		char SearchDestination[length];
		strcpy(SearchDestination, CorrectCityName());
		int total = 0;
		AmountSorting(head);
		for(current1 = head, current2 = head;current2 != NULL && current1 != NULL; current2 = current2->next)
		{
			if (strcmp(current2->destination, SearchDestination) == 0)//比较
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total记录所需打印个数
			}
		}
		Print(head, total);
	}
}

void DeparturedateAndDestinationSearch(struct Information* head)//出发日期及目的地搜索
{
	if (head == NULL) printf("No List.\n");
	else
	{
		system("cls");
		struct Information* current1, *current2;
		current1 = (struct Information*)malloc(sizeof(struct Information));
		current2 = (struct Information*)malloc(sizeof(struct Information));
		printf("Please Enter a Departuredate. \n");
		char SearchDepartdate[length];
		Departuredate(SearchDepartdate);
		//getchar();
		printf("Please Enter a Destination. \n");
		char SearchDestination[length];
		strcpy(SearchDestination, CorrectCityName());
		int total = 0;
		RankSorting(head);//按等级排序
		for(current1 = head, current2 = head;current2 != NULL && current1 != NULL; current2 = current2->next)
		{
			if (strcmp(current2->destination, SearchDestination) == 0 && Turn(current2->departdate) == Turn(SearchDepartdate))//比较
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total记录所需打印个数
			}
		}
		Print(head, total);
	}
}
void OrderQuery(struct Information* head)//订单查询函数
{
	if (head == NULL) printf("No List.\n");
	else
	{
		system("cls");
		printf("=========MENU2=========\n");
		int k = 1;
		for (int i = 0; i < 5; i ++)
		{
			printf("(%d)%s\n", k + i, Menu2[i]);
		}
		int num;
		printf("Please Enter a Number(1 - 5)\n");
		scanf("%d", &num);
		getchar();
		switch (num)
		{
			case 1:
				RateSearch(head);//等级查找功能
				break;
			case 2:
				DeparturedateAndRateSearch(head);//出发日期及等级查找功能
				break;
			case 3:
				NameSearch(head);//姓名查找功能
				break;
			case 4:
				DestinationSearch(head);//目的地查找功能
				break;
			case 5:
				DeparturedateAndDestinationSearch(head);//出发日期及目的地查找功能
				break;

		}
	}
}

void WeatherQuery()
{
	system("cls");
	CorrectCityName();
	printf("Please Enter your Departuredate.  ");
	char tempdepartdate[length];
	Departuredate(tempdepartdate);
	printf(WEATHER);
	printf("\n");
	system("pause");
}

int Change()//菜单函数
{
	int re = 0;
	int num = 0;
	printf("Please Enter a Numeber(1 - 6)\n");
	scanf("%d", &num);
	getchar();
	switch (num)
	{
		case 1:
			head = OrderEntry();//订单录入功能
			Savedata(head);
			break;
		//case 2:
			//Print(head,2147000000);
			//break;
		case 2:
			OrderStatistics(head);//订单统计功能
			Savedata(head);
			printf("Task Comnpleted.\n"); 
			system("pause");
			break;
		case 3:
			OrderQuery(head);//订单搜索功能
			system("pause");
			break;
		case 4:
			DestinationTimeGeneration();//目的地时间转换功能
			system("pause");
			break;
		case 5:
			WeatherQuery();//生成目的地天气功能
			break;
		case 6:
			printf("Corresponding Reminders have been sent to the User.\n");//已为用户发送相应提醒
			system("pause");
			break;
		case 7://退出
			re = 1;
			break;
	}
	return re;
}
int main()
{
	CitySave();
	/*for (int i = 0; i < 78707; i ++)
	{
		printf("%s ", Allcity[i].cityname);
		printf("%f", Allcity[i].citylongitude);
		printf("\n"); 
	}*/
	//system("pause");
	/*char b[1000] = "20241331";
	int a = Turn(b) / 100 % 100;
	printf("%d", a);*/
	FILE* file = fopen("data.txt", "r");
	if(file!=NULL)
	{
		int total;
		fscanf(file,"%d\n",&total);
		for(int i = 0; i < total; i++)  FileOrderEntry(file);
	}
	fclose(file);
	while (1)
	{
		system("cls");
		Show();
		if(Change()) break;
	}
    system("pause");
}