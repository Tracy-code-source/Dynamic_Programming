//https://www.luogu.com.cn/problem/P3392
#include <bits/stdc++.h>
using namespace std;
#define int long long
char mp[55][55];
int N, M;
int num;
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
    int minn = 999999;
    for (int i = 1; i <= N - 2; i ++)
    {
        for (int j = i + 1; j <= N - 1; j ++)
        {
            num = 0;
            for (int k = 1; k <= i; k ++)
            {
                for (int t = 1; t <= M; t ++)
                {
                    if (mp[k][t] != 'W') num ++;
                }
            }
            for (int k = i + 1; k <= j; k ++)
            {
                for (int t = 1; t <= M; t ++)
                {
                    if (mp[k][t] != 'B') num ++;
                }
            }
            for (int k = j + 1; k <= N; k ++)
            {
                for (int t = 1; t <= M; t ++)
                {
                    if (mp[k][t] != 'R') num ++;
                }
            }
            minn =  min(num, minn);
        }
    }
    cout << minn << '\n';
    system("pause");
    return 0;
}