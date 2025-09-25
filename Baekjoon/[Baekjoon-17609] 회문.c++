#include <iostream>
#include <string>
using namespace std;

int t;
string str;

int par(int left, int right, int flag)
{
    int tmp;

    if (left > right)
    {
        if (flag == 0)
            return 1;
        else
            return 0;
    }

    if (str[left] == str[right])
        tmp = par(left + 1, right - 1, flag);
    else
    {
        if (flag == 0)
            return 2;
        else
            tmp = min(par(left + 1, right, 0), par(left, right - 1, 0));
    }

    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t-- > 0)
    {
        cin >> str;

        cout << par(0, str.length() - 1, 1) << "\n";
    }

    return 0;
}
