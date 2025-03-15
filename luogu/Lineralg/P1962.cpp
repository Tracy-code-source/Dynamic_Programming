//https://www.luogu.com.cn/problem/P1962
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
struct cube
{
    int a11 = 1, a12 = 1;
    int a21 = 1, a22 = 0;
};
struct Start
{
    int i = 1;
    int j = 1;
};
signed main()
{
    cin >> n;
    struct cube C;
    struct Start A;
    if (n <= 2) cout << 1 << '\n';
    else 
    {
        k = n - 2;
        while (k > 0)
        {
            if (k & 1)
            {
                int i1 = (C.a11 * A.i + C.a12 * A.j) % 1000000007;
                int j1 = (C.a21 * A.i + C.a22 * A.j) % 1000000007;
                A.i = i1;
                A.j = j1;
            }
            int t1 = (C.a11 * C.a11 + C.a12 * C.a21) % 1000000007;
            int t2 = (C.a11 * C.a12 + C.a12 * C.a22) % 1000000007;
            int t3 = (C.a21 * C.a11 + C.a22 * C.a21) % 1000000007;
            int t4 = (C.a21 * C.a12 + C.a22 * C.a22) % 1000000007;
            C.a11 = t1, C.a12 = t2, C.a21 = t3, C.a22 = t4;
            k >>= 1;
        }
        cout << A.i << '\n';
    }
    system("pause");
    return 0;
}