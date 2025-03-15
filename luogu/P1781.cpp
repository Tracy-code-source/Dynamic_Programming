//https://www.luogu.com.cn/problem/P1781
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string p;
struct In
{
    int num;
    string point;
}member[25];
bool cmp(struct In a, struct In b)
{
    if (a.point.size() != b.point.size()) return a.point.size() > b.point.size();
    else return a.point > b.point;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> member[i].point;
        member[i].num = i;
    }
    sort(member + 1, member + 1 + n, cmp);
    cout << member[1].num << '\n' << member[1].point << '\n';
    system("pause");
    return 0;
}