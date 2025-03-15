//https://www.luogu.com.cn/problem/P2010
#include <bits/stdc++.h>
using namespace std;
int leap(int n)
{
    int t = 0;
    if (n % 4 == 0 && n % 100 != 0)   t ++;
    if (n % 100 == 0 && n % 400 == 0) t ++;
    if (t > 0) return 1;
    else return 0;
    
}
long long correct(int n)
{
    if (leap(n / 10000) == 1)
    {
        int month = n % 10000 / 100;
        if (month == 0 || month > 12) return 0;
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            int day = n % 100;
            if (day == 0 || day > 31) return 0;
        }
        else if (month == 2)
        {
            int day = n % 100;
            if (day == 0 || day > 29) return 0;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            int day = n % 100;
            if (day == 0 || day > 30) return 0;
        } 
    }
    else 
    {
        int month = n % 10000 / 100;
        if (month == 0 || month > 12) return 0;
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            int day = n % 100;
            if (day == 0 || day > 31) return 0;
        }
        else if (month == 2)
        {
            int day = n % 100;
            if (day == 0 || day > 28) return 0;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            int day = n % 100;
            if (day == 0 || day > 30) return 0;
        }
    }
    return 1;
}
long long turn(int n)
{
    long long ret = 0;
    while (n > 0)
    {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}
int main()
{
    long long begin, end;
    cin>> begin >> end;
    int n = 0;
    for (int i = begin; i <= end; i ++)
    {
        if (correct(i) != 0)
        {
            if (i == turn(i)) n ++;
        }
    }
    cout << n << '\n';
    system("pause");
    return 0;
}