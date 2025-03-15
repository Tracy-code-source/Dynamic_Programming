//https://www.luogu.com.cn/problem/P1308
#include <bits/stdc++.h>
#define len 100005
using namespace std;

int main()
{
    string word;
    cin >> word;
    word = ' ' + word + ' ';
    getchar();
    for (int i = 0; i < word.size(); i ++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
    }
    string article;
    getline(cin, article);
    article = ' ' + article + ' ';
    int fir = 9999999;
    int n = 0;
    for (int i = 0; i < article.size(); i ++)
    {
        if (article[i] >= 'A' && article[i] <= 'Z') article[i] += 32;
    }
    for (int i = 0; i < (int)article.size(); i ++)
    {
        if (article.substr(i, word.size()) == word)
        {
            fir = min(fir, i);
            n ++;
        }
    }
    if (n == 0) cout << "-1" << '\n';
    else cout << n << ' ' << fir << '\n';
    system("pause");
}