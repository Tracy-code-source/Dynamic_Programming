//https://www.luogu.com.cn/problem/P1449
#include <bits/stdc++.h>
using namespace std;
#define int long long
stack <int> num;
string str;
int n;
signed main()
{
    cin >> str;
    for (int i = 0; str[i] != '@'; i ++)
    {
        if (str[i] != '.' && (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') && str[i + 1] != '.')
        {
            n = n * 10 + (str[i] - '0');
        }
        if (str[i] != '.' && (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') && str[i + 1] == '.')
        {
            n =  n * 10 + (str[i] - '0');
            num.push(n);
            n = 0;
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            if (str[i] == '+') num.push(a + b);
            if (str[i] == '-') num.push(b - a);
            if (str[i] == '*') num.push(a * b);
            if (str[i] == '/') num.push(b / a);
        }
    }
    cout << num.top() << '\n';
    system("pause");
    return 0;
}
