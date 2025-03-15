//https://www.luogu.com.cn/problem/P5594
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int num[n][m];
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0 ; j < m; j ++)
        {
            cin >> num[i][j];
        }
    }
    int couch[k + 1];
    for (int i = 1; i <= k; i ++)
    {
        couch[i] = 0;
    }
    int ap[1000];
    for (int i = 1; i <= 999; i ++)
    {
        ap[i] = 0;
    }
    for (int j = 0; j < m; j ++)
    {
        for (int i = 0; i < n; i ++)
        {
            ap[num[i][j]] ++;
        }
        for (int i = 1; i <= k; i ++)
        {
            if (ap[i] > 0) couch[i] ++;
        }
        for (int i = 1; i <= 999; i ++)
        {
            ap[i] = 0;
        }
    }
    for (int i = 1; i <= k; i ++)
    {
        cout << couch[i] << ' ';
    }
    system("pause");
}