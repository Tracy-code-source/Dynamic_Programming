//https://www.luogu.com.cn/problem/P1464
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[30][30][30];
int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) 
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) 
    {
        dp[20][20][20] = w(20, 20, 20);
        return w(20, 20, 20);
    }
    if (dp[a][b][c] != 0) return dp[a][b][c];
    if (a < b && b < c) 
    {
        dp[a][b][c] = w(a , b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return w(a , b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else 
    {
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);;
        return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}
signed main()
{
    int a, b, c;
    cin >> a >> b >> c;
    while (a != - 1 || b != - 1 || c != -1)
    {
        printf("w(%lld, %lld, %lld) = %d\n", a, b, c, w(a, b,c));
        cin >> a >> b >> c;
    }
    system("pause");
    return 0;
}