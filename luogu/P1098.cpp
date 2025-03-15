//https://www.luogu.com.cn/problem/P1098
#include <bits/stdc++.h>
using namespace std;
#define int long long
int p1, p2, p3;
char str[505], pre, af, la;
char change(char a)
{
    if (a >= 'a' && a <= 'z') a -= 32;
    return a;
}
void expand(int m, int k, int o)
{
    for (int i = 0; str[i] != '\0'; i ++)
    {
        pre = str[i], af = str[i + 1], la = str[i + 2];
        if (af == '-' && pre < la  && (pre >= '0' && la <= '9' || pre >= 'a' && la <= 'z'))
        {
            cout << pre;
            char temp;
            if (o == 1)
            {
                temp = str[i] + 1;
                while (temp < la)
                {
                    if (m == 1)
                    {
                        for (int i = 1; i <= k; i ++)
                        {
                            cout << temp;
                        }
                    }
                    if (m == 2)
                    {
                        for (int i = 1; i <= k; i ++)
                        {
                            cout << change(temp);
                        }
                    }
                    if (m == 3)
                    {
                        for (int i = 1; i <= k; i ++)
                        {
                            cout << '*';
                        }
                    }
                    temp ++;
                }
            }
            if (o == 2)
            {
                temp = str[i + 2] - 1;
                while (temp > pre)
                {
                    if (m == 1)
                    {
                        for (int i = 1; i <= k; i ++)
                        {
                            cout << temp;
                        }
                    }
                    if (m == 2)
                    {
                        for (int i = 1; i <= k; i ++)
                        {
                            cout << change(temp);
                        }
                    }
                    if (m == 3)
                    {
                        for (int i = 1; i <= k; i ++)
                        {
                            cout << '*';
                        }
                    }
                    temp --;
                }
            }
            i ++;
        }
        else cout << pre;
    }   
    
}
signed main()
{
    cin >> p1 >> p2 >> p3;
    cin >> str;
    expand(p1, p2, p3);
    cout << '\n';
    system("pause");
    return 0;
}