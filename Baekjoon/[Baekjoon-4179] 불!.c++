#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

char world[1000][1000];
int dp[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> fire;
vector<pair<int, int>> jihoon;

void bfs(int r, int c)
{
    queue<pair<pair<int, int>, char>> q;
    for (int i = 0; i < fire.size(); i++)
    {
        q.push({{fire[i].first, fire[i].second}, 'F'});
    }
    for (int i = 0; i < jihoon.size(); i++)
    {
        q.push({{jihoon[i].first, jihoon[i].second}, 'J'});
        dp[jihoon[i].second][jihoon[i].first] = 1;
    }

    while (!q.empty())
    {
        int x_now = q.front().first.first;
        int y_now = q.front().first.second;
        int val = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int y_next = y_now + dy[i];
            int x_next = x_now + dx[i];

            if (val == 'J' && (x_next < 0 || x_next >= c || y_next < 0 || y_next >= r))
            {
                cout << dp[y_now][x_now] << "\n";
                return;
            }

            if (x_next >= 0 && x_next < c && y_next >= 0 && y_next < r)
            {
                if (val == 'F')
                {
                    if (world[y_next][x_next] != 'F' && world[y_next][x_next] != '#')
                    {
                        world[y_next][x_next] = 'F';
                        q.push({{x_next, y_next}, 'F'});
                    }
                }
                else if (val == 'J')
                {
                    if (world[y_next][x_next] == '.')
                    {
                        world[y_next][x_next] = 'J';
                        q.push({{x_next, y_next}, 'J'});
                        dp[y_next][x_next] = dp[y_now][x_now] + 1;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main()
{
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < c; j++)
        {
            world[i][j] = tmp[j];
            if (world[i][j] == 'J')
            {
                jihoon.push_back({j, i});
            }
            else if (world[i][j] == 'F')
            {
                fire.push_back({j, i});
            }
        }
    }

    bfs(r, c);
    return 0;
}
