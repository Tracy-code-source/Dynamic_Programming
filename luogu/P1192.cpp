//https://www.luogu.com.cn/problem/P1192
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 100003;
int N, K, ans;
int solution[100005];
int fb(int n)
{
    if (solution[n] != 0) return solution[n];
    int num = 0;
    for (int i = n - 1; i >= n - K && i >= 0; i --)
    {
        num += fb(i) % mod;
        num %= mod;
    }
    solution[n] = num % mod;
    return solution[n];
}
signed main()
{
    cin >> N >> K;
    solution[0] = 1,solution[1] = 1;
    int ret = fb(N);
    cout << ret%mod << '\n';
    system("pause");
    return 0;
}