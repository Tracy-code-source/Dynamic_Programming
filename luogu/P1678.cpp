//https://www.luogu.com.cn/problem/P1678
#include <bits/stdc++.h>
using namespace std;
#define int long long
int m, n;
int uni[100005], score[100005];
int ans;
bool compare(int a, int b)
{
    return a < b;
}
signed main()
{
    cin >> m >> n;
    for(int i = 0;i<100005;i++) uni[i] = -100000000;
    for (int i = 1; i <= m; i ++) cin >> uni[i];
    for (int i = 1; i <= n; i ++) cin >> score[i];
    sort(uni + 1, uni + 1 + m, compare);
    for (int i = 1; i <= n; i ++)
    {
        int left = 1, right = m;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (uni[mid] > score[i]) right = mid - 1;
            else left = mid + 1;
        }
        int num = min(abs(score[i] - uni[left-1]),abs(score[i]-uni[right]));
        num = min(num,abs(score[i]-uni[right + 1]));
        ans += num; 
        //printf("ans=%d\n",ans);
    }
    cout << ans << '\n';
    system("pause");
    return 0;
}