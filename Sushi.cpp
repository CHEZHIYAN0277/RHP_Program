#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int c = 0;
    int n1 = n - 1;
    int m1 = m - 1;

    while (n1 >= 0 && m1 >= 0) {
        if (a[n1] * 2 >= b[m1]) {
            c++;
            n1--;
            m1--;
        } else {
            m1--;
        }
    }

    cout << c << '\n';
    return 0;
}
