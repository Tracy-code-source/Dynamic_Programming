//https://www.luogu.com.cn/problem/P5587
#include <bits/stdc++.h>
using namespace std;
string del(string str)
{
    int i = 0;
    string temp;
    for (i = 0; i < str.size(); i ++)
    {
        if (str[i] != '<') temp += str[i];
        else if (!temp.empty()) temp.pop_back();
    }
    return temp;
}
int main()
{
    string exa;
    string sum[10005];
    getline(cin, exa);
    int i = 0;
    while (exa != "EOF")
    {
        sum[i] = del(exa);
        i ++;
        getline(cin, exa);
    }
    /*for (int j = 0; j < i; j ++)
    {
        cout << sum[j] << '\n';
    }*/
   string write[10005];
   string mine;
   getline(cin, mine);
   int j = 0;
   while (mine != "EOF")
   {
        write[j] = del(mine);
        j ++;
        getline(cin, mine);
   }
   int T;
   cin >> T;
   int num = 0;
   int minn = min(i, j);
   for (int i = 0; i < minn; i ++)
   {
        for (int t = 0; sum[i][t] != '\0' && write[i][t] != '\0'; t ++)
        {
            if (sum[i] [t] == write[i][t]) num ++;
        }
   }
   double kpm = 1.0000 * num / T;
   kpm *= 60;
   int ret = floor(kpm);
   double test = ret + 0.500001;
   if (kpm > test) ret += 1;
   cout << ret << '\n';
    system("pause");
}