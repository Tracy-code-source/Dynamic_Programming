//https://www.luogu.com.cn/problem/P4994
#include <bits/stdc++.h>
using namespace std;
#define int long long
int M;
int dp[10000005];
int fib (int n)
{
    if (dp[n] != 0) return dp[n];
    if (n > 1) dp[n] = (fib(n - 1) + fib(n - 2))%   M;
    return dp[n];
}
signed main()
{
    dp[0] = 0;
    dp[1] = 1;
    cin >> M;


    for(int i = 2;i<10000005;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%M;
    }
    int k;
    for (int i = 1;i<10000005; i ++)
    {
        if (dp[i] % M == 0 && dp[i + 1] % M == 1)
        {
            k = i;
            break;
        }
    }
    cout << k << '\n';
    system("pause");
    return 0;
}