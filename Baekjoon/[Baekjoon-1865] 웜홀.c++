#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<pair<int, int>, int>> v;
int dis[501];

bool bellman(int n)
{
    memset(dis, 987654321, sizeof(dis));
    dis[1] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int now = v[j].first.first;
            int next = v[j].first.second;
            int val = v[j].second;

            if (dis[now] != 987654321 && dis[now] + val < dis[next])
            {
                dis[next] = dis[now] + val;
                if (i == n)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n, m, w;
        cin >> n >> m >> w;

        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back({{s, e}, t});
            v.push_back({{e, s}, t});
        }
        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back({{s, e}, -t});
        }

        cout << (bellman(n) ? "YES\n" : "NO\n");
        v.clear();
    }

    return 0;
}
