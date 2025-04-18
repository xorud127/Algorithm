#include <iostream>
#include <string>
#include <vector>
using namespace std;

int nums[9][9];
bool col[9][10], row[9][10], square[9][10];
bool flag = 0;

void dfs(int cnt)
{
    if (cnt == 81)
    {
        flag = 1;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << nums[i][j];
            cout << "\n";
        }

        return;
    }

    int x = cnt % 9, y = cnt / 9;

    if (nums[y][x] != 0)
    {
        dfs(cnt + 1);
        return;
    }

    int s = (y / 3) * 3 + x / 3;
    for (int i = 1; i < 10; i++)
    {
        if (!row[y][i] && !col[x][i] && !square[s][i])
        {
            nums[y][x] = i;
            row[y][i] = col[x][i] = square[s][i] = 1;
            dfs(cnt + 1);
            if (flag == 1)
                return;
            nums[y][x] = 0;

            row[y][i] = col[x][i] = square[s][i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 9; j++)
        {
            nums[i][j] = tmp[j] - '0';
            int num = nums[i][j];
            if (num != 0)
            {
                row[i][num] = true;
                col[j][num] = true;
                square[(i / 3) * 3 + (j / 3)][num] = true;
            }
        }
    }

    dfs(0);

    return 0;
}
