//https://www.luogu.com.cn/problem/P5735
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double len[3];
    double xs[3];
    double ys[3];
    for (int i = 0; i < 3; i ++)
    {
        cin >> xs[i] >> ys[i];
    }
    len[0] = sqrt((xs[0] - xs[1]) * (xs[0] - xs[1]) + (ys[0] - ys[1]) * (ys[0] - ys[1]));
    len[1] = sqrt((xs[0] - xs[2]) * (xs[0] - xs[2]) + (ys[0] - ys[2]) * (ys[0] - ys[2]));
    len[2] = sqrt((xs[2] - xs[1]) * (xs[2] - xs[1]) + (ys[2] - ys[1]) * (ys[2] - ys[1]));
    double l = len[0] + len[1] + len[2];
    printf("%.2lf", l);
    system("pause");
    return 0;
}