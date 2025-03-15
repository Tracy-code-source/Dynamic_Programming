//https://www.luogu.com.cn/problem/P1002
#include <bits/stdc++.h>
using namespace std;
#define int long long
int BX, BY, HX, HY;
int mp[25][25];
int dp[25][25];
int ans;
void Block(int x, int y)
{
    mp[x][y] = 1;
    int direction[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (int i = 0; i < 8; i ++)
    {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if (nx >= 0 && nx <= BX && ny >= 0 && ny <= BY) mp[nx][ny] = 1;
    }
}
/*void dfs(int sx, int sy)
{
    if (sx == BX && sy == BY) ans ++;
    if (sx + 1 >= 0 && sx + 1 <= BX && sy >= 0 && sy <= BY && mp[sx + 1][sy] != 1) dfs(sx + 1, sy);
    if (sx >= 0 && sx <= BX && sy + 1 >= 0 && sy + 1 <= BY && mp[sx][sy + 1] != 1) dfs(sx, sy + 1); 
}*/
int solve(int sx, int sy)
{
    if (mp[sx][sy] == 1)  return dp[sx][sy] = 0;
    //if (dp[sx][sy] != 0) return dp[sx][sy];
    if ((sx == 0 || sx == BX) && sy - 1 >= 0 && sy <= BY) return dp[sx][sy] = solve(sx, sy - 1);
    if ((sy == 0 || sy == BY) && sx - 1 >= 0 && sx <= BX) return dp[sx][sy] = solve(sx - 1, sy);
    return dp[sx][sy] = solve(sx - 1, sy) + solve(sx, sy - 1);
}
signed main()
{
    cin >> BX >> BY >> HX >> HY;
    Block(HX, HY);
    //dfs(0, 0);
    dp[0][0] = 1;
    for (int i = 0; i <= BX; i ++)
    {
        for (int j = 0; j <= BY; j ++)
        {
            if (mp[i][j] == 1) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[BX][BY] << '\n';
    system("pause");
    return 0;
}