//https://www.luogu.com.cn/problem/P1255
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, len = 1;
int fl[5005][3000];
void high_prec(int n)
{
    for (int i = 1; i <= len; i ++) fl[n][i] = fl[n - 1][i] + fl[n - 2][i];
    for (int i = 1; i <= len; i ++)
    {
        if (fl[n][i] > 9)
        {
            fl[n][i + 1] += fl[n][i] / 10;
            fl[n][i] %= 10;
            if (fl[n][len + 1] != 0) len ++;
        }
    }
}
signed main()
{
    cin >> N;
    fl[1][1] = 1, fl[2][1] = 2;
    for (int i = 3; i <= N; i ++) high_prec(i);
    for (int i = len; i > 0; i --) cout << fl[N][i];
    cout << '\n';
    system("pause");
    return 0;
}