//https://www.luogu.com.cn/problem/P10579
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a, b, c;
int l;
int ans = -9999999;
int nums[300005];
bool check(int ans)
{
    
}
signed main()
{
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i ++) cin >> nums[i];
    int left = 1, right = 1;
    for (int i = 1; i <= n; i ++)
    {
        nums[i] += nums[i - 1]; 
    }
    
    //cout << ans << '\n';
    system("pause");
    return 0;
}