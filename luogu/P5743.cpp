//https://www.luogu.com.cn/problem/P5743
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ret = 1;
    for (int i = n; i > 1; i --)
    {
        ret = 2 * (ret + 1);
    }
    cout << ret << '\n';
    system("pause");
    return 0;
}