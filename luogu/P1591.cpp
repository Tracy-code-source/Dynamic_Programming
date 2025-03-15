//https://www.luogu.com.cn/problem/P1591
#include <bits/stdc++.h>
using namespace std;
int t, n, a;
int temp[2600];
signed main()
{
    cin >> t;
    for (int i = 1; i <= t; i ++)
    {
        cin >> n >> a;
        temp[0] = 1;
        for (int k = 1; k <= n; k ++)
        {
            for (int j = 0; j < 2599; j ++) temp[j] *= k;
            for (int j = 0; j < 2599; j ++)
            {
                if (temp[j] >= 10)
                {
                    temp[j + 1] += temp[j] / 10;
                    temp[j] %= 10;
                }
            }
        }
        int num = 0;
        int loc = -1;
        for (int k = 2599; k >= 0; k --)
        {
            if (temp[k] != 0)
            {
                loc = k;
                break;
            }
        }
        for (int k = loc; k >= 0; k --)
        {
            if (a == temp[k]) num ++;
        }
        cout << num << '\n';
        memset(temp, 0, sizeof(temp));
    }
    system("pause");
    return 0;
}