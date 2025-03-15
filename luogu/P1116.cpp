//https://www.luogu.com.cn/problem/P1116
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, n;
int num[10005];
signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i ++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= N - 1; i ++)
    {
        for (int j = i; j <= N; j ++)
        {
            if (num[j] < num[i]) n ++;
        }
    }
    cout << n << '\n';
    system("pause");
    return 0;
}