//https://www.luogu.com.cn/problem/P1271
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int num[2000005];
bool cmp(int a, int b)
{
    return a < b;
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++) cin >> num[i];
    sort(num, num + m, cmp);
    for (int i = 0; i < m; i ++) cout << num[i] << ' ';
    cout << '\n';
    system("pause");
    return 0;
}