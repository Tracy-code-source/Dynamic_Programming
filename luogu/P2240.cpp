//https://www.luogu.com.cn/problem/P2240
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, T;
double ans;
struct D
{
    int m;
    int v;
    double avg;
}gold[105];
bool cmp(struct D a, struct D b)
{
    return a.v * b.m > b.v * a.m;
}
signed main()
{
    cin >> N >> T;
    for (int i = 1; i <= N; i ++)
    {
        cin >> gold[i].m >> gold[i].v;
        gold[i].avg = gold[i].v * 1.0 / (gold[i].m * 1.0);
    }
    sort(gold + 1, gold + 1 + N, cmp);
    for (int i = 1; i <= N; i ++)
    {
        if (T >= gold[i].m)
        {
            ans += gold[i].v;
            T -= gold[i].m;
        }
        else 
        {
            ans += (T * gold[i].avg * 1.0);
            break;
        }
    }
    //for (int i = 1; i <= N; i ++) cout << gold[i].m << ' ' << gold[i].v << gold[i].avg << '\n';
    printf("%.2lf\n", ans);
    system("pause");
    return 0;
}