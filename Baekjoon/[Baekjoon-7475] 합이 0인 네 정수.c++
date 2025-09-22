#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<long long> ab, cd;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ab.push_back((long long)a[i]+b[j]);
            cd.push_back((long long)c[i]+d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long ans = 0;
    for(auto x: ab){
        auto low = lower_bound(cd.begin(), cd.end(), -x);
        auto high = upper_bound(cd.begin(), cd.end(), -x);
        ans += (high - low);
    }

    cout << ans << "\n";
}
