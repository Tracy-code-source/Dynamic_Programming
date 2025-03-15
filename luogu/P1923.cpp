//https://www.luogu.com.cn/problem/P1923
#include <bits/stdc++.h>//快排
using namespace std;
#define int long long
int n, k;
int sum;
int num[5000005];
int partition(int num[], int low, int high)
{
    int pivot = num[low];
    while (low < high)
    {
        while (low < high && num[high] >= pivot) high --;
        num[low] = num[high];
        while (low < high && num[low] <= pivot) low ++;
        num[high] = num[low];
    }
    num[low] = pivot;
    return low;
}
void quicksort(int num[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition(num, low, high);
        quicksort(num, low, pivotpos - 1);
        quicksort(num, pivotpos + 1, high);
    }
}
signed main()
{
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%lld", &num[i]);
    quicksort(num, 0, n - 1);
    printf("%lld\n", num[k]);
    system("pause");
    return 0;
}