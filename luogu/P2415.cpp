//https://www.luogu.com.cn/problem/P2415
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long  num, sum = 0, n = 0;;
    while (cin >> num)
    {
        sum += num;
        n ++;
    }
    for (int i = 1; i <= n - 1; i ++)
    {
        sum *= 2;
    }
    cout << sum << '\n';
}