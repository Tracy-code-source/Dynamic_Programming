//https://www.luogu.com.cn/problem/P2367
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, p;
int score[5000005];
int plusarray[5000005];
int minn = 9999999999;
bool compare(int a, int b)
{
    return a < b;
}
signed main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i ++) 
    {
        cin >> score[i];
        plusarray[i] = score[i] - score[i - 1];
    }
    for (int i = 1; i <= p; i ++)
    {
        int left, right, add;
        cin >> left >> right >> add;
        plusarray[left] += add;
        plusarray[right + 1] -= add;
    }
    for (int i = 1; i <= n; i ++)
    {
        plusarray[i] += plusarray[i - 1];
        minn = min(minn, plusarray[i]);
    }
    //sort(plusarray + 1, plusarray + 1 + n, compare);
    printf("%lld\n", minn);
    system("pause");
    return 0;
}