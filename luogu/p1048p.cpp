//https://www.luogu.com.cn/problem/P1048
#include <bits/stdc++.h>
using namespace std;
#define int long long
int T, M;
int value[1005];
struct In
{
    int t;
    int v;
}herb[1005];
void Dynamic_Programming()
{
    for (int i = 1; i <= M; i ++)
    {
        for (int j = herb[i].t; j <= T ; j ++)
        {
            value[j] = max(value[j], herb[i].v + value[j - herb[i].t]);
        
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
    cout << value[T] << '\n';
    system("pause");
    return 0;
}