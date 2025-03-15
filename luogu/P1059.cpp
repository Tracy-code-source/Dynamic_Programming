//https://www.luogu.com.cn/problem/P1059
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int num[105], ret[105];
bool cmp(int a, int b)
{
    return a < b;
}
signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i ++)
    {
        cin >> num[i];
    }
    int j = 1;
    for (int i = 1; i <= N; i ++)
    {
        int k = 0;
        for (int t = 1; t <= j; t ++)
        {
            if (num[i] == ret[t])
            {
                k = 1;
                break;
            }
        }
        if (k == 0)
        {
            ret[j] = num[i];
            j ++;
        }
    }
    sort(ret, ret + j, cmp);
    cout << j - 1 << '\n';
    for (int i = 1; i < j; i ++)
    {
        cout << ret[i] << ' ';
    }
    cout << '\n';
    system("pause");
    return 0;
}