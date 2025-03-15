//https://www.luogu.com.cn/problem/P3156
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n ,m;
int num[2000005];
int findd[1000005];
int ans[1000005];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> num[i];
    for (int i = 1; i <= m; i ++) cin >> findd[i];
    for (int i = 1; i <= m; i ++)
    {
        ans[i] = num[findd[i]];
    }
    for (int i = 1; i <= m; i ++)
    {
        cout << ans[i] << '\n';
    }
    system("pause");
    return 0;
}