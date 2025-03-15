//https://www.luogu.com.cn/problem/P1024
#include <bits/stdc++.h>
using namespace std;
#define int long long
double a, b, c, d;
signed main()
{
    cin >> a >> b >> c >> d;
    for (double i = -100.00; i <= 100.00; i += 0.01)
    {
        double ans = a * i * i * i + b * i * i + c * i + d;
        if ((ans >= -0.001 && ans <= 0.001) || ans == 0.00) printf("%.2lf ", i);
    }
    cout << '\n';
    system("pause");
    return 0;
}