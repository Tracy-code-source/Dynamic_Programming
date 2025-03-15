//https://www.luogu.com.cn/problem/P5741
#include <bits/stdc++.h>
#define len 1005
using namespace std;
struct In
{
    string name;
    int ch;
    int ma;
    int En;
}student[len];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        cin >> student[i].name >> student[i].ch >> student[i].ma >> student[i].En;
    }
    int k = 0;
    for (int i = 0; i < N; i ++)
    {
        for (int j = i + 1; j <= N - 1; j ++)
        {
            if (abs(student[i].ch - student[j].ch)  <= 5)
            {
                if (abs(student[i].ma - student[j].ma) <= 5)
                {
                    if (abs(student[i].En - student[j].En) <= 5)
                    {
                        if (abs(student[i].ch + student[i].ma + student[i].En - (student[j].ch + student[j].ma + student[j].En)) <= 10)
                        {
                            if (student[i].name > student[j].name) cout << student[j].name << ' ' << student[i].name << '\n';
                            else cout << student[i].name << ' ' << student[j].name << '\n';
                        }
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}