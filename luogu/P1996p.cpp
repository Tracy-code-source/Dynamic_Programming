//https://www.luogu.com.cn/problem/P1996
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int num, ans[105];
queue <int> member;
signed main()
{
    cin >> n >> m;
    int step = 1;
    for (int i = 1; i <= n; i ++)
    {
        member.push(i);
    }
    while (!member.empty())
    {
        if (step == m)
        {
            ans[num] = member.front();
            member.pop();
            num ++;
            step = 1;
        }
        else 
        {
            step ++;
            member.push(member.front());
            member.pop();
        }
    }
    for (int i = 0; i < n; i ++) cout << ans[i] << ' ';
    cout << '\n';
    system("pause");
    return 0;
}