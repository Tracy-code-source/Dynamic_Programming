//https://www.luogu.com.cn/problem/P5740
#include <bits/stdc++.h>
#define len 1005
using namespace std;
struct In
{
    string name;
    int Chinese;
    int math;
    int English;
}student[len];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        cin >> student[i].name;
        cin >> student[i].Chinese;
        cin >> student[i].math;
        cin >> student[i].English;
    }
    struct In best;
    best.Chinese = 0;
    best.math = 0;
    best.English = 0;
    int j = 0, t = 0;
    int max = 0;
    for (int i = 0; i  < N; i ++)
    {
        if (student[i].Chinese + student[i].math + student[i].English == 0 && t == 0) 
        {
            best.name = student[i].name;
            t = 1;
        }
        if (student[i].Chinese + student[i].math + student[i].English > max)
        {
            max = student[i].Chinese + student[i].math + student[i].English;
            best.name = student[i].name;
            best.Chinese = student[i].Chinese;
            best.math = student[i].math;
            best.English = student[i].English;
        }
    }
    cout << best.name << ' ' << best.Chinese << ' ' << best.math << ' ' << best.English << '\n';
    system("pause");
    return 0;
}