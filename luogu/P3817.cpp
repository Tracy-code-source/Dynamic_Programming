//https://www.luogu.com.cn/problem/P3817
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x;
int candy[1000005];
int ans;
signed main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i ++) cin >> candy[i];
    for (int i = 2; i <= n; i ++)
    {
        if (candy[i - 1] + candy[i] > x)
        {
            
        }

    }
}