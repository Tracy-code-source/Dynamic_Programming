//https://www.luogu.com.cn/problem/P1618
#include <bits/stdc++.h>
using namespace std;
#define int long long
int A, B, C;
int num;
struct D
{
    int x, y, z;
}n[10005];
int judge(int a)
{
    int t1 = a / 100;
    int t2 = (a / 10) % 10;
    int t3 = a % 10;
    if (t1 == 1 || t1 == 2 || t1 == 3 || t1 == 4 || t1 == 5 || t1 == 6 || t1 == 7 || t1 == 8 || t1 == 9)
    {
        if (t2 == 1 || t2 == 2 || t2 == 3 || t2 == 4 || t2 == 5 || t2 == 6 || t2 == 7 || t2 == 8 || t2 == 9)
        {
            if (t3 == 1 || t3 == 2 || t3 == 3 || t3 == 4 || t3 == 5 || t3 == 6 || t3 == 7 || t3 == 8 || t3 == 9)
            {
                return 1;
            }  
        }
    }
    return 0;
}
signed main()
{
    cin >> A >> B >> C;
    if (A == 0)
    {
        cout << "No!!!" << '\n';
        return 0;
    }
    else
    {
        for (int i = 123; i <= 987; i ++)
        {
            if (i % 10 == 0 || (i / 10) % 10 == 0 || i % 10 == 0) continue;
            int k1 = i / 100, k2 = (i / 10) % 10, k3 =  i % 10;
            if (k1 == k2 || k1 == k3 || k2 == k3) continue;
            if (i % A != 0) continue;
            int num2 = i / A * B, num3 = i / A * C;
            if (num2 / 100 == k1 || (num2 / 10) % 10 == k1 || num2 % 10 == k1 || num2 / 100 == k2 || (num2 / 10) % 10 == k2 || num2 % 10 == k2 || num2 / 100 == k3 || (num2 / 10) % 10 == k3 || num2 % 10 == k3) continue;
            int k4 = num2 / 100, k5 = (num2 / 10) % 10, k6 = num2 % 10;
            if (k4 == k5 || k4 == k6 || k5 == k6) continue;
            if (num3 / 100 == k1 || (num3 / 10) % 10 == k1 || num3 % 10 == k1 || num3 / 100 == k2 || (num3 / 10) % 10 == k2 || num3 % 10 == k2 || num3 / 100 == k3 || (num3 / 10) % 10 == k3 || num3 % 10 == k3) continue;
            else if (num3 / 100 == k4 || (num3 / 10) % 10 == k4 || num3 % 10 == k4 || num3 / 100 == k5 || (num3 / 10) % 10 == k5 || num3 % 10 == k5 || num3 / 100 == k6 || (num3 / 10) % 10 == k6 || num3 % 10 == k6) continue;
            int k7 = num3 / 100, k8 = (num3 / 10) % 10, k9 = num3 % 10;
            if (k7 == k8 || k7 == k9 || k8 == k9) continue;
            if (judge(num2) != 0 && judge(num3) != 0)
            {
                n[num].x = i;
                n[num].y = num2;
                n[num].z = num3;
                num ++;
            }
        }
    }
    if (num == 0) cout << "No!!!" << '\n';
    else 
    {
        for (int i = 0; i < num; i ++)
        {
            cout << n[i].x << ' ' << n[i].y << ' ' << n[i].z << '\n';
        }
    }
    system("pause");
    return 0;

}