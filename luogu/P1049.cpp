//https://www.luogu.com.cn/problem/P1049
#include <bits/stdc++.h>
using namespace std;
#define int long long
int V, n;
int item[35];
int dp[20005];
int ans;
void Dynamic_Programming()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = V; j > 0; j --)
        {
            if (j >= item[i]) dp[j] = max(dp[j - item[i]] + item[i], dp[j]);
        }
    }
}
signed main()
{
    cin >> V;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> item[i];
    Dynamic_Programming();
    ans = V - dp[V];
    cout << ans << '\n';
    system("pause");
    return 0;
}
