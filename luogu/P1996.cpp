//https://www.luogu.com.cn/problem/P1996
#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
#define int long long
bool member[105];
int n, m;
int k, num = 1;
int ans[105];
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    k = n;
    for (int i = 1; i <= n; i ++) member[i] = 1;
    int loc = 1, step = m - 1;
    while (k > 0)
    {
        for (loc; step > 0; )
        {
            
            loc ++;
            if (loc > n) loc %= n;
            //printf("loc=%d,step=%d,member=%d\n",loc,step,member[loc]);
            if (member[loc] == 1) step --;
            
            //Sleep(100);
        }
        //printf("loc=%d,m=%d,k=%d\n",loc,m,k);
        if (member[loc] == 1 && step == 0)
        {
            ans[num] = loc;
            num ++;
            k --;
            member[loc] = 0;
            step = m;
        }
    }
    for (int i = 1; i < num; i ++) cout << ans[i] << ' ';
    cout << '\n';
    system("pause");
    return 0;
}