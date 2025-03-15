//https://www.luogu.com.cn/problem/B3630
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, fir;
struct In
{
    int index = 0;
    int ID;
    int behind;
}student[2000005];
int ind[2000005];
int boo[2000005];
int num = 1;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) 
    {
        cin >> student[i].behind;
        student[i].ID = i;
        boo[student[i].behind] = 1;
    }
    cin >> fir;
    for (int i = 1; i <= n; i ++)
    {
        if (boo[i] == 0) 
        {
            student[i].index = fir;
            ind[num] = student[i].ID;
        }
        
    }
    //student[1].index = fir;
    int prev = fir;
    //while (student[prev].ID != 1) prev ++;
    while (student[prev].behind != 0)
    {
        student[student[prev].behind].index = student[prev].index + 1;
        ind[++num] = student[student[prev].behind].ID;
        prev = student[prev].behind;
    }
    for (int i = 1; i <= n; i ++)
    {
        cout << ind[i] << ' ';
    }
    cout << '\n';
    system("pause");
    return 0;
}