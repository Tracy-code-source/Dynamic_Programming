//https://www.luogu.com.cn/problem/P1328
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int N, NA, NB;
string SA[205], SB[205];
int AP, BP;
void fight(string a, string b)
{
    if (a == "0")
    {
        if (b == "0") AP += 0;
        if (b == "1") BP ++;
        if (b == "2" || b == "3") AP ++;
        if (b == "4") BP ++;
    }
    if (a == "1")
    {
        if (b == "0" || b == "3") AP ++;
        if (b == "1") AP += 0;
        if (b == "2" || b == "4") BP ++;
    }
    if (a == "2")
    {
        if (b == "0" || b == "3") BP ++;
        if (b == "2") AP += 0;
        if (b == "1" || b == "4") AP ++;
    }
    if (a == "3")
    {
        if (b == "0" || b == "1") BP ++;
        if (b == "3") AP += 0;
        if (b == "2" || b == "4") AP ++;
    }
    if (a == "4")
    {
        if (b == "0" || b == "1") AP ++;
        if (b == "4") AP += 0;
        if (b == "2" || b == "3") BP ++;
    }
}
signed main()
{
    cin >> N >> NA >> NB;
    string ta[NA];
    for (int i = 0; i < NA; i ++)
    {
        cin >> ta[i];
    }
    for (int i = 0; i < 205; i ++)
    {
        SA[i] = ta[i % NA];
    }
    string tb[NB];
    for (int i = 0; i < NB; i ++)
    {
        cin >> tb[i];
    }
    for (int i = 0; i < 205; i ++)
    {
        SB[i] = tb[i % NB];
    }
    for (int i = 0; i < N; i ++)
    {
        fight(SA[i], SB[i]);
    }
    cout << AP << ' ' << BP << '\n';
    system("pause");
    return 0;
}
