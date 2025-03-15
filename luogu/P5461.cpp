//https://www.luogu.com.cn/problem/P5461
#include <bits/stdc++.h>
using namespace std;
int num[1030][1030];
void secure(int x, int y, int n)
{
    if (n == 0) return ;
    for (int i = x; i < x + ((1 << (n - 1))); i ++)
    {
        for (int j = y; j < y + ((1 << (n - 1))); j ++)
        {
            num[i][j] = 0;
        }
    }
    secure(x + (1 << (n - 1)), y, n - 1);
    secure(x, y + (1 << (n - 1)), n - 1);
    secure(x + (1 << (n - 1)), y + (1 << (n - 1)), n - 1);
}
int main()
{
    for (int i = 0; i < 1030; i ++)
    {
        for (int j = 0; j < 1030; j ++)
        {
            num[i][j] = 1;
        }
    }
    int n;
    cin >> n;
    secure(0, 0, n);
    for (int i = 0; i < (1 << n); i ++)
    {
        for (int j = 0; j < (1 << n); j ++)
        {
            cout << num[i][j] << ' ';
        }
        cout << '\n';
    }
    system("pause");
    return 0;
}