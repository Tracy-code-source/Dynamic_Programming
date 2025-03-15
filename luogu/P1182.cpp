//https://www.luogu.com.cn/problem/P1182
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
int nums[100005];
void dfs(int n)
{
    
}
signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i ++) 
    {
        cin >> nums[i];
        nums[i] += nums[i - 1];
    }
}
