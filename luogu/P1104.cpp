//https://www.luogu.com.cn/problem/P1104
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct In
{
    string name;
    int year;
    int month;
    int day;
    int num;
}student[105];
bool cmp(struct In a, struct In b)
{
    if (a.year != b.year) return a.year < b.year;
    else if (a.month != b.month) return a.month < b.month;
    else if (a.day != b.day) return a.day < b.day;
    else return a.num > b.num;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> student[i].name >> student[i].year >> student[i].month >> student[i].day;
        student[i].num = i;
    }
    sort(student + 1, student + 1 + n, cmp);
    for (int i = 1; i <= n; i ++) cout << student[i].name << '\n';
    system("pause");
    return 0;
}