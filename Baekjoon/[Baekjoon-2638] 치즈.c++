#include <iostream>
#include <queue>
using namespace std;

int paper[100][100], visit[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfsAir(int n, int m, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[y][x] = 1;

    while (!q.empty())
    {
        int x_now = q.front().first;
        int y_now = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x_next = x_now + dx[i];
            int y_next = y_now + dy[i];

            if (x_next >= 0 && x_next < m && y_next >= 0 && y_next < n)
            {
                if (visit[y_next][x_next] == 0 && paper[y_next][x_next] == 0)
                {
                    visit[y_next][x_next] = 1;
                    q.push({x_next, y_next});
                }
            }
        }
    }
}

bool check(int n, int m, int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int x_next = x + dx[i];
        int y_next = y + dy[i];

        if (x_next >= 0 && x_next < m && y_next >= 0 && y_next < n)
        {
            if (visit[y_next][x_next] == 1)
                cnt++;
        }
    }
    if (cnt >= 2)
        return 1;
    else
        return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> paper[i][j];
        }
    }

    int cnt = 0;
    queue<pair<int, int>> q;
    while (1)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visit[i][j] = 0;
        bfsAir(n, m, 0, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (paper[i][j] == 1 && check(n, m, j, i))
                {
                    q.push({j, i});
                }
            }
        }

        if (!q.empty())
        {
            cnt++;
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                paper[y][x] = 0;
            }
        }
        else
        {
            cout << cnt;
            break;
        }
    }

    return 0;
}