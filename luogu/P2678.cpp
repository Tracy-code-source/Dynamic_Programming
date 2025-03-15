//https://www.luogu.com.cn/problem/P2678
#include <bits/stdc++.h>
using namespace std;
#define int long long
int L, N, M, ans;
int loc[50005];
bool judge(int length)
{
    int cnt = 0, prev = 0;
    for (int i = 1; i <= N; i ++)
    {
        if (loc[i] - prev < length) cnt ++;
        else prev = loc[i];
    }
    return cnt <= M;
}
signed main()
{
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i ++) cin >> loc[i];
    loc[N + 1] = L;
    int left = 1, right = L, mid;
    while (right >= left)
    {
        mid = (left + right) / 2;
        if (judge(mid)) ans = mid, left = mid + 1;
        else right = mid - 1;
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}