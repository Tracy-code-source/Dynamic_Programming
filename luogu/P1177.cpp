//https://www.luogu.com.cn/problem/P1042
#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool cmp(int a, int b)
{
    return a < b;
}
int N;
int num[100005];
signed main()
{
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        cin >> num[i];
    }
    sort(num, num + N, cmp);
    for (int i = 0; i < N; i ++)
    {
        cout << num[i] << ' ';
    }
    system("pause");
    return 0;
}