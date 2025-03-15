//多重背包问题（此写法在每种物品有较多件时时间会爆）
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, W;
int num[105];
int n = 1, sum;
struct In
{
    int w;
    int v;
}item[1005];
int value[1005][105];
void Dynamic_Programming()
{
    for (int i = 1; i <= sum; i ++)
    {
        for (int j = 1; j <= W; j ++)
        {
            if (item[i].w > j) value[i][j] = value[i - 1][j];
            else value[i][j] = max(value[i - 1][j], value[i - 1][j - item[i].w] + item[i].v);
        }
    }
}
signed main()
{
    cin >> N >> W;
    for (int i = 1; i <= N; i ++)
    {
        int w1, v1;
        cin >> w1 >> v1 >> num[i];
        sum += num[i];
        for (int j = 1; j <= num[i]; j ++)
        {
            item[n].w = w1;
            item[n].v = v1;
            n ++;
        }
    }
    Dynamic_Programming();
    cout << value[sum][W] << '\n';
    system("pause");
    return 0;
}