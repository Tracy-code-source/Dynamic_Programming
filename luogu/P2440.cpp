//https://www.luogu.com.cn/problem/P2440
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, num;
int wood[100005];
bool ans = 1;
bool compare(int a, int b)
{
    return a > b;
}
bool check(int len)
{
    int num = 0;
    for (int i = 1; i <= n; i ++)
    {
        num += wood[i] / len;
        if (num >= k) return true;
    }
    
    return false;
}
signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> wood[i];
    sort (wood + 1, wood + 1 + n, compare);
    int left = 1, right = wood[1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (check(mid)) left = mid + 1;
        else right = mid;
        if (right == left && right == 1)
        {
            if (check(right)) ans = 1;
            else ans = 0;
        }
    }
    if (ans == 0) cout << "0" << '\n';
    else cout << --right << '\n';
    system("pause");
    return 0;
}
