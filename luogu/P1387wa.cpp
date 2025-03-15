//https://www.luogu.com.cn/problem/P4387
#include <bits/stdc++.h>
using namespace std;
#define int long long
int q;
int num[10];
int n[100005];
stack <int> l;
signed main()
{
    cin >> q;
    for (int i = 1; i <= q; i ++)
    {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j ++)
        {
            int a;
            cin >> a;
            l.push(a);
            //n[num[i] + 1 - j] = j;
        }
        for (int j = 1; j <= num[i]; j ++) cin >> n[j];
        for (int j = 1; j <= num[i]; j ++)
        {
            if (n[j] == l.top())
            {
                n[j] = 0;
                l.pop();
            }
            else break;
        }
        if (l.empty()) cout << "Yes" << '\n';
        else 
        {
            memset(n, 0, sizeof(n));
            while(!l.empty()) l.pop();
            cout << "No" << '\n';
        }
    }
    system("pause");
    return 0;
}