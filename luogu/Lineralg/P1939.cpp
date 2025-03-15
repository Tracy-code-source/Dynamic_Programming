//https://www.luogu.com.cn/problem/P1939
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1000000007
int n;
int num[105];
int ans[105];
struct cube
{
    int a11 = 1, a12 = 0, a13 = 1;
    int a21 = 1, a22 = 0, a23 = 0;
    int a31 = 0, a32 = 1, a33 = 0;
};
struct A
{
    int i = 1;
    int j = 1;
    int k = 1;
};
signed main()
{
    cin >> n;
    struct cube c;
    struct A a;
    for (int i = 1; i <= n; i ++) cin >> num[i];
    for (int m = 1; m <= n; m ++)
    {
        if (num[m] <= 3) ans[m] = 1;
        else 
        {
            int k = num[m] - 3;
            while (k > 0)
            {
                if (k & 1)
                {
                    int i1 = (c.a11 * a.i + c.a12 * a.j + c.a13 * a.k) % MAX;
                    int j1 = (c.a21 * a.i + c.a22 * a.j + c.a23 * a.k) % MAX;
                    int k1 = (c.a31 * a.i + c.a32 * a.j + c.a33 * a.k) % MAX;
                    a.i = i1, a.j = j1, a.k = k1;
                }
                int t1 = (c.a11 * c.a11 + c.a12 * c.a21 + c.a13 * c.a31) % MAX;
                int t2 = (c.a11 * c.a12 + c.a12 * c.a22 + c.a13 * c.a32) % MAX;
                int t3 = (c.a11 * c.a13 + c.a12 * c.a23 + c.a13 * c.a33) % MAX;
                int t4 = (c.a21 * c.a11 + c.a22 * c.a21 + c.a23 * c.a31) % MAX;
                int t5 = (c.a21 * c.a12 + c.a22 * c.a22 + c.a23 * c.a32) % MAX;
                int t6 = (c.a21 * c.a13 + c.a22 * c.a23 + c.a23 * c.a33) % MAX;
                int t7 = (c.a31 * c.a11 + c.a32 * c.a21 + c.a33 * c.a31) % MAX;
                int t8 = (c.a31 * c.a12 + c.a32 * c.a22 + c.a33 * c.a32) % MAX;
                int t9 = (c.a31 * c.a13 + c.a32 * c.a23 + c.a33 * c.a33) % MAX;
                c.a11 = t1, c.a12 = t2, c.a13 = t3;
                c.a21 = t4, c.a22 = t5, c.a23 = t6;
                c.a31 = t7, c.a32 = t8, c.a33 = t9;
                k >>= 1;
            }
            ans[m] = a.i;
            a.i = 1, a.j = 1, a.k = 1;
            c.a11 = 1, c.a12 = 0, c.a13 = 1;
            c.a21 = 1, c.a22 = 0, c.a23 = 0;
            c.a31 = 0, c.a32 = 1, c.a33 = 0;
        }
    }
    for (int i = 1; i <= n; i ++) cout << ans[i] << '\n';
    system("pause");
    return 0;
}