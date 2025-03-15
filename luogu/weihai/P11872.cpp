//https://www.luogu.com.cn/problem/P11872?contestId=234038
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
int nums[100005];
signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> nums[i];
    for (int i = 1; i <= q; i ++)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int x, p;
            cin >> x >> p;
            nums[x] = p;
        }
        if (op == 1)
        {
            int plus[100005] = {0};
            
        }
    }
}