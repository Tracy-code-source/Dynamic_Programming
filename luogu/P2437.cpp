//https://www.luogu.com.cn/problem/P2437
#include <bits/stdc++.h>
using namespace std;
#define int long long
int m, n, len = 1;//开始时位数为1
int num[1005][1005];//一维表示第几个数，二维存高精度数
void high_prec(int n)
{
    for (int i = 1; i <= len; i ++) num[n][i] = num[n - 1][i] + num[n - 2][i];
    for (int i = 1; i <= len; i ++)
    {
        if (num[n][i] > 9)
        {
            num[n][i + 1] += num[n][i] / 10;
            num[n][i] %= 10;
        }
    }
    if (num[n][len + 1] != 0) len ++;
}
signed main()
{
    cin >> m >> n;
    num[1][1] = 1, num[2][1] = 2;
    for (int i = 3; i <= n - m; i ++) high_prec(i);
    for (int i = len; i > 0; i --) cout << num[n - m][i];
    cout << '\n';
    system("pause");
    return 0;
}