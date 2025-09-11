#include <iostream>
using namespace std;

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    
    // 벡터ab, ac 외적
    int val = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);

    if (val > 0)
        cout << 1 << "\n";
    else if (val < 0)
        cout << -1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}
