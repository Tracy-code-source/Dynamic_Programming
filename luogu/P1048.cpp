//https://www.luogu.com.cn/problem/P1048
#include <bits/stdc++.h>
using namespace std;
#define int long long
int T, M;
int value[105][1005];
struct In
{
    int t;
    int v;
}herb[105];
void Dynamic_Programming()
{
    for (int i = 1; i <= M; i ++)
    {
        for (int j = 1; j <= T; j ++)
        {
            if (herb[i].t > j) value[i][j] = value[i - 1][j];
            else value[i][j] = max(value[i - 1][j], value[i - 1][j - herb[i].t] + herb[i].v);
        }
    }
}
signed main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i ++)
    {
        cin >> herb[i].t >> herb[i].v;
    }
    Dynamic_Programming();
    cout << value[M][T] << '\n';
    system("pause");
    return 0;
}