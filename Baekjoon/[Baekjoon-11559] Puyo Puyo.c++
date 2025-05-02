#include <iostream>
#include <queue>
#include <string>
using namespace std;

char puyo[12][6];
int visit[12][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> group;

    char type = puyo[y][x];
    q.push({x, y});
    visit[y][x] = 1;
    group.push_back({x, y});

    while (!q.empty())
    {
        int x_now = q.front().first;
        int y_now = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x_next = x_now + dx[i];
            int y_next = y_now + dy[i];

            if (x_next >= 0 && x_next < 6 && y_next >= 0 && y_next < 12)
            {
                if (!visit[y_next][x_next] && puyo[y_next][x_next] == type)
                {
                    visit[y_next][x_next] = 1;
                    q.push({x_next, y_next});
                    group.push_back({x_next, y_next});
                }
            }
        }
    }

    if (group.size() >= 4)
    {
        for (auto [x, y] : group)
            puyo[y][x] = '.';
        return true;
    }

    return false;
}

int main()
{
    for (int i = 0; i < 12; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 6; j++)
        {
            puyo[i][j] = tmp[j];
        }
    }

    int combo = 0;
    bool flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (puyo[i][j] == '.')
                    continue;

                if (bfs(j, i))
                    flag = 1;
            }
        }

        for (int j = 0; j < 6; j++)
        {
            for (int i = 11; i >= 0; i--)
            {
                if (puyo[i][j] == '.')
                {
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (puyo[k][j] != '.')
                        {
                            puyo[i][j] = puyo[k][j];
                            puyo[k][j] = '.';
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                visit[i][j] = 0;

        if (flag == 1)
            combo++;
    }
    cout << combo;

    return 0;
}
