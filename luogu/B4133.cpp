//https://www.luogu.com.cn/problem/B4133
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, l;
//int nums[10000005];
int ans = -888888888;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int a;
        scanf("%lld", &a);
        if (i == 1) l = a;
        else l = max(l + a, a);
        ans = max(ans, l);
    }
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}
