//https://www.luogu.com.cn/problem/P2676
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, B;
int num, realh;
int height[20005];
bool cmp(int a, int b)
{
    return a > b;
}
signed main()
{
    cin >> N >> B;
    for (int i = 1; i <= N; i ++) cin >> height[i];
    sort(height + 1, height + 1 + N, cmp);
    for (int i = 1; i <= N; i ++)
    {
        realh += height[i];
        num ++;
        if (realh >= B) break;
    }
    cout << num << '\n';
    system("pause");
    return 0;
}