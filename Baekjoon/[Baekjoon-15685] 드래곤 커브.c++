#include <iostream>
#include <vector>
using namespace std;

int flat[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void draw(int x, int y, int d, int g)
{
    vector<int> v;
    v.push_back(d);
    int x_now = x + dx[d], y_now = y + dy[d];
    flat[y][x] = 1;
    flat[y_now][x_now] = 1;

    for (int i = 1; i <= g; i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            int tmp = (v[j] + 1) % 4;
            v.push_back(tmp);

            x_now += dx[tmp];
            y_now += dy[tmp];
            if (y_now >= 0 && y_now < 101 && x_now >= 0 && x_now < 101)
                flat[y_now][x_now] = 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        draw(x, y, d, g);
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (flat[i][j] == 1 && flat[i + 1][j] == 1 && flat[i][j + 1] == 1 && flat[i + 1][j + 1] == 1)
                cnt++;
        }
    }
    cout << cnt;

    return 0;
}
