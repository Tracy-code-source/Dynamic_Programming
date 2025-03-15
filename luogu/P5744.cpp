//https://www.luogu.com.cn/problem/P5744
#include <bits/stdc++.h>
using namespace std;
struct In
{
    string name;
    int age;
    int score;
}student[6];
struct In Turn(struct In a)
{
    a.age += 1;
    a.score *= 1.2;
    if (a.score > 600) a.score = 600;
    return a;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> student[i].name >> student[i].age >> student[i].score;
    }
    for (int i = 0; i < n; i ++)
    {
        student[i] = Turn(student[i]);
        cout << student[i].name << ' ' << student[i].age << ' ' << student[i].score << '\n';
    }
    system("pause");
    return 0;
}