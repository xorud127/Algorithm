#include <iostream>
#include <string>
using namespace std;

char map[10000][500];
int visit[10000][500];
int r, c, ans;
int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};

bool dfs(int x, int y)
{
    if (x == c - 1)
    {
        ans++;
        return 1;
    }

    visit[y][x] = 1;

    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= c || ny < 0 || ny >= r || visit[ny][nx] == 1 || map[ny][nx] == 'x')
            continue;
        if (dfs(nx, ny))
            return 1;
    }
    return 0;
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
            map[i][j] = str[j];
    }

    bool tmp;
    for (int i = 0; i < r; i++)
        tmp = dfs(0, i);

    cout << ans;

    return 0;
}
