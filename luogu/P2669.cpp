//https://www.luogu.com.cn/problem/P2669
#include <bits/stdc++.h>
using namespace std;
#define int long long
int k, n = 1;
int ans, num = 1;
signed main()
{
    cin >> k;
    for (int i = 1; i <= k; i ++)
    {
        if (i <= num)
        {
            ans += n;
        }
        if (i == num)
        {
            n ++;
            num += n;
        }
    }
    cout << ans << '\n';
    system("pause");
    return 0;
    
}