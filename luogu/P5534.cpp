//https://www.luogu.com.cn/problem/P5534
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a1, a2, k, d;
int an[1000005];
int ret(int k)
{
    int end = 0;
    for (int i = 1; i <= k; i ++)
    {
        end += an[i];
    }
    return end;
}
signed main()
{
    cin >> a1 >> a2 >> k;
    d = a2 - a1;
    an[1] = a1;
    an[2] = a2;
    for (int i = 3; i <= k; i ++)
    {
        an[i] = an[i - 1] + d;
    }
    cout << ret(k) << '\n';
    system("pause");
    return 0;
}