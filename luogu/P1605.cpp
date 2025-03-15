//https://www.luogu.com.cn/problem/P1605
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M, T;
int SX, SY, FX, FY;
int ans;
int mp[7][7];
struct Loc
{
    int x, y;
}loc[15];
void Block(int x, int y)
{
    mp[x][y] = 1;
}
void dfs(int x, int y)
{
    if (x == FX && y == FY) ans ++;
    if (x + 1 <= N && x + 1 >= 1 && y >= 1 && y <= M && mp[x + 1][y] == 0)
    {
        mp[x][y] = 1;
        dfs(x + 1, y);
        mp[x][y] = 0;
    }
    if (x - 1 <= N && x - 1 >= 1 && y >= 1 && y <= M && mp[x - 1][y] == 0)
    {
        mp[x][y] = 1;
        dfs(x - 1, y);
        mp[x][y] = 0;
    }
    if (y + 1 <= M && y + 1 >= 1 && x >= 1 && x <= N && mp[x][y + 1] == 0)
    {
        mp[x][y] = 1;
        dfs(x, y + 1);
        mp[x][y] = 0;
    }
    if (y - 1 <= M && y - 1 >= 1 && x >= 1 && x <= N && mp[x][y - 1] == 0)
    {
        mp[x][y] = 1;
        dfs(x, y - 1);
        mp[x][y] = 0;
    }
}
signed main()
{
    cin >> N >> M >> T;
    cin >> SX >> SY >> FX >> FY;
    for (int i = 1; i <= T; i ++) cin >> loc[i].x >> loc[i].y;
    for (int i = 1; i <= T; i ++) Block(loc[i].x, loc[i].y);
    dfs(SX, SY);
    cout << ans << '\n';
    system("pause");
    return 0;
}