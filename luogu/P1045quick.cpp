//https://www.luogu.com.cn/problem/P1045
#include <bits/stdc++.h>
using namespace std;
#define int long long
int num[5005], p[10005];
int P, k1 = 1, k2 = 1;
void Mul1()
{
    int ans[10005];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < k2; i ++)
    {
        for (int j = 0; j < k1; j ++)
        {
            ans[i + j] += num[j] * p[i];
            if (ans[i + j] > 9)
            {
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }
        }
    }
    while (ans[k1 + 1] != 0) k1 ++;
    for (int i = 1; i <= k1; i ++) num[i] = ans[i];
    return ;
}
void Mul2()
{
    int ans[10005];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < k2; i ++)
    {
        for (int j = 0; j < k2; j ++)
        {
            ans[i + j] += p[j] * p[i];
            if (ans[i + j] > 9)
            {
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }
        }
    }
    while (ans[k2 + 1] != 0) k2 ++;
    for (int i = 1; i <= k2; i ++) p[i] = ans[i];
    return ;
}
signed main()
{
    cin >> P;
    int ret = ceil(P * log10(2));
    cout << ret << '\n';
    num[0] = 1;
    p[0] = 2;
    while (P > 0)
    {
        if (P & 1) 
        {
            Mul1();
        }
        Mul2();
        P >>= 1;
    }
    int n = 0;
    for (int i = 500; i >= 1; i --) 
    {
        cout << num[i];
        n ++;
        if (n == 50) cout <<'\n', n = 0;
    }
    system("pause");
    return 0;
}