//https://www.luogu.com.cn/problem/P2004
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M, C;
int mp[1005][1005];
int value[1005][1005];
int maxx, x, y;
signed main()
{
    cin >> N >> M >> C;
    for (int i = 1; i <= N; i ++)
    {
        for (int j = 1; j <= M; j ++)
        {
            cin >> mp[i][j];
            value[i][j] = mp[i][j] + value[i - 1][j] + value[i][j - 1] - value[i - 1][j - 1];                                                                                            
        }
    }
    for (int i = 1; i + C - 1 <= N; i ++)
    {
        for (int j = 1; j + C - 1 <= M; j ++)
        {
            int n = value[i + C - 1][j + C - 1] - value[i + C - 1][j - 1] - value[i - 1][j + C - 1] + value[i - 1][j - 1];
            if (n >= maxx)
            {
                maxx = n;
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y << '\n';
    system("pause");
    return 0;
}