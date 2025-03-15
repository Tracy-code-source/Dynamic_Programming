//https://www.luogu.com.cn/problem/P3654
#include <bits/stdc++.h>
using namespace std;
int R, C, K;
char mp[105][105];
int num, n;
signed main()
{
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i ++)
    {
        for (int j = 1; j <= C; j ++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= R; i ++)
    {
        for (int j = 1; j <= C - K + 1; j ++)
        {
            n = 0;
            for (int k = 0; k < K; k ++)
            {
                if (mp[i][j + k] == '.') n ++;
                else break;
            }
            if (n == K) num ++;
        }
    }
    for (int i = 1; i <= C; i ++)
    {
        for (int j = 1; j <= R - K + 1; j ++)
        {
            n = 0;
            for (int k = 0; k < K; k ++)
            {
                if (mp[j + k][i] == '.') n ++;
                else break;
            }
            if (n == K) num ++;
        }
    }
    if (K == 1) cout << num / 2 << '\n';
    else cout << num << '\n';
    system("pause");
    return 0;
}