//https://www.luogu.com.cn/problem/P1786
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct In
{
    string name;
    string job;
    int jobrate;
    int dev;
    int rate;
    int ID;
}member[115];
bool cmp(struct In a, struct In b)
{
    if (a.dev != b.dev) return a.dev > b.dev;
    else return a.ID < b.ID;
}
bool cmp1(struct In a, struct In b)
{
    if (a.jobrate != b.jobrate) return a.jobrate > b.jobrate;
    else if (a.rate != b. rate) return a.rate > b.rate;
    else return a.ID < b.ID;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> member[i].name >> member[i].job >> member[i].dev >> member[i].rate;
        member[i].ID = i;
        if (member[i].job == "BangZhu") member[i].jobrate = 7;
        if (member[i].job == "FuBangZhu") member[i].jobrate = 6;
        if (member[i].job == "HuFa") member[i].jobrate = 5;
        if (member[i].job == "ZhangLao") member[i].jobrate = 4;
        if (member[i].job == "TangZhu") member[i].jobrate = 3;
        if (member[i].job == "JingYing") member[i].jobrate = 2;
        if (member[i].job == "BangZhong") member[i].jobrate = 1;
    }
    if (n == 3)
    {
        for (int i = 1; i <= 3; i ++)
        {
            cout << member[i].name << ' ' << member[i].job << ' ' << member[i].rate << '\n';
        }
    }
    else 
    {
        for (int i = 1; i <= 3; i ++)
        {
            cout << member[i].name << ' ' << member[i].job << ' ' << member[i].rate << '\n';
        }
        sort(member + 4, member + n + 1, cmp);
        int num1 = 2, num2 = 4, num3 = 7, num4 = 25;
        for (int i = 4; i <= n; i ++)
        {
            if (num1 != 0) member[i].job = "HuFa", num1 --;
            else if (num2 != 0) member[i].job = "ZhangLao", num2 --;
            else if (num3 != 0) member[i].job = "TangZhu", num3 --;
            else if (num4 != 0) member[i].job = "JingYing", num4 --;
            else member[i].job = "BangZhong";
            if (member[i].job == "BangZhu") member[i].jobrate = 7;
            if (member[i].job == "FuBangZhu") member[i].jobrate = 6;
            if (member[i].job == "HuFa") member[i].jobrate = 5;
            if (member[i].job == "ZhangLao") member[i].jobrate = 4;
            if (member[i].job == "TangZhu") member[i].jobrate = 3;
            if (member[i].job == "JingYing") member[i].jobrate = 2;
            if (member[i].job == "BangZhong") member[i].jobrate = 1;
        }
        sort(member + 4, member + n + 1, cmp1);
        for (int i = 4; i <= n; i ++)
        {
            cout << member[i].name << ' ' << member[i].job << ' ' << member[i].rate << '\n';
        }
    }
    system("pause");
    return 0;
}