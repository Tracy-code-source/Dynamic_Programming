//https://www.luogu.com.cn/problem/T573802?contestId=228622
#include <bits/stdc++.h>
using namespace std;
#define int long long
int ve, vm, vt, vkk;
int e, m, t;
signed main()
{
    cin >> ve >> vm >> vt;
    cin >> e >> m >> t;
    vkk = e * ve + m * vm;
    int num = vkk / vt ;
    if (vkk % vt != 0) num ++;
    if (num % t != 0) num = num / t + 1;
    else num = num / t;
    cout << num << '\n';
    system("pause");
    return 0;
}