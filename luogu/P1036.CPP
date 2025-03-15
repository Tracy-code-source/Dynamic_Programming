////https://www.luogu.com.cn/problem/P1036
#include <bits/stdc++.h>
using namespace std;
#define int long long
int ret[100005];
int ans;
int n, k;
int prime(int n)
{
    int t = 1;
    for (int i = 2; i <= n; i ++)
    {
        if (n % i == 0 && i != n)
        {
            t = 0;
            break;
        }
    }
    if (t == 1) return 1;
    else return 0;
}
void dfs(int i, int num, int sum)
{
    if (num == k)
    {
        if (prime(sum) != 0) ans ++;
    }
    else if (i < n)
    {
        dfs(i + 1, num, sum);
        dfs(i + 1, num + 1, sum + ret[i]);
    }
}
signed main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
    {
        cin >> ret[i];
    }
    dfs(0, 0, 0);
    cout << ans << '\n';
    system("pause");
    return 0;
}