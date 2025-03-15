//https://www.luogu.com.cn/problem/P1102
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, C, ans;
int nums[200005];
bool compare(int a, int b)
{
    return a < b;
}
void check(int n, int a)
{
    if (nums[n] == a)
    {
        ans ++;
        check(nums[n - 1], a);
    }
    else return ;
}
signed main()
{
    cin >> N >> C;
    for (int i = 1; i <= N; i ++) cin >> nums[i];
    sort(nums + 1, nums + 1 + N, compare);
    int left = 1, right1 = 1, right2 = 1;
    for (int left = 1; left <= N; left ++)
    {
        while (right1 <= N && nums[right1] - nums[left] <= C) right1 ++;
        while (right2 <= N && nums[right2] - nums[left] < C) right2 ++;
        if (nums[right2] - nums[left] == C && nums[right1 - 1] - nums[left] == C && right1 - 1 >= 1) ans += right1 - right2;
        
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}