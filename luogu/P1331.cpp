//https://www.luogu.com.cn/problem/P1331
#include <bits/stdc++.h>
using namespace std;
#define int long long
int R, C;
char mp[1005][1005];
int ans;
void dfs(int i , int j)
{
    mp[i][j] = '.';
    if (mp[i - 1][j] == '#') dfs(i - 1, j);
    if (mp[i + 1][j] == '#') dfs(i + 1, j);
    if (mp[i][j - 1] == '#') dfs(i, j - 1);
    if (mp[i][j + 1] == '#') dfs(i, j + 1);
}
signed main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i ++)
    {
        for (int j = 1; j <= C; j ++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= R; i ++)
    {
        for (int j = 1; j <= C; j ++)
        {
            if (mp[i][j] == '#')
            {
                ans ++;
                dfs(i, j);
            }
        }
    }
    if (ans == 0) cout << "Bad placement.\n";
    else cout  << "There are " << ans << " ships.\n";
    system("pause");
    return 0;
}