//https://www.luogu.com.cn/problem/P4995
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int height[305];
int ans;
bool cmp(int a, int b)
{
    return a < b;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> height[i];
    sort(height + 1, height + 1 + n, cmp);
    int left = 0, right = n;
    while (left < right)
    {
        int energy1 = (height[right] - height[left]) * (height[right] - height[left]);
        int energy2 = (height[right] - height[left + 1]) * (height[right] - height[left + 1]);
        ans += energy1 + energy2;
        left ++;
        right --;
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}