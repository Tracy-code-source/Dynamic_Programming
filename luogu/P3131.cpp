//https://www.luogu.com.cn/problem/P3131
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int ID[50005];
int ans;
signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i ++) cin >> ID[i];
    for (int i = 1; i <= N; i ++)
    {
        ID[i] += ID[i - 1];
    }
    for (int i = 1; i <= N; i ++) ID[i] %= 7;
    for (int i = 0; i <= 6; i ++)
    {
        int first = 0, end = 0;
        for (int j = 1; j <= N; j ++)
        {
            if (first == 0 && ID[j] == i) first = j, end = j;
            else if (ID[j] == i) end = j;
        }
        if ((i == 0 || end - first > 0) && end - first > ans) ans = end - first;
    }
    cout << ans << '\n';
    //for (int i = 1; i <= N; i ++) cout << ID[i] << ' ';
    system("pause");
    return 0;
}