//https://www.luogu.com.cn/problem/P2670
#include <bits/stdc++.h>
using namespace std;
#define int long long
char mapp[105][105];
int n, m;
void search(int x, int y)
{
    int num = 0;
    for (int i = x - 1; i < x + 2; i ++)
    {
        for (int j = y - 1; j < y + 2; j ++)
        {
            if (mapp[i][j] == '*') num ++;
        }
    }
    mapp[x][y] = num + '0';
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cin >> mapp[i][j];
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (mapp[i][j] == '?') search(i, j);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cout << mapp[i][j];
        }
        cout << '\n';
    }
    system("pause");
    return 0;
}