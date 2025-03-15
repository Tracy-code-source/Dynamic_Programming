//https://www.luogu.com.cn/problem/P3613
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
int num = 1;
int ans[100005];
map<int, int>bag[100005];
signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= q; i ++)
    {
        int choice, i1, j1, k;
        cin >> choice;
        if (choice == 1)
        {
            cin >> i1 >> j1 >> k;
            bag[i1][j1] = k;
        }
        else 
        {
            cin >> i1 >> j1;
            ans[num] = bag[i1][j1];
            num ++;
            //cout << bag[i1][j1] << '\n';
        }
    }
    for (int i = 1; i < num; i ++) cout << ans[i] << '\n';
    system("pause");
    return 0;
}