//https://www.luogu.com.cn/problem/P1309
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, R, Q;
struct DATA
{
    int point;
    int power;
    int ID;
}player[100005];
int judge(struct DATA a, struct DATA b)
{
    if (a.power > b.power) return 1;
    else return 0;
}
bool cmp(struct DATA a, struct DATA b)
{
    if (a.point != b.point) return a.point > b.point;
    else return a.ID < b.ID;
}
signed main()
{
    cin >> N >> R >> Q;
    for (int i = 1; i <= N * 2; i ++)
    {
        cin >> player[i].point;
        player[i].ID = i;
    }
    for (int i = 1; i <= N * 2; i ++)
    {
        cin >> player[i].power;
    }
    sort(player + 1, player + 2 * N + 1, cmp);
    for (int i = 1; i <= R; i ++)
    {
        for (int j = 1; j <= N * 2; j + 2)
        {
            if (judge(player[j], player[j + 1]) == 1) player[j].point ++;
            else player[j].point ++;
        }
        sort(player + 1, player + 2 * N + 1, cmp);
    }
    sort(player + 1, player + 2 * N + 1, cmp);
    cout << player[Q].ID << '\n';
    system("pause");
    return 0;
}