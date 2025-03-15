//https://www.luogu.com.cn/problem/P1012
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    return a + b > b + a;
}
int main()
{
    int n;
    cin >> n;
    string sum[25];
    for (int i = 0; i < n; i ++)
    {
        cin >> sum[i];
    }
    sort(sum, sum + n, cmp);
   for (int i = 0; i < n; i ++)
   {
        cout << sum[i];
   }
    system("pause");
    return 0;
}