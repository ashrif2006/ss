#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n + 1, 0);
    vector<long long> aSorted(n + 1, 0);
    vector<long long> prefix(n + 1, 0);
    vector<long long> sortedPrefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        aSorted[i] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }


    sort(aSorted.begin() + 1, aSorted.end());
    for (int i = 1; i <= n; i++) {
        sortedPrefix[i] = sortedPrefix[i - 1] + aSorted[i];
    }

    int numberOfOperation;
    cin >> numberOfOperation;
    
    while (numberOfOperation--) {
        int type, l, r;
        cin >> type >> l >> r;  

        long long res = 0;
        if (type == 1) {
            res = prefix[r] - prefix[l - 1];
        } else if (type == 2) {
            res = sortedPrefix[r] - sortedPrefix[l - 1];
        }
        cout << res << "\n";
    }

    return 0;
}