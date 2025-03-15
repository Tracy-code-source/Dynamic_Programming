//https://www.luogu.com.cn/problem/P8218
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[100005];
int m;
struct lar
{
    int l, r;
}LAR[100005];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i ++) cin >> LAR[i].l >> LAR[i].r;
    for (int i = 1; i <= n; i ++)
    {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i ++)
    {
        cout << a[LAR[i].r] - a[LAR[i].l - 1] << '\n';
    }
    system("pause");
    return 0;
 }