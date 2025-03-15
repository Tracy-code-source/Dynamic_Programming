//https://www.luogu.com.cn/problem/P1208
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int ans;
struct cow
{
    int p;
    int maxx;
}farmer[5005];
bool cmp(struct cow a, struct cow b)
{
    return a.p < b.p;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        cin >> farmer[i].p >> farmer[i].maxx;
    }
    sort(farmer + 1, farmer + 1 + m, cmp);
    for (int i = 1; i <= m; i ++)
    {
        if (n > farmer[i].maxx)
        {
            ans += farmer[i].p * farmer[i].maxx;
            n -= farmer[i].maxx;
        }
        else 
        {
            ans += farmer[i].p * n;
            break;
        }
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}