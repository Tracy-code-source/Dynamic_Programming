//https://www.luogu.com.cn/problem/P2249
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int num[1000005];
int target[100005];
int ans[100005];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> num[i];
    for (int i = 1; i <= m; i ++) cin >> target[i];
    for (int i = 1; i <= m; i ++)
    {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (target[i] > num[mid]) left = mid + 1;
            else right = mid; 
        }
        if (num[left] == target[i]) ans[i] = left;
        else ans[i] = -1;
    }
    for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
    cout << '\n';
    system("pause");
    return 0;
}