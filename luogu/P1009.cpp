//https://www.luogu.com.cn/problem/P1009
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, k;
int a[105], b[105];
string num;
signed main()
{
    cin >> n;
    a[0] = 1;
    for (int x = 1; x <= n; x ++)
    {
        for (int i = 1; i <= x; i ++)
        {
            for (int j = 0; j < 100; j ++) a[j] *= i;
            for (int k = 0; k < 100; k ++)
            {
                if (a[k] >= 10)
                {
                    a[k + 1] += a[k] / 10;
                    a[k] %= 10;
                }
            }
        }
        for (int i = 0; i < 100; i ++)
        {
            b[i] += a[i];
            if (b[i] >= 10)
            {
                b[i + 1] += 1;
                b[i] -= 10;
            }
            a[i] = 0;
        }
        a[0] = 1;
    }
    for (int i = 100; i >= 0; i --)
    {
        if (b[i] == 0 && k == 0) continue;
        k = 1;
        cout << b[i];
    }
    cout << '\n';
    system("pause");
    return 0;
}
