//https://www.luogu.com.cn/problem/P1223
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
double sum;
struct D
{
    int t;
    int ID;
}member[1005];
int tt[1005];
bool cmp(struct D a, struct D b)
{
    return a.t < b.t;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> member[i].t;
        member[i].ID = i;
    }
    sort(member + 1, member + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
    {
        cout << member[i].ID << ' ';
        tt[i] = tt[i - 1] + member[i].t;
    }
    cout << '\n';
    for (int i = 0; i < n; i ++) sum += tt[i];
    printf("%.2lf\n", sum / n);
    system("pause");
    return 0;
}