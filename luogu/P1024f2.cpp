#include <bits/stdc++.h>
using namespace std;
#define int long long
double a, b, c, d;
double x1, x2;
int num;
double fun(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
signed main()
{
    cin >> a >> b >> c >> d;
    for (double i = -100.00; i <= 100.00; i ++)
    {
        double left = i;
        double right = i + 1;
        x1 = fun(left);
        x2 = fun(right);
        if (x1 == 0.00) 
        {
            printf("%.2lf ", i);
            num ++;
        }
        if (x1 * x2 < 0)
        {
            while (right - left >= 0.001)
            {
                double middle = (left + right) / 2;
                if (fun(middle) * fun(right) <= 0)  left = middle;
                else right = middle;
            }
            printf("%.2lf ", right);
            num ++;
        }
        if (num == 3) break;
    }
    system("pause");
    return 0;
}
