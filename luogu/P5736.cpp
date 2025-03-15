//https://www.luogu.com.cn/problem/P5736
#include <bits/stdc++.h>
#define len 10005
using namespace std;
int main()
{
    int n;
    cin >> n;
    int temp[len];
    int pre[len];
    for (int i = 0; i < n; i ++)
    {
        cin >> pre[i];
    }
    int j = 0;
    for (int i = 0; i < n; i ++)
    {
        int t = 1;
        for (int k = 1; k <= pre[i]; k ++)
        {
            if (pre[i] == 1) 
            {
                t = 0;
                break;
            }
            else if (pre[i] == 2)
            {
                temp[j] = pre[i];
                j ++;
                t = 0;
                break;
            }
            else if (pre[i] % k == 0 && pre[i] != k && k != 1)
            {
                t = 0;
                break;
            }
        }
        if (t == 1) 
        {
            temp[j] = pre[i];
            j ++;
        }
    }
    for (int i = 0; i < j ; i ++)
    {
        cout << temp[i] << ' ';
    }
    system("pause");
    return 0;
}