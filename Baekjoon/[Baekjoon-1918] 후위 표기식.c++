#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push('(');
        else if (str[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else
            cout << str[i];
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}
