//https://www.luogu.com.cn/problem/P5739
#include <bits/stdc++.h>
using namespace std;
int k(int n)
{
    if (n == 1) return 1;
    else return k(n - 1) * n;
}
int main()
{
    int n;
    cin >> n;
    int ret = k(n);
    cout << ret << '\n';
    system("pause");
    return 0;
}