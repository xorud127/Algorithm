#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int city[11], visit[11];
bool selected[11];
vector<int> v[11];
int s, ans = 987654321;

bool connection(vector<int> a, bool t)
{
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    q.push(a[0]);
    visit[a[0]] = 1;
    int cnt = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];

            if (selected[y] == t && visit[y] == 0)
            {
                visit[y] = 1;
                cnt++;
                q.push(y);
            }
        }
    }

    if (a.size() == cnt)
        return 1;
    return 0;
}

bool check(int n)
{
    vector<int> a, b;
    for (int i = 1; i <= n; i++)
        if (selected[i] == 1)
            a.push_back(i);
        else
            b.push_back(i);

    if (a.size() == 0 || b.size() == 0)
        return 0;

    bool aState = connection(a, 1);
    if (aState == 0)
        return 0;

    bool bState = connection(b, 0);
    if (bState == 0)
        return 0;

    return 1;
}

void calc(int n)
{
    int aNum, BNum, diff;
    aNum = BNum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (selected[i] == 1)
            aNum += city[i];
        else
            BNum += city[i];
    }

    diff = abs(aNum - BNum);
    ans = min(ans, diff);
}

void dfs(int n, int idx, int cnt)
{
    if (cnt >= 1)
    {
        if (check(n) == 1)
            calc(n);
    }

    for (int i = idx; i <= n; i++)
    {
        if (selected[i] == 1)
            continue;
        selected[i] = 1;
        dfs(n, i, cnt + 1);
        selected[i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> city[i];
        s += city[i];
    }
    ans = s;

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    dfs(n, 1, 0);

    if (ans == s)
        cout << -1;
    else
        cout << ans;

    return 0;
}
