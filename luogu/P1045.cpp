//https://www.luogu.com.cn/problem/P1045
#include <bits/stdc++.h>
using namespace std;
#define int long long
int P;
int temp[505];
signed main()
{
    cin >> P;
    int num = ceil(P * log10(2));
    cout << num << '\n';
    temp[0] = 1;
    while (P > 0)
    {
        int t = 0;
        for (int i = 0; i < 500; i ++)
        {
            if (P > 40) temp[i] <<= 40;
            else temp[i] <<= P;
            temp[i] += t;
            t = temp[i] / 10;
            temp[i] %= 10;
        }
        P -= 40;
    }
    temp[0] -= 1;
    int n = 0;
    for (int i = 499; i >= 0; i --)
    {
        cout << temp[i];
        n ++;
        if (n == 50) cout << '\n', n = 0;
    }
    system("pause");
    return 0;
    
}