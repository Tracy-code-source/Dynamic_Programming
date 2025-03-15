//https://www.luogu.com.cn/problem/P1469
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans = 0;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        int num;
        cin >> num;
        ans ^= num;
    }

    cout << ans << endl;
    system("pause");
    return 0;
}