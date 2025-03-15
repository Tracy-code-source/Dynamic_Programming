//https://www.luogu.com.cn/problem/P1145
#include <bits/stdc++.h>
using namespace std;
#define int long long

int k, m;
signed main()
{
    cin >> k;          
    int n1 = k, n2 = k;
    
    for (int i = k + 1; ; i ++)
    {
        queue <int> tok;
        for (int i = 1; i <= k; i ++) tok.push(1);
        for (int i = 1; i <= k; i ++) tok.push(2);
        if (i % (k + 2) != 0) continue;
        else
        {
            m = i;
            n2 = k;
            while (n2 > 0)
            {
                for (int j = 1; j < m; j ++)
                {
                    tok.push(tok.front());
                    tok.pop();
                }
                if (tok.front() == 2)
                {
                    tok.pop();
                    n2 --;
                }
                else
                {
                    break;
                }
            }
            if (n2 == 0) break;
        }
    }
    cout << m << '\n';
    system("pause");
    return 0;
}