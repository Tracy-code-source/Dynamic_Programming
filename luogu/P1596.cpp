//https://www.luogu.com.cn/problem/P1596
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
char mp[105][105];
int ans;
void dfs(int i, int j)
{
    mp[i][j] = '.';
    if (mp[i - 1][j] == 'W') dfs(i - 1, j);
    if (mp[i + 1][j] == 'W') dfs(i + 1, j);
    if (mp[i][j - 1] == 'W') dfs(i, j - 1);
    if (mp[i][j + 1] == 'W') dfs(i, j + 1);
    if (mp[i - 1][j - 1] == 'W') dfs(i - 1, j - 1);
    if (mp[i - 1][j + 1] == 'W') dfs(i - 1, j + 1);
    if (mp[i + 1][j - 1] == 'W') dfs(i + 1, j - 1);
    if (mp[i + 1][j + 1] == 'W') dfs(i + 1, j + 1);
}
signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i ++)
    {
        for (int j = 1; j <= M; j ++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= N; i ++)
    {
        for (int j = 1; j <= M; j ++)
        {
            if (mp[i][j] == 'W')
            {
                ans ++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}