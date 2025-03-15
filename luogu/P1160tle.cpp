//https://www.luogu.com.cn/problem/P1160
#include <bits/stdc++.h>
using namespace std;
#define int long long
queue <int> m;
int N, M;
int loc[100005], dir[100005], del[100005];
signed main()
{
    cin >> N;
    m.push(1);
    for (int i = 2; i <= N; i ++)
    {
        cin >> loc[i];
        cin >> dir[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i ++) cin >> del[i];
    for (int i = 2; i <= N; i ++)
    {
        int len = m.size();
        //cout << len << '\n';
        if (dir[i] == 0)
        {
            while (m.front() != loc[i])
            {
                m.push(m.front());
                m.pop();
                len --;
            }
            m.push(i);
            while (len > 0)
            {
                m.push(m.front());
                m.pop();
                len --;
            }
        }
        else 
        {
            while (m.front() != loc[i])
            {
                m.push(m.front());
                m.pop();
                len --;
            }
            m.push(m.front());
            m.pop();
            len --;
            m.push(i);
            while (len > 0)
            {
                m.push(m.front());
                m.pop();
                len --;
            }
        }
    }
    for (int i = 1; i <= M; i ++)
    {
        int len = m.size();
        while (m.front() != del[i] && len > 0)
        {
            m.push(m.front());
            m.pop();
            len --;
        }
        if (m.front() == del[i])
        {
            m.pop();
            len --;
        }
        while (len > 0)
        {
            m.push(m.front());
            m.pop();
            len --;
        }
    }
    while (!m.empty())
    {
        cout << m.front() << ' ';
        m.pop();
    }
    system("pause");
    return 0;
}