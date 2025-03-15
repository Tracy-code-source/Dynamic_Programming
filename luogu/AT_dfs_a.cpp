//https://www.luogu.com.cn/problem/AT_dfs_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int x, y, sx, sy;
int ans;
char mp[505][505];
void dfs(int i, int j)
{
    if (i == x && j == y) ans = 1;
    mp[i][j] = '#';
    if (mp[i - 1][j] == '.') dfs(i - 1, j);
    if (mp[i + 1][j] == '.') dfs(i + 1, j);
    if (mp[i][j - 1] == '.') dfs(i, j - 1);
    if (mp[i][j + 1] == '.') dfs(i, j + 1);

}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'g') 
            {
                x = i;
                y = j;
                mp[x][y] = '.';
            }
            if (mp[i][j] == 's')
            {
                sx = i;
                sy = j;
            }
        }
    }
    dfs(sx, sy);

    if (ans == 1) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    system("pause");
    return 0;
}