//https://www.luogu.com.cn/problem/P3397
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int mp[1005][1005];
struct loc
{
    int x1, y1;
    int x2, y2;
}location[1005];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) 
    {
        cin >> location[i].x1 >> location[i].y1 >> location[i].x2 >> location[i].y2;
    }
    for (int i = 1; i <= m; i ++)
    {
        for (int j = location[i].x1; j <= location[i].x2; j ++)
        {
            for (int k = location[i].y1; k <= location[i].y2; k ++)
            {
                mp[j][k] ++;
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
    system("pause");
    return 0;
}
