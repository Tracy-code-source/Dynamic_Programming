//https://www.luogu.com.cn/problem/P1803
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct be
{
    int bg;
    int end;
}game[1000005];
bool cmp(struct be a, struct be b)
{
    return a.end < b.end;
}
int ans;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) 
    {
        cin >> game[i].bg >> game[i].end;
    }
    sort(game + 1, game + n + 1, cmp);
    int beg = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (beg <= game[i].bg)
        {
            ans ++;
            beg = game[i].end;
        }
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}