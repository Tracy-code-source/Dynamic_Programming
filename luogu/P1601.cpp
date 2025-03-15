//https://www.luogu.com.cn/problem/P1601
#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,  b;
int len;
int al[100000], bl[100000], cl[100000];
signed main()
{
    cin >> a >> b;
    for (int i = 0; i < a.size(); i ++)
    {
        al[a.size() - i - 1] = a[i] - '0';
    }
    for (int i = 0; i < b.size(); i ++)
    {
        bl[b.size() - i - 1] = b[i] - '0';
    }
    len = max(a.size(), b.size()); 
    for (int i = 0; i < len; i ++)
    {
        cl[i] = al[i] + bl[i];
    }
    for (int i = 0; i < len; i ++)
    {
        if (cl[i] >= 10)
        {
            cl[i + 1] += cl[i] / 10;
            cl[i] %= 10;
        }
    }
    if (cl[len] != 0) len ++;
    for (int i = len - 1; i >= 0; i --) cout << cl[i];
    cout << '\n';
    system("pause");
    return 0;
}