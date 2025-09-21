#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans[3];
long long val = 3000000000;
vector<long long> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1, right = n - 1;

        while (left < right)
        {
            long long s = v[i] + v[left] + v[right];

            if (abs(s) < val)
            {
                ans[0] = i, ans[1] = left, ans[2] = right;
                val = abs(s);
            }

            if (s < 0)
                left++;
            else
                right--;
        }
    }

    for (int i = 0; i < 3; i++)
        cout << v[ans[i]] << " ";

    return 0;
}
