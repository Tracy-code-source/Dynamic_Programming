//多重背包问题（二进制优化）
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, W;
int value[1005];
struct In
{
    int w;
    int v;
    //int num;
}item[1005];
int n;
void Dynamic_Programming()
{
    for (int i = 1; i <= n; i ++)
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
        int tempw, tempv, num;
        cin >> tempw >> tempv >> num;
        for (int j = 1; j <= num; j <<= 1)
        {
            n ++;
            item[n].w = tempw * j;
            item[n].v = tempv * j;
            num -= j;
        }
        if (num != 0)
        {
            n ++;
            item[n].w = tempw * num;
            item[n].v = tempv * num;
        }
    }
    Dynamic_Programming();
    cout << value[W] << '\n';
    system("pause");
    return 0;
}