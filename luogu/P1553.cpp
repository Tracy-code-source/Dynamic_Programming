//https://www.luogu.com.cn/problem/P1553
#include <bits/stdc++.h>
#include <format>
using namespace std;
int Turn(string str)
{
	int result = 0;
    int i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		int data = str[i] - '0';
		result = result * 10 + data;
		i ++;
	}
	return result;
}
int num(int n)
{
    int ret = 0;
    while (n > 0)
    {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}
int main()
{
    string str;
    getline(cin, str);
    int t = 1;
    for (int i = 0; i < str.size(); i ++)
    {
        if (str[i] == '.') t = 2;
        if (str[i] == '/') t = 3;
        if (str[i] == '%') t = 4;
    }
    if (t == 1)
    {
        int j = 0;
        string temp;
        for (int i = str.size() - 1; i >= 0; i --)
        {
            if (str[i] == '0') str[i] = '\0';
            else break;
        }
        for (int i = str.size() - 1; i >= 0; i --)
        {
            temp += str[i];
        }
        cout << temp << '\n';
    }
    if (t == 2)
    {
        int k = 1;
        string str1;
        string str2;
        for (int i = 0; i < str.size(); i ++)
        {
            if (str[i] == '.')
            {
                k = 0;
                continue;
            }
            if (k == 1)
            {
                str1 += str[i];
            }
            if (k == 0)
            {
                str2 += str[i];
            }
        }
        string temp1, temp2;
        for (int i = str1.size() - 1; i >= 0; i --)
        {
            if (str1[i] == '0') str1[i] = '\0';
            else break;
        }
        for (int i = str2.size() - 1; i >= 0; i --)
        {
            if (str2[i] == '0') str2[i] = '\0';
        }
        for (int i = str1.size() - 1; i >= 0; i--)
        {
            temp1 += str1[i];
        }
        for (int i = str2.size() - 1; i >= 0; i--)
        {
            temp2 += str2[i];
        }
        cout << temp1 + '.' + temp2 << '\n';
    }
    if (t == 3)
    {
        int k = 1;
        string str1;
        string str2;
        for (int i = 0; i < str.size(); i ++)
        {
            if (str[i] == '/')
            {
                k = 0;
                continue;
            }
            if (k == 1)
            {
                str1 += str[i];
            }
            if (k == 0)
            {
                str2 += str[i];
            }
        }
         string temp1, temp2;
        for (int i = str1.size() - 1; i >= 0; i --)
        {
            if (str1[i] == '0') str1[i] = '\0';
            else break;
        }
        for (int i = str2.size() - 1; i >= 0; i --)
        {
            if (str2[i] == '0') str2[i] = '\0';
        }
        for (int i = str1.size() - 1; i >= 0; i--)
        {
            temp1 += str1[i];
        }
        for (int i = str2.size() - 1; i >= 0; i--)
        {
            temp2 += str2[i];
        }
        cout << temp1 + '/' + temp2 << '\n';
    }
    if (t == 4)
    {
        string temp;
        int j = 0;
        for (int i = str.size() - 2; i >= 0; i --)
        {
            if (str[i] == '0') str[i] = '\0';
            else break;
        }
        for (int i = str.size() - 2; i >= 0; i --)
        {
            temp += str[i];
        }
        cout << temp + '%' << '\n';
    }
    system("pause");
}