#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> graph[100001];
int visit[100001];
int mxdist, mxnode;

void dfs(int node, int dist)
{
    if (visit[node] == 1)
    {
        return;
    }
    if (mxdist < dist)
    {
        mxdist = dist;
        mxnode = node;
    }

    visit[node] = 1;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i].first;
        int val = graph[node][i].second + dist;
        dfs(next, val);
    }
}

int main()
{
    int v;
    cin >> v;

    for (int i = 0; i < v; i++)
    {
        int start, a, b;
        cin >> start;

        while (1)
        {
            cin >> a;
            if (a == -1)
                break;
            cin >> b;

            graph[start].push_back({a, b});
        }
    }

    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    mxdist = 0;

    dfs(mxnode, 0);
    cout << mxdist;

    return 0;
}
