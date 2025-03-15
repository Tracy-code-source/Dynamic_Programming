//https://www.luogu.com.cn/problem/P11868?contestId=234038
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b;
double ans;
signed main()
{
    cin >> a >> b;
    ans = min(a, b);
    printf("%.8lf\n", ans);
    system("pause");
    return 0;
}