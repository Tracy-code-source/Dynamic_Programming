//https://www.luogu.com.cn/problem/P5738
#include <bits/stdc++.h>
using namespace std;
double bubblesort(int* a, int m)
{
    int sum = 0;
    int minn = 999999, maxn = 0;
    for (int i = 0; i < m ; i ++)
    {
        minn = min(a[i], minn);
        maxn = max(a[i], maxn);
        sum += a[i];
    }
    sum -= minn + maxn;
    return sum / (float)(m - 2);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int con[n][m];
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cin >> con[i][j];
        }
    }
    double max[n];
    for (int i = 0; i < n; i ++)
    {
        max[i] = bubblesort(con[i], m);
    }
    double ret = 0.0;
    for (int i = 0; i < n; i ++)
    {
        if (max[i] > ret) ret = max[i];
    }
    printf("%.2lf", ret);
    system("pause");
    return 0;
}