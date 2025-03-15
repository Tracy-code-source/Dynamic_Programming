//https://www.luogu.com.cn/problem/P2142
#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b;
int mark = 1, loc = 0;
int numa[10500], numb[10500];
int ans[10500];
bool compare(string a, string b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i --)
    {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}
void check(string a, string b)
{
    if (!compare(a, b)) 
    {
        mark = 0;
        cout << '-';
    }
}
signed main()
{
    cin >> a >> b;
    check(a, b);
    for (int i = 0; i < a.size(); i ++) numa[i] = a[a.size() - 1 - i] - '0';
    for (int i = 0; i < b.size(); i ++) numb[i] = b[b.size() - 1 - i] - '0';
    if (mark > 0)
    {
        for (int i = 0; i < max(a.size(), b.size()); i ++)
        {
            if (numa[i] >= numb[i]) ans[i] = numa[i] - numb[i];
            else 
            {
                numa[i + 1] -= 1;
                ans[i] = numa[i] + 10 - numb[i];
            }
        }
    }
    else 
    {
        for (int i = 0; i < max(a.size(), b.size()); i ++)
        {
            if (numb[i] >= numa[i]) ans[i] = numb[i] - numa[i];
            else 
            {
                numb[i + 1] -= 1;
                ans[i] = numb[i] + 10 - numa[i];
            }
        }
    }
    for (int i = 10499; i >= 0; i --)
    {
        if (ans[i] != 0) 
        {
            loc = i;
            break;
        }
    }
    for (int i = loc; i >= 0; i --) cout << ans[i];
    cout << '\n';
    system("pause");
    return 0;
}