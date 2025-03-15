//https://www.luogu.com.cn/problem/P5737
#include <bits/stdc++.h>
#define len 1000
using namespace std;
void leap(int a, int b)
{
    int num = 0;
    int sum[len];
    int j = 0;
    for (int i = a; i <= b; i ++)
    {
        int n = 0;
        if (i % 4 == 0)
        {
            if (i % 100 != 0) n ++;
        }
        if (i % 100 == 0)
        {
            if (i % 400 == 0) n ++;
        }
        if (n > 0)
        {
            num ++;
            sum[j] = i;
            j ++;
        }
    }
    cout << num << '\n';
    for (int i = 0; i < num; i ++)
    {
        cout << sum[i] << ' ';
    }
}
int main()
{
    int x, y;
    cin >> x >> y;
    leap(x, y);
    system("pause");
    return 0;
}
