//https://www.luogu.com.cn/problem/P1051
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, total;
struct In
{
    string name;
    int avg;
    int judge;
    char YON;
    char west;
    int num;
    int sum;
    int ID;
}student[105];
int add(struct In p)
{
    int bonus = 0;
    if (p.avg > 80 && p.num >= 1) bonus += 8000;
    if (p.avg > 85 && p.judge > 80) bonus += 4000;
    if (p.avg > 90) bonus += 2000;
    if (p.avg > 85 && p.west == 'Y') bonus += 1000;
    if (p.judge > 80 && p.YON == 'Y') bonus += 850;
    return bonus;
}
bool cmp(struct In a, struct In b)
{
    if (a.sum != b.sum) return a.sum > b.sum;
    else return a.ID < b.ID;
}
signed main()
{
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        cin >> student[i].name >> student[i].avg >> student[i].judge >> student[i].YON >> student[i].west >> student[i].num;
        student[i].sum = add(student[i]);
        student[i].ID = i;
    }
    sort(student, student + N, cmp);
    cout << student[0].name << '\n' << student[0].sum << '\n';
    for (int i = 0; i < N; i ++)
    {
        total += student[i].sum;
    }
    cout << total << '\n';
    system("pause");
    return 0;
}