//https://www.luogu.com.cn/problem/P2058
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct In
{
    int t, k;
}ship[300005];
int nation[100005];
int ans[100005];
int a, l, r;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int t, k;
        cin >> t >> k;
        /*if (ship[i].t > second) 
        {
            second += 86400;
            a = 0;
            memset(nation, 0, sizeof(nation));
        }*/
        for (int j = 1; j <= k; j ++)
        {   
            int nat;
            cin >> nat;
            r ++;
            ship[r].t = t, ship[r].k = nat;
            nation[nat] ++;
            if (nation[nat] == 1) a ++;
        }
        while (l < r && t - ship[l].t >= 86400)
        {
            nation[ship[l].k] --;
            if (nation[ship[l].k] == 0) a--;
            l ++;
        }
        ans[i] = a;
    }
    for (int i = 1; i <= n; i ++)
    {
        cout << ans[i] << '\n';
    }
    system("pause");
    return 0;
}
