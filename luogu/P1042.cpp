//https://www.luogu.com.cn/problem/P1042
#include <bits/stdc++.h>
using namespace std;
#define int long long
int ph, lh;
char str[100010];
char temp;
int n;
void add(char a)
{
    if (a == 'W') ph ++;
    if (a == 'L') lh ++;
}
signed main()
{
    cin >> temp;
    for (n; temp != 'E'; n ++)
    {
        str[n] = temp;
        cin >> temp;
    }
    for (int i = 0; i < n; i ++)
    {
        add(str[i]);
        if ((ph >= 11 || lh >= 11) && abs(ph - lh) >= 2) 
        {
            cout << ph << ':' << lh << '\n';
            ph = 0;
            lh = 0;
        }
    }
    cout << ph << ':' << lh << '\n';
    ph = 0;
    lh = 0;
    cout << '\n';
    for (int i = 0; i < n; i ++)
    {
        add(str[i]);
        if ((ph >= 21 || lh >= 21) && abs(ph - lh) >= 2) 
        {
            cout << ph << ':' << lh << '\n';
            ph = 0;
            lh = 0;
        }
    }
    cout << ph << ':' << lh << '\n';
    ph = 0;
    lh = 0;
    system("pause");
    return 0;
}