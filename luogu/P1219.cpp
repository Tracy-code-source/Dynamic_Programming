//https://www.luogu.com.cn/problem/P1219
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int opy1[30], opy2[30], opy3[30], solution[20];
int mark;
void Save(int i, int j, int num)
{
    solution[i] = j;
    opy1[j] = num;
    opy2[i + j] = num;
    opy3[i - j + n] = num;
}
void dfs(int i)
{
    if (i > n)
    {
        mark ++;
        if (mark <= 3) 
        {
            for (int j = 1; j <= n; j ++) cout << solution[j] << ' ';
            cout << '\n';
        }
    }
    for (int j = 1; j <= n; j ++) 
    {
        if (opy1[j] == 1 || opy2[i + j] == 1 || opy3[i - j + n] == 1) continue;
        Save(i, j, 1);
        dfs(i + 1);
        Save(i, j, 0);
    }

}
signed main()
{
    cin >> n;
    dfs(1);
    cout << mark << '\n';
    system("pause");
    return 0;
}