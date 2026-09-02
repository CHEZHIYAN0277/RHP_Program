#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, q;
        cin >> n >> q;

        vector<int> A(n), mp(100001);

        for (int i = 0; i < n; i++)
            cin >> A[i];

        iota(mp.begin(), mp.end(), 0);

        cout << "Case " << tc << ":\n";

        while (q--) {
            int type, x, y;
            cin >> type >> x;

            if (type == 1) {
                cin >> y;
                mp[x] = mp[y];
            } else {
                cout << mp[A[x - 1]] << '\n';
            }
        }
    }
}
