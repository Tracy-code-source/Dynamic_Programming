//https://www.luogu.com.cn/problem/P1540
#include <bits/stdc++.h>
using namespace std;
#define int long long
int M, N;
int num[1005];
int ans;
queue <int> n;
signed main()
{
    cin >> M >> N;
    for (int i = 1; i <= N; i ++) cin >> num[i];
    ans ++;
    n.push(num[1]);
    int save = 1;
    for (int i = 2; i <= N; i ++)
    {
        int len = n.size();
        //cout << len << ' ';
        int t = 0;
        while (len > 0)
        {
            if (n.front() != num[i])
            {
                n.push(n.front());
                n.pop();
                len --;
            }
            else if (n.front() == num[i])
            {
                n.push(n.front());
                n.pop();
                len --;
                t = 1;
            }
        }
        if (t == 0) 
        {
            n.push(num[i]);
            ans ++;
            save ++;
        }
        if (save > M)
        {
            n.pop();
            save = M;
        }
        //cout << ans << '\n';
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}
