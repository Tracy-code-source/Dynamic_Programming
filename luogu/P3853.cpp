//https://www.luogu.com.cn/problem/P3853
#include <bits/stdc++.h>
using namespace std;
#define int long long
int L, N, K;
int block[100005];
int len[100005];
bool compare(int a, int b)
{
    return a > b;
}
bool judge(int cherk)
{
    int cnt = 0;
    for (int i = 1; i <= N - 1; i ++)
    {
        if (len[i] / cherk > 0) cnt += len[i] / cherk;
        if (len[i] % cherk == 0) cnt -= 1;
    }
    return cnt <= K;
}
signed main()
{
    cin >> L >> N >> K;
    for (int i = 1; i <= N; i ++)
    {
        cin >> block[i];
        len[i - 1] = block[i] - block[i - 1];
    }
    sort(len + 1, len + N, compare);
    //for (int i = 1; i <= N - 1; i ++) cout << len[i] << '\n';
    int left = 1, right = L;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (judge(mid)) right = mid;
        else left = mid + 1;
    }
    cout << min(left, right) << '\n';
    system("pause");
    return 0;                                                                                                      
}