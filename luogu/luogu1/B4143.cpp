//https://www.luogu.com.cn/problem/B4143
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, y;
signed main()
{
    cin >> n >> x >> y;
    if (y > x)
    {
        if (y - x < n - (y - x)) cout << "Clockwise Loop\n";
        else if (y - x > n - (y - x)) cout << "Counter-clockwise Loop\n";
        else cout << '"' << "Wonderful" << '"' << '\n';
    }
    else 
    {
        if (abs(y - x) < n - abs(y - x)) cout << "Clockwise Loop\n";
        else if (abs(y - x) > n - abs(y - x)) cout << "Counter-clockwise Loop\n";
        else cout << '"' << "Wonderful" << '"' << '\n';
    }
    system("pause");
    return 0;
}