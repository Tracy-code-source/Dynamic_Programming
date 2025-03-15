//01背包问题（二维数组）
#include <bits/stdc++.h>
using namespace std;
#define int long long
int value[105][105];
struct In
{
    int w;
    int v;
}item[105];
int n;//有n个物品
int weight;//背包最大容量
void Dynamic_Programming()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= weight; j ++)
        {
            if (item[i].w > j) value[i][j] = value[i - 1][j];
            else value[i][j] = max(value[i - 1][j], value[i - 1][j - item[i].w] + item[i].v);
        }
    }
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> item[i].w >> item[i].v;//录入物品信息
    }
    cin >> weight;
    Dynamic_Programming();
    cout << value[n][weight] << '\n';
    system("pause");
    return 0;
}