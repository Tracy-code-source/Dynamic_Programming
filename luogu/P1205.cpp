//https://www.luogu.com.cn/problem/P1205
#include <bits/stdc++.h>
using namespace std;
#define int long long
char pre[15][15];
char need[15][15];
char change[15][15];
char C[15][15];
int n;
int ans;
void change1()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            change[j][n + 1 - i] = pre[i][j];
        }
    }
}
void change2()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            change[n + 1 - i][n + 1 - j] = pre[i][j];
        }
    }
}
void change3()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            change[n + 1 - j][i] = pre[i][j];
        }
    }
}
void change4()
{
    //if (n % 2 != 0) int mid = n / 2 + 1;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            change[i][n + 1 - j] = pre[i][j];
        }
    }
}
void change5()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            change[i][j] = pre[i][j];
        }
    }
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            cin >> pre[i][j];
        }
    }
    //cout << '\n';
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            cin >> need[i][j];
        }
    }
    //cout << '\n';
    for (int i = 1; i <= 7; i ++)
    {
        if (i == 1)
        {
            change1();
            int t = 1;
            for (int j = 1; j <= n; j ++)
            {
                for (int k = 1; k <= n; k ++)
                {
                    if (change[j][k] != need[j][k])
                    {
                        t = 0;
                        break;
                    }
                }
                if (t == 0) break;
            }
            /*cout << t << '\n';
            for (int j = 1; j <= n; j ++)
            {
                for (int k = 1; k <= n; k ++)
                {
                    change[i][j];
                }
                cout << '\n';
            }*/
            if (t == 1)
            {
                ans = i;
                break;
            }
        }
        if (i == 2)
        {
            change2();
            int t = 1;
            for (int j = 1; j <= n; j ++)
            {
                for (int k = 1; k <= n; k ++)
                {
                    if (change[j][k] != need[j][k])
                    {
                        t = 0;
                        break;
                    }
                }
                if (t == 0) break;
            }
            if (t == 1)
            {
                ans = i;
                break;
            }
        }
        if (i == 3)
        {
            change3();
            int t = 1;
            for (int j = 1; j <= n; j ++)
            {
                for (int k = 1; k <= n; k ++)
                {
                    if (change[j][k] != need[j][k])
                    {
                        t = 0;
                        break;
                    }
                }
                if (t == 0) break;
            }
            if (t == 1)
            {
                ans = i;
                break;
            }
        }
        if (i == 4)
        {
            change4();
            int t = 1;
            for (int j = 1; j <= n; j ++)
            {
                for (int k = 1; k <= n; k ++)
                {
                    if (change[j][k] != need[j][k])
                    {
                        t = 0;
                        break;
                    }
                }
                if (t == 0) break;
            }
            if (t == 1)
            {
                ans = i;
                break;
            }
        }
        if (i == 5)
        {
            int m = 0;
            for (int a = 1; a <= 3; a ++)
            {
                change4();
                if (a == 1) 
                {
                    for (int j = 1; j <= n; j ++)
                    {
                        for (int k = 1; k <= n; k ++)
                        {
                            C[k][n + 1 - j] = change[j][k];
                        }
                    }
                    int t = 1;
                for (int j = 1; j <= n; j ++)
                {
                    for (int k = 1; k <= n; k ++)
                    {
                        if (C[j][k] != need[j][k])
                        {
                            t = 0;
                            break;
                        }
                    }
                    if (t == 0) break;
                }
                if (t == 1)
                {
                    ans = i;
                    m = 1;
                    break;
                }
                }
                if (a == 2) 
                {
                    int t = 1;
                    for (int j = 1; j <= n; j ++)
                    {
                        for (int k = 1; k <= n; k ++)
                        {
                            C[n + 1 - j][n + 1 - k] = change[j][k];
                        }
                    }
                    for (int j = 1; j <= n; j ++)
                    {
                        for (int k = 1; k <= n; k ++)
                        {
                            if (C[j][k] != need[j][k])
                            {
                                t = 0;
                                break;
                            }
                        }
                        if (t == 0) break;
                    }
                    if (t == 1)
                {
                    ans = i;
                    m = 1;
                    break;
                }
                }
                if (a == 3) 
                {
                    int t = 1;
                    for (int j = 1; j <= n; j ++)
                    {
                        for (int k = 1; k <= n; k ++)
                        {
                            C[n + 1 - k][j] = change[j][k];
                        }
                    }
                    for (int j = 1; j <= n; j ++)
                    {
                        for (int k = 1; k <= n; k ++)
                        {
                            if (C[j][k] != need[j][k])
                            {
                                t = 0;
                                break;
                            }
                        }
                        if (t == 0) break;
                    }
                    if (t == 1)
                {
                    ans = i;
                    m = 1;
                    break;
                }
                }
            }
            if (m == 1) break;
        }
        if (i == 6) 
        {
            change5();
            int t = 1;
            for (int j = 1; j <= n; j ++)
            {                    
                for (int k = 1; k <= n; k ++)
                {
                    if (change[j][k] != need[j][k])
                    {
                        t = 0;
                        break;
                    }
                }
                if (t == 0) break;
            }
            if (t == 1)
            {
                ans = i;
                break;
            }
        }
        if (i == 7) ans = i;
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}