//https://www.luogu.com.cn/problem/P1067
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, num;
signed main()
{
    cin >> n;
    for (int i = n; i >= 0; i --)
    {
        cin >> num;
        if (num)
        {
            if (i != n && num > 0) cout << "+";
            if (abs(num) > 1 || i == 0) cout << num;
            if (num == - 1 && i != 0) cout << "-";
            if (i > 1) cout << "x^"  << i;
            if (i == 1) cout << "x";
        }
    }
    cout << '\n';
    system("pause");
    return 0;
}