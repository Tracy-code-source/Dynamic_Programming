//https://www.luogu.com.cn/problem/P2392
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct ID
{
    int s;
    int num[25];
}q[5];
int ans;
signed main()
{
    for (int i = 1; i <= 4; i ++) cin >> q[i].s;
    for (int i = 1; i <= 4; i ++)
    {
        for (int j = 1; j <= q[i].s; j ++)
        {
            cin >> q[i].num[j];
        }
    }
    /*for (int i = 1; i <= 4; i ++)
    {
        for (int j = 1; j <= q[i].s; j ++)
        {
            cout << q[i].num[j] << ' ';
        }
        cout << '\n';
    }*/
    for (int i = 1; i <= 4; i ++)
    {
        int more = 0;
        for (int j = 1; j <= q[i].s; j += 2)
        {
            ans += max(q[i].num[j], q[i].num[j + 1]) - more;
            //cout << ans << '\n';
            more = abs(q[i].num[j] - q[i].num[j + 1]);
        }
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}