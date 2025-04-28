#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char nums[1000][1000];
int dp[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<pair<int, int>, char>> q;
vector<pair<int, int>> fire;
vector<pair<int, int>> sang;

void bfs(int n, int m)
{
    for (int i = 0; i < fire.size(); i++)
        q.push({{fire[i].first, fire[i].second}, '*'});
    q.push({{sang[0].first, sang[0].second}, '@'});
    dp[sang[0].second][sang[0].first] = 1;

    while (!q.empty())
    {
        int x_now = q.front().first.first;
        int y_now = q.front().first.second;
        int type = q.front().second;
        q.pop();

        if (type == '@')
        {
            if (x_now == 0 || y_now == 0 || x_now == m - 1 || y_now == n - 1)
            {
                cout << dp[y_now][x_now] << "\n";
                return;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int x_next = x_now + dx[i];
            int y_next = y_now + dy[i];

            if (x_next >= 0 && y_next >= 0 && x_next < m && y_next < n)
            {
                if (type == '@')
                {
                    if (nums[y_next][x_next] == '.')
                    {
                        q.push({{x_next, y_next}, '@'});
                        nums[y_next][x_next] = '@';
                        dp[y_next][x_next] = dp[y_now][x_now] + 1;
                    }
                }
                else if (type == '*')
                {
                    if (nums[y_next][x_next] == '.' || nums[y_next][x_next] == '@')
                    {
                        q.push({{x_next, y_next}, '*'});
                        nums[y_next][x_next] = '*';
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < m; j++)
            {
                nums[i][j] = tmp[j];
                dp[i][j] = 0;

                if (nums[i][j] == '*')
                {
                    fire.push_back({j, i});
                }
                else if (nums[i][j] == '@')
                {
                    sang.push_back({j, i});
                }
            }
        }

        bfs(n, m);

        fire.clear();
        sang.clear();
        while (!q.empty())
            q.pop();
    }
    return 0;
}
