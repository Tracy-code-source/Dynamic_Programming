//https://www.luogu.com.cn/problem/P1303
#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b;
int ai[10000], bi[10000], ci[20000];
int loc;
signed main()
{
    cin >> a >> b;
    for (int i = 0; i < a.size(); i ++) ai[a.size() - 1 - i] = a[i] - '0';
    for (int i = 0; i < b.size(); i ++) bi[b.size() - 1 - i] = b[i] - '0';
    for (int i = 0; i < b.size(); i ++)
    {
        for (int j = 0; j < a.size(); j ++)
        {
            ci[i + j] += ai[j] * bi[i];
            if (ci[i + j] >= 10)
            {
                ci[i + j + 1] += ci[i + j] / 10;
                ci[i + j] %= 10;
            }
        }
    }
    for (int i = a.size() + b.size() - 1; i >= 0; i --)
    {
        if (ci[i] != 0)
        {
            loc = i;
            break;
        }
    }
    for (int i = loc; i >= 0; i --) cout << ci[i];
    cout << '\n';
    system("pause");
    return 0;
}