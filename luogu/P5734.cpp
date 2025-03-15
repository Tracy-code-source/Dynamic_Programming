//https://www.luogu.com.cn/problem/P5734
#include <iostream>
#include <string>
using namespace std;

constexpr int len = 100;

int main() {
    int q;
    string source;
    cin >> q;
    cin >> source;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        if (n == 1)
            {
                string temp;
                cin >> temp;
                source += temp;
                cout << source << '\n';
                continue;
            }
        if (n == 2)
            {
                int a, b;
                cin >> a >> b;
                string extracted = source.substr(a, b);
                //cout << extracted << '\n';
                source = extracted;
                cout << source << '\n';
                continue;
            }
        if (n == 3)
            {
                int pos;
                cin >> pos;
                string replaceStr;
                cin >> replaceStr;
                source.insert(pos,replaceStr);
                cout << source << '\n';
                continue;
            }
        if (n == 4)
            {
                string searchStr;
                cin >> searchStr;
                size_t found = source.find(searchStr);
                if (found != string::npos) {
                    cout << found << '\n';
                } else {
                    cout << "-1" << '\n';
                }
            }  
            
        }
        system("pause");
         return 0;
    }
