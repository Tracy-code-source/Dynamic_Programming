//01背包问题(一维滚动数组)
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, W;
int value[105];
struct In
{                                                                                                                       
    int w;
    int v;
}item[105];
void Dynamic_Programming()
{
    for (int i = 1; i <= N; i ++)
    {
        for (int j = W; j >= item[i].w; j --)
        {
            value[j] = max(value[j], value[j - item[i].w] + item[i].v);
        }
    }
}
signed main()
{
    cin >> N >> W;
    for (int i = 1; i <= N; i ++)
    {
        cin >> item[i].w >> item[i].v;  
    }
    Dynamic_Programming();
    cout << value[W] << '\n';
    system("pause");
    return 0;
}