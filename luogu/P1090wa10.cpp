//https://www.luogu.com.cn/problem/P1090
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int f[10005];
int ans;
bool compare(int a, int b)
{
    return a < b;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> f[i];
    sort(f + 1, f + 1 + n, compare);
    for (int i = 1; i < n; i ++)
    {
        f[i + 1] += f[i];
        ans += f[i + 1];
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}