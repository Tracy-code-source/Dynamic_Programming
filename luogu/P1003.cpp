//https://www.luogu.com.cn/problem/P1003
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, ret;
int xi, yi;
int xs[10005], ys[10005], xl[10005], yl[10005];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> xs[i] >> ys[i] >> xl[i] >> yl[i];
    }
    cin >> xi >> yi;
    for (int i = 1; i <= n; i ++)
    {
        if (xi >= xs[i] && xi <= xs[i] + xl[i] && yi >= ys[i] && yi <= ys[i] + yl[i]) ret = i;
    }
    if (ret != 0) cout << ret << '\n';
    else cout << "-1" << '\n';
    system("pause");
    return 0;
}