//https://www.luogu.com.cn/problem/P1873
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
int tree[1000005];
int ans;
bool cmp(int a, int b)
{
    return a > b;
}
signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i ++) cin >> tree[i];
    int left = 0, right = 2e9;
    //sort(tree + 1, tree + 1 + N, cmp);
    while (left < right)
    {
        int mid = (left + right) / 2 + 1;
        int sum = 0;
        for (int i = 1; i <= N; i ++)
        {
            if (tree[i] > mid) sum += tree[i] - mid;
        }
        if (sum < M)
        {
            right = mid - 1;
        }
        else left = mid;
        //printf("left=%d,right=%d\n",left,right);
    }
    
    cout << left << '\n';
    system("pause");
}