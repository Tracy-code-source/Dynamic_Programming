//https://www.luogu.com.cn/problem/P1563
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, m;
int dir[100100];
string name[100100];
int cdir[100100];
int mov[100100];
signed main()
{
    cin >> n  >> m;
    for (int i = 0; i < n; i ++)
    {
        cin >> dir[i] >> name[i];
    }
    for (int i = 0; i < m; i ++)
    {
        cin >> cdir[i] >> mov[i];
    }
    int loc = 0;
    for (int i = 0; i < m; i ++)
    {
        if (dir[loc] == 0)
        {
            if (cdir[i] == 0) 
            { 
                if (loc - mov[i] >= 0) loc = (loc - mov[i]) % n;
                else loc = n + (loc - mov[i]) % n;
            }
            else loc = (loc + mov[i]) % n;
        }
        else 
        {
            if (cdir[i] == 0) loc = (loc + mov[i]) % n;
            else 
            {
                if (loc - mov[i] >= 0) loc = (loc - mov[i]) % n;
                else loc = n + (loc - mov[i]) % n;
            }
        }
    }
    cout << name[loc] << '\n';
    system("pause");
    return 0;
}