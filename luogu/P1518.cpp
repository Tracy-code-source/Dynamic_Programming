//https://www.luogu.com.cn/problem/P1518
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mapp[15][15];
int minu, t;
int xc, yc, xf, yf;
signed main()
{
    for (int i = 0; i <= 11; i ++)
    {
        mapp[0][i] = 1;
        mapp[i][0] = 1;
        mapp[11][i] = 1;
        mapp[i][11] = 1;
    }
    for (int i = 1; i <= 10; i ++)
    {
        for (int j = 1; j <= 10; j ++)
        {
            char temp;
            cin >> temp;
            if (temp == '*') mapp[i][j] = 1;
            else if (temp == 'C') xc = i, yc = j;
            else if (temp == 'F') xf = i, yf = j;
        }
    }
    int foward1 = 0, foward2 = 0;
    for (int i = 1; i <= 1000000; i ++)
    {
        if (foward1 == 0)
        {
            if (xc - 1 >= 1 && mapp[xc - 1][yc] == 0) xc --;
            else foward1 ++;
        }
        else if (foward1 == 1) 
        {
            if (yc + 1 <= 10 && mapp[xc][yc + 1] == 0) yc ++;
            else foward1 ++;
        }
        else if (foward1 == 2)
        {
            if (xc + 1<= 10 && mapp[xc + 1][yc] == 0) xc ++;
            else foward1 ++;
        }
        else if (foward1 == 3)
        {
            if (yc - 1 >= 1 && mapp[xc][yc - 1] == 0) yc --;
            else foward1 = 0;
        }
        if (foward2 == 0)
        {
            if (xf - 1 >= 1 && mapp[xf - 1][yf] == 0) xf --;
            else foward2 ++;
        }
        else if (foward2 == 1) 
        {
            if (yf + 1 <= 10 && mapp[xf][yf + 1] == 0) yf ++;
            else foward2 ++;
        }
        else if (foward2 == 2)
        {
            if (xf + 1<= 10 && mapp[xf + 1][yf] == 0) xf ++;
            else foward2 ++;
        }
        else if (foward2 == 3)
        {
            if (yf - 1 >= 1 && mapp[xf][yf - 1] == 0) yf --;
            else foward2 = 0;
        }
        if (xc == xf && yc == yf)
        {
            minu = i;
            break;
        }
    }
    cout << minu << '\n';
    system("pause");
    return 0;
}