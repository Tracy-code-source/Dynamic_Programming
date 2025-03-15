//https://www.luogu.com.cn/problem/P1094
#include <bits/stdc++.h>
using namespace std;
#define int long long
int w, n;
int gift[30005];
int ans;
bool compare(int a, int b)
{
    return a > b;
}
signed main()
{
    cin >> w >> n;
    for (int i = 1; i <= n; i ++) cin >> gift[i];
    sort(gift + 1, gift + 1 + n, compare);
    int left = 1, right = n;
    while (left <= right)
    {
        if (left == right)
        {
            ans ++;
            break;
        }
        if (gift[left] + gift[right] > w)
        {
            ans ++;
            left ++;
        }
        else 
        {
            ans ++;
            left ++;
            right --;
        }
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}