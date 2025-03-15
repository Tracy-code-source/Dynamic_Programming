//https://www.luogu.com.cn/problem/P5742
#include <bits/stdc++.h>
using namespace std;
int member(int a, int b)
{
    return a + b;
}
struct In
{
    int ID;
    int score;
    int ex;
    float ret;
    int sum;
}student[1005];
void judge(struct In a)
{
    if (a.score + a.ex > 140 && a.score * 7 + a.ex * 3 >= 800)
    {
        cout << "Excellent" << '\n';
    }
    else cout << "Not excellent" << '\n';
}
int main() 
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        cin >> student[i].ID >> student[i].score >> student[i].ex;
        student[i].ret = student[i].score * 0.7 + student[i].ex * 0.3;
        student[i].sum = student[i].score + student[i].ex;
    }
    for (int i = 0; i < N; i ++)
    {
        judge(student[i]);
    }
    system("pause");
    return 0;
}