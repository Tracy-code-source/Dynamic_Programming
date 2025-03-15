//https://www.luogu.com.cn/problem/P1226
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, p;
int quickpower(int a, int b)
{
    int ans = 1, k = a;
    while (b > 0)
    {
        if (b & 1) ans = (ans * k) % p;
        k = (k * k) % p;
        b >>= 1;
    }
    return ans % p;
}
signed main()
{
    cin >> a >> b >> p;
    cout << a << '^' << b << ' ' << "mod" << ' ' << p << '=' << quickpower(a, b) << '\n';
    system("pause");
    return 0; 
}
