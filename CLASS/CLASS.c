#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define length 1000
#define WEATHER "Rainy  26 degrees Celsius  78.8 degrees Fahrenheit"
struct Information* head = NULL;
int Turn(char* str)//�����ַ���ת���κ���
{
	while (*str == ' ') str++;//����ǰ��ո�
	int result = 0;
	while (*str >= '0' && *str <= '9')//��ÿ���ַ�ת��Ϊint
	{
		int data = *str - '0';
		result = result * 10 + data;
		str++;
	}
	return result;
} 
struct Information//�û���Ϣ�ṹ��
{
	char name[length];
	char rate[length];
	char destination[length];
	char departdate[length];
	char duration[length];
	char cost[length];
	struct Information* next;
};
struct City//������Ϣ�ṹ��
{
	char cityname[length];
	char cityweather[length];
	float citylongitude;
}Allcity[78710];//������Ϣ�ṹ������
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

int KMP(char* str1,char *str2)//���ٲ���
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

int Leapyear(int year)//�ж�����
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

char Menu[7][length] =//���˵�
{
	"Order Entry",
	"Order Statistics",
	"Order Query",
	"Destination Time",
	"Destination Weather",
	"Travel Depareture Reminder",
	"Close Menu"
};
char Menu1[2][length] =//�Ӳ˵�1
{
	"Sort by User Level",
	"Sort by Order Amount Size"
};
char Menu2[5][length] =//�Ӳ˵�2
{
	"Enter user Rate.",
	"Enter user Departuredate and Rate.",
	"Enter user Name",
	"Enter Destination",
	"Enter Departuredate and Destination"
};

void Show()//��ӡ�˵�
{
	int k = 1;
	printf("=========MENU=========\n");
		for (int i = 0; i < 7; i++)
		{
			printf("(%d)%s\n", k + i, Menu[i]);
		}
}
void Savedata(struct Information* head)//�����ļ����溯��
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
		
			fprintf(file, "%s%s%s%s%s%s", current->name, current->rate, current->destination, current->departdate, current->duration, current->cost);//������������д���ļ�
			current = current->next;
		}
		fclose(file);
	}
}  
char* Name(char* username)//�����û�������
{
	fgets(username, length, stdin);
	while (username == NULL || username[0] == '\n')
	{
		memset(username, '\0', sizeof(username));
		printf("Please Enter in the Correct Form.  ");//�������뱨��
		scanf("%s", username);
	}
	return username;
}
void Rate(char* rate)//�����û��ȼ�����
{
	fgets(rate, length, stdin);
	while (rate[0] == '\n'|| Turn(rate) > 4 || Turn(rate) < 1)//�ĸ��ȼ�
	{
		memset(rate, '\0', sizeof(rate));
		printf("Please Enter in the Correct Form.  ");
		fgets(rate, length, stdin);
	}
}
/*void Destination(char* destination)//�����û�Ŀ�ĵغ���
{
	fgets(destination,length, stdin);
	while ( destination[0] == '\n')
	{
		printf("Please Enter in the Correct Form.  ");
		fgets(destination, length, stdin);
	}
}*/

char* CorrectCityName()//�����û�Ŀ�ĵغ���
{
	while (1)
	{
		char cdestination[length];
		printf("Please Enter your Destination: ");
		char tempdestination[length];
		fgets(tempdestination, length, stdin);
		//system("cls");
		static char May[70000][length];//��ſ���ΪĿ�ĵص�����
		int num = 0;
		for (int i = 0; i<78707; i ++)
		{
			if (KMP(tempdestination, Allcity[i].cityname) == 1)//KMP���ٲ���
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
			printf("%s\n", May[i]);//�����ӡ
		}
	}
}
void DestinationTimeGeneration()//Ŀ�ĵ�ʱ�����ɺ���
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
		//ʱ������
		time_t timep;
    	struct tm *p;
		time(&timep);
		p = gmtime(&timep);
		int hour = p->tm_hour;
		int minute = p->tm_min;
		int second = p->tm_sec;
		//�����ж�ʱ���Ӽ�
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
void Departuredate(char* departdate)//�����û��������ں���
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
				if ((Turn(departdate) / 100 % 100) > 12 || (Turn(departdate) / 100 % 100) < 1) //�³�������13��0��
				{
					n = 0;
					printf("Please Enter in the Correct Form. ");
					continue;
					//system("pause");
				}
				if ((Turn(departdate) /100 % 100) == 1 || (Turn(departdate) /100 % 100) == 3 || (Turn(departdate) /100 % 100) == 5 || (Turn(departdate) /100 % 100) == 7 || (Turn(departdate) /100 % 100) == 8 || (Turn(departdate) /100 % 100) == 10 || (Turn(departdate) /100 % 100) == 12)
				{
					if (Turn(departdate) % 100 > 31 || Turn(departdate) % 100 < 1) //�ճ�����
					{
						n = 0;
						printf("Please Enter in the Correct Form. ");
						continue;
						//system("pause");
					}
				}
				if ((Turn(departdate) /100 % 100) == 2)
				{
					if ((Turn(departdate) % 100) > 29 || ((Turn(departdate) % 100) < 1))//��������
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
		if (n == 1) return ;//ֱ��������ȷ����
	}
}
void Duration(char* duration)//�����û�������������
{
	fgets(duration, length, stdin);
	while (duration[0] == '\n')
	{
		memset(duration, '\0', sizeof(duration));
		printf("Please Enter in the Correct Form.  ");
		fgets(duration, length, stdin);
	}
}
void Cost(char* cost)//�����û���������
{
	fgets(cost, length, stdin);
	while (cost == NULL || cost[0] == '\n')
	{
		memset(cost, '\0', length);
		printf("Please Enter in the Correct Form.  ");
		fgets(cost, length, stdin);
	}
}
struct Information* OrderEntry()//�û���Ϣ¼�뺯��
{
	struct Information* current, *tail;
	tail = head;
	while(tail != NULL && tail->next != NULL)  tail = tail->next;//ÿ���һ���ڵ㣬�������������һλ

	current = (struct Information*)malloc(sizeof(struct Information));
	if (head == NULL)
	{
		head = current;
	}
	else
	{
		tail->next = current;//����һ���û���Ϣ�ṹ���nextָ��ָ��ǰ�ṹ��
	}
	current->next = NULL;
	//������ǰ����
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
struct Information* FileOrderEntry(FILE *file)//���ļ��ж�ȡ�û���Ϣ����
{
	struct Information* current, *tail;
	tail = head;
	while(tail != NULL && tail->next != NULL)  tail = tail->next;//ÿ���һ���ڵ㣬�������������һλ
	char username[length], userdestination[length];
	current = (struct Information*)malloc(sizeof(struct Information));
	fgets(current->name, length, file);
	
	if (head == NULL)
	{
		head = current;
	}
	else
	{
		tail->next = current;//����һ���û���Ϣ�ṹ���nextָ��ָ��ǰ�ṹ��
	}
	current->next = NULL;
	//���ļ����ݷ�������
	fgets(current->rate, length, file);
	fgets(current->destination, length, file); 
	fgets(current->departdate, length, file);
	fgets(current->duration, length, file);
	fgets(current->cost, length, file);
	return head;
}

void Print(struct Information* user, int n)//��ʾ����
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
void TempSave(struct Information* a, struct Information* b)//�ṹ����Ϣ��������
{
	struct Information* temp = (struct Information*)malloc(sizeof(struct Information));
	//���ṹ��a�����ݸ��Ƶ���ʱ�ṹ��temp��
	strcpy(temp->name, a->name);
	strcpy(temp->rate, a->rate);
	strcpy(temp->destination, a->destination);
	strcpy(temp->departdate, a->departdate);
	strcpy(temp->duration, a->duration);
	strcpy(temp->cost, a->cost);
	//���ṹ��b�����ݸ��Ƶ��ṹ��a��
	strcpy(a->name, b->name);
	strcpy(a->rate, b->rate);
	strcpy(a->destination, b->destination);
	strcpy(a->departdate, b->departdate);
	strcpy(a->duration, b->duration);
	strcpy(a->cost, b->cost);
	//����ʱ�ṹ��temp�����ݸ��Ƶ��ṹ��b��
	strcpy(b->name, temp->name);
	strcpy(b->rate, temp->rate);
	strcpy(b->destination, temp->destination);
	strcpy(b->departdate, temp->departdate);
	strcpy(b->duration, temp->duration);
	strcpy(b->cost, temp->cost);
	free(temp);//�ͷ�temp
}
void RankSorting(struct Information* head)//������1
{
	if (head == NULL) printf("No List.\n");
	else
	{
		struct Information* current1, *current2;
		current1 = NULL;
		current2 = NULL;
		//ð�����򣬲������ڵ㣬�����ڵ�������
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
void AmountSorting(struct Information* head)//������2
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

void OrderStatistics(struct Information* head)//�û���Ϣͳ�ƺ���
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
				RankSorting(head);//���ȼ�������
				break;
			case 2:
				AmountSorting(head);//�����������
				break;
		}
		Print(head,2147000000);
	}
}

void RateSearch(struct Information* head)//�ȼ���������
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
		getchar();//��ȡ���з�
		int total = 0;
		RankSorting(head);//���ȼ�����
		for(current1 = head, current2 = head;current2 != NULL && current1 != NULL ; current2 = current2->next)//current1��¼��ǰλ�ã�current2�����ߣ��ҵ�����ȼ���current1��λ������ӡ��ǰ��λ
		{
			if (Turn(current2->rate) == SearchRate)
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total��¼�����ӡ����
			}
		}
		Print(head, total);
	}
	
}

void DeparturedateAndRateSearch(struct Information* head)//�������ڼ��ȼ���������
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
			if (Turn(current2->rate) == SearchRate && Turn(current2->departdate) == Turn(SearchDepartdate))//current1��¼��ǰλ�ã�current2�����ߣ��ҵ�����ȼ�������������current1��λ������ӡ��ǰ��λ
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total��¼�����ӡ����
			}
		}
		Print(head, total);
	}
}

void NameSearch(struct Information* head)//������������
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
			if (strcmp(current2->name, Username) == 0)//�Ƚ�
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total��¼�����ӡ����
			}
		}
		Print(head, total);
	}
}

void DestinationSearch(struct Information* head)//Ŀ�ĵ���������
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
			if (strcmp(current2->destination, SearchDestination) == 0)//�Ƚ�
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total��¼�����ӡ����
			}
		}
		Print(head, total);
	}
}

void DeparturedateAndDestinationSearch(struct Information* head)//�������ڼ�Ŀ�ĵ�����
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
		RankSorting(head);//���ȼ�����
		for(current1 = head, current2 = head;current2 != NULL && current1 != NULL; current2 = current2->next)
		{
			if (strcmp(current2->destination, SearchDestination) == 0 && Turn(current2->departdate) == Turn(SearchDepartdate))//�Ƚ�
			{
				TempSave(current1, current2);
				current1 = current1->next;
				total++;//total��¼�����ӡ����
			}
		}
		Print(head, total);
	}
}
void OrderQuery(struct Information* head)//������ѯ����
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
				RateSearch(head);//�ȼ����ҹ���
				break;
			case 2:
				DeparturedateAndRateSearch(head);//�������ڼ��ȼ����ҹ���
				break;
			case 3:
				NameSearch(head);//�������ҹ���
				break;
			case 4:
				DestinationSearch(head);//Ŀ�ĵز��ҹ���
				break;
			case 5:
				DeparturedateAndDestinationSearch(head);//�������ڼ�Ŀ�ĵز��ҹ���
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

int Change()//�˵�����
{
	int re = 0;
	int num = 0;
	printf("Please Enter a Numeber(1 - 6)\n");
	scanf("%d", &num);
	getchar();
	switch (num)
	{
		case 1:
			head = OrderEntry();//����¼�빦��
			Savedata(head);
			break;
		//case 2:
			//Print(head,2147000000);
			//break;
		case 2:
			OrderStatistics(head);//����ͳ�ƹ���
			Savedata(head);
			printf("Task Comnpleted.\n"); 
			system("pause");
			break;
		case 3:
			OrderQuery(head);//������������
			system("pause");
			break;
		case 4:
			DestinationTimeGeneration();//Ŀ�ĵ�ʱ��ת������
			system("pause");
			break;
		case 5:
			WeatherQuery();//����Ŀ�ĵ���������
			break;
		case 6:
			printf("Corresponding Reminders have been sent to the User.\n");//��Ϊ�û�������Ӧ����
			system("pause");
			break;
		case 7://�˳�
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