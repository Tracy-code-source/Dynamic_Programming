//https://www.luogu.com.cn/problem/P1014
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int floor = 1;
    while (N > floor)
    {
        N -= floor;
        floor ++;
    }
    if (floor % 2 == 0)
    {
        cout << N << '/' << floor + 1 - N << '\n';
    }
    else 
    {
        cout << floor + 1 - N << '/' << N << '\n';
    }
    system("pause");
}