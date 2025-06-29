#include <iostream>
#include <queue>
using namespace std;

deque<int> dq;
int robot[100];
int ans, cnt;

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n * 2; i++)
    {
        int tmp;
        cin >> tmp;
        dq.push_back(tmp);
    }

    while (cnt < k)
    {
        ans++;

        int tmp = dq.back();
        dq.pop_back();
        dq.push_front(tmp);
        for (int i = n - 1; i > 0; i--)
        {
            robot[i] = robot[i - 1];
        }
        robot[0] = 0, robot[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            if (robot[i] == 1 && robot[i + 1] != 1 && dq[i + 1] != 0)
            {
                robot[i + 1] = 1;
                robot[i] = 0;
                if (--dq[i + 1] == 0)
                    cnt++;
            }
        }
        robot[n - 1] = 0;

        if (dq[0] != 0)
        {
            robot[0] = 1;
            if (--dq[0] == 0)
                cnt++;
        }
    }

    cout << ans;

    return 0;
}
