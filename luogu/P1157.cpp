//https://www.luogu.com.cn/problem/P1157
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define int long long
int n, r;
int nums[25];
int ans[25];
void dfs(int num, int ns, int mark)
{
    if (num > ns)
    {
        for (int i = 1; i <= r; i ++) cout << setw(3) << ans[i];
    }
    

}
signed main()
{
    cin >> n >> r;

}