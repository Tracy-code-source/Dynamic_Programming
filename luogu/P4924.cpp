//https://www.luogu.com.cn/problem/P4924
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, num = 1;
int x, y, r, z;
int sq[505][505], temp[505][505];
void magic1(int xi, int yi, int len)//shun
{
    for (int i = 0; i < len; i ++)
    {
        for (int j = 0; j < len; j ++)
        {
            temp[xi + j][yi + len - 1 - i] = sq[xi + i][yi + j];
        }
    }
    for (int i = xi; i < xi + len; i ++)
    {
        for (int j = yi; j < yi + len; j ++)
        {
            sq[i][j] = temp[i][j];
        }
    }
    temp[505][505] = {0};
}
void magic2(int xi, int yi, int len)//ni
{
    for (int i = 0; i < len; i ++)
    {
        for (int j = 0; j < len; j ++)
        {
            temp[xi + len - 1 - j][yi + i] = sq[xi + i][yi + j]; 
        }
    }
    for (int i = xi; i < xi + len; i ++)
    {
        for (int j = yi; j < yi + len; j ++)
        {
            sq[i][j] = temp[i][j];
        }
    }
    temp[505][505] = {0};
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            sq[i][j] = num;
            num ++;
        }
    }
    for (int i = 1; i <= m; i ++)
    {
        cin >> x >> y >> r >> z;
        if (z == 0) magic1(x - r, y - r, 2 * r + 1);
        else magic2(x - r, y - r, 2 * r + 1);
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            cout << sq[i][j] << ' ';
        }
        cout << '\n';
    }
    system("pause");
    return 0;
}