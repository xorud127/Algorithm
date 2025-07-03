#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int> mx, mn;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if (mx.size() == mn.size())
            mx.push(tmp);
        else
            mn.push(-tmp);

        if (!mx.empty() && !mn.empty() && mx.top() > -(mn.top()))
        {
            int swap1 = mx.top(), swap2 = -mn.top();
            mx.pop();
            mn.pop();
            mx.push(swap2);
            mn.push(-swap1);
        }

        cout << mx.top() << "\n";
    }

    return 0;
}
