/**
 * Author: Tanya
 * Description: this can also be use to find minimum partition on posit by finding maximum anti-chain
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    vector<int> best(n + 1);
    best[0] = 0;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int len = lower_bound(best.begin(), best.begin() + result + 1, x[i]) -
                  best.begin();
        if (len > result) {
            result = len;
            best[len] = x[i];
        } else {
            best[len] = min(best[len], x[i]);
        }
    }

    cout << result << endl;
}
