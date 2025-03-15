//https://www.luogu.com.cn/problem/P1147
#include <bits/stdc++.h>
using namespace std;
#define int long long
int M;
int nums[2000005];
int ans;
signed main()
{
    cin >> M;
    int left = 1;
    for (int right = 1; right < M; right ++)
    {
        ans += right;
        while (ans > M)
        {
            ans -= left;
            left ++;
        }
        if (ans == M) cout << left << ' ' << right << '\n';
    }
    system("pause");
    return 0;
}