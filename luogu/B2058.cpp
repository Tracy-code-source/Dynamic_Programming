//https://www.luogu.com.cn/problem/B2058
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int m[105][5];
int total;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= 3; j ++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= 3; i ++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j ++)
        {
            ans += m[j][i];
        }
        cout << ans << ' ';
        total += ans;
    }
    cout << total << '\n';
    system("pause");
    return 0;
}
