//https://www.luogu.com.cn/problem/P2089
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, num;
struct solve
{
    int i, j, k, t, a, b, c, d, e, f;
}sum[50005];
signed main()
{
    cin >> n;
    for (int i = 1; i <= 3; i ++)
    {
        for (int j = 1; j <= 3; j ++)
        {
            for (int k = 1; k <= 3; k ++)
            {
                for (int t = 1; t <= 3; t ++)
                {
                    for (int a = 1; a <= 3; a ++)
                    {
                        for (int b = 1; b <= 3; b ++)
                        {
                            for (int c = 1; c <= 3; c ++)
                            {
                                for (int d = 1; d <= 3; d ++)
                                {
                                    for (int e = 1; e <= 3; e ++)
                                    {
                                        for (int f = 1; f <= 3; f ++)
                                        {
                                            if (i + j + k + t + a + b + c + d + e + f == n)
                                            {
                                                sum[num].i = i;
                                                sum[num].j = j;
                                                sum[num].k = k;
                                                sum[num].t = t;
                                                sum[num].a = a;
                                                sum[num].b = b;
                                                sum[num].c = c;
                                                sum[num].d = d;
                                                sum[num].e = e;
                                                sum[num].f = f;
                                                num ++;
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (num != 0) cout << num << '\n';
    if (num == 0) 
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < num; i ++)
    {
        cout << sum[i].i  << ' ' << sum[i].j  << ' ' << sum[i].k << ' ' << sum[i].t << ' ' << sum[i].a << ' ' << sum[i].b << ' ' << sum[i].c << ' ' << sum[i].d << ' ' << sum[i].e << ' ' << sum[i].f << '\n';
    }
    system("pause");
    return 0;
}