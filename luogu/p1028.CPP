//https://www.luogu.com.cn/problem/P1028
#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans = 0;
int dp[1005];
int sum(int n)
{
    if(dp[n] != 0) return dp[n];

    int num = 0;
    for (int i = n / 2; i >= 1; i --)
    {
        num += sum(i);
    }
    dp[n] = num + 1;
    return num + 1;

}
signed main() 
{
    int n;
    cin >> n;
    //int ret = sum(n);
    ans = sum(n);
    cout << ans << '\n';
    system("pause");
    return 0;
}