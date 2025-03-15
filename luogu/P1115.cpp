//https://www.luogu.com.cn/problem/P1115
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, l, ans = -99999999;
int nums[200005];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> nums[i];
        if (i == 1) l = nums[i];
        else l = max(l + nums[i], nums[i]);
        ans = max(ans, l);
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}