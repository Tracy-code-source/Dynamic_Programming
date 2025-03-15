//https://www.luogu.com.cn/problem/P1478
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, s;
int a, b;
int ans;
struct In
{
    int height;
    int cost;
}apple[5005];
bool compare(struct In a, struct In b)
{
    return a.cost < b.cost;
}
signed main()
{
    cin >> n >> s;
    cin >> a >> b;
    for (int i = 1; i <= n; i ++)
    {
        cin >> apple[i].height >> apple[i].cost;
    }
    sort(apple + 1, apple + 1 + n, compare);
    /*for (int i = 1; i <= n; i ++)
    {
        cout << apple[i].height << ' ' << apple[i].cost << '\n';
    }*/
    for (int i = 1; i <= n; i ++)
    {
        if (a + b >= apple[i].height && s >= apple[i].cost)
        {
            ans ++;
            s -= apple[i].cost;
        }
        if (s <= 0) break;
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}