//https://www.luogu.com.cn/problem/P1160
#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt;
struct stnode
{
    int i,l,r;
    bool isdead = 0;
}node[100005];
int sy[100005];

 
signed main()
{
    int n,m;
    cin >> n;
    cnt = 1;
    node[1].i = 1;
    node[1].l = 0;
    node[1].r = 0;
    sy[1] = 1;
    for(int i = 2;i<=n;i++)
    {
        int k,p;
        cin >> k >> p;

        cnt++;
        sy[cnt] = i;
        if(p==0)
        {
            node[node[sy[k]].l].r = cnt;
            node[cnt].l = node[sy[k]].l;

            node[sy[k]].l = cnt;
            node[cnt].r = sy[k];

            node[cnt].i = i;
        }
        else
        {
            node[node[sy[k]].r].l = cnt;
            node[cnt].r = node[sy[k]].r;

            node[sy[k]].r = cnt;
            node[cnt].l = sy[k];

            node[cnt].i = i;
        }
    }
    cin >> m;
    for(int i = 0;i<m;i++)
    {
        int s;
        cin >> s;
        node[sy[s]].isdead = 1;
    }

    int ans = 1;

    while(node[ans].l!=0) ans = node[ans].l;

    while(node[ans].i!=0)
    {
        if(node[ans].isdead == 0) cout << node[ans].i << ' ';
        ans = node[ans].r;
    }
    system("pause");
    return 0;
}
