//https://www.luogu.com.cn/problem/P1093
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct In
{
    int cn;
    int math;
    int Eng;
    int sum;
    int ID;
}student[305];
int n;
bool cmp(struct In a, struct In b)
{
    if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.cn != b.cn) return a.cn > b.cn;
    else return a.ID < b.ID;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> student[i].cn >> student[i].math >> student[i].Eng;
        student[i].sum = student[i].cn + student[i].math + student[i].Eng;
        student[i].ID = i;
    }
    sort(student + 1, student + 1 + n, cmp);
    for (int i = 1; i <= 5; i ++)
    {
        cout << student[i].ID << ' ' << student[i].sum << '\n';
    }
    system("pause");
    return 0;
}