#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, ans;
char school[600][600];
int visit[600][600];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs()
{

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx_x = dx[i] + x;
            int nx_y = dy[i] + y;

            if (visit[nx_y][nx_x] == 0 && nx_x >= 0 && nx_x < m && nx_y >= 0 && nx_y < n)
            {
                if (school[nx_y][nx_x] == 'X')
                    continue;
                else if (school[nx_y][nx_x] == 'P')
                    ans++;
                q.push({nx_x, nx_y});
                visit[nx_y][nx_x] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            school[i][j] = tmp[j];
            if (school[i][j] == 'I')
            {
                q.push({j, i});
                visit[i][j] = 1;
            }
        }
    }

    bfs();

    if (ans == 0)
        cout << "TT";
    else
        cout << ans;

    return 0;
}
