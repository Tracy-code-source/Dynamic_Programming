//https://www.luogu.com.cn/problem/P4387
#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, num;
stack <int> l;
int n[100005];
int n2[100005];
signed main()
{
    cin >> q;
    for (int i = 1; i <= q; i ++)
    {
        while(l.size()) l.pop();
        int number;
        cin >> number;
        for(int i = 1;i<=number;i++)
        {
            cin >> n[i];
        }
        for(int i = 1;i<=number;i++)
        {
            cin >> n2[i];
        }

        int cnt1 = 0,cnt2 = 0;
        while(cnt1 < number)
        {
            l.push(n[++cnt1]);
            while(!l.empty()&&l.top()==n2[cnt2+1])
            {
                l.pop();
                cnt2++;
            }
        }

        if(cnt2>=number) cout << "Yes\n";
        else cout << "No\n";
    }
    system("pause");
}
