//https://www.luogu.com.cn/problem/P4057
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c;
int ans;
signed main()
{
    cin >> a >> b >> c;
    int r = a % b;
    int t = a * b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    int m1 = t / b;
    int r1 = m1 % c;
    int t1 = m1 * c;
    while (r1 != 0)
    {
        m1 = c;
        c = r1;
        r1 = m1 % c;
    }
    cout << t1 / c << '\n';
    system("pause");
    return 0;
}