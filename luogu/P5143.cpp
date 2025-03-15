//https://www.luogu.com.cn/problem/P5143
#include <bits/stdc++.h>
using namespace std;
#define int long long
double s;
int N;
struct loc
{
    int x, y, z;
}mp[50005];
bool cmp(struct loc a, struct loc b)
{
    return a.z > b.z;
}
signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i ++)
    {
        cin >> mp[i].x >> mp[i].y >> mp[i].z;     
    }
    sort(mp + 1, mp + 1 + N, cmp);
    struct loc last = mp[1];
    for (int i = 2; i <= N; i ++)
    {
        double X = (mp[i].x - last.x) * (mp[i].x - last.x);
        double Y = (mp[i].y - last.y) * (mp[i].y - last.y);
        double Z = (mp[i].z - last.z) * (mp[i].z - last.z);
        s += sqrt(X + Y + Z);
        last = mp[i];
    }
    printf("%.3lf\n", s);
    system("pause");
    return 0;
}