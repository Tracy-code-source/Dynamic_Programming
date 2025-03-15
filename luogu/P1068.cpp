//https://www.luogu.com.cn/problem/P1068
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int realnum = 0;
struct Student
{
    int num;
    int score;
}com[5005];
bool cmp(struct Student a, struct Student b)
{
    if (a.score == b.score) return a.num < b.num;
    else return a.score > b.score;
    
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> com[i].num >> com[i].score;
    }
    sort(com + 1, com + n + 1, cmp);
    int min = floor(m * 1.5);
    int minscore = com[min].score;
    for (int i = 1; i <= n; i ++)
    {
        if (com[i].score >= minscore) realnum ++;
    }
    cout << minscore << ' ' << realnum << '\n';
    for (int i = 1; i <= realnum; i ++)
    {
        cout << com[i].num << ' ' << com[i].score << '\n';
    }
    system("pause");
    return 0;
}