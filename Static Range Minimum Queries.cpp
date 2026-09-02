#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<long long> tree;
    int n;

public:
    SegmentTree(vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {

        // Completely outside
        if (r < start || end < l)
            return LLONG_MAX;

        // Completely inside
        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        long long left = query(2 * node, start, mid, l, r);
        long long right = query(2 * node + 1, mid + 1, end, l, r);

        return min(left, right);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr);

    while (q--) {
        int a, b;
        cin >> a >> b;

        // Convert 1-based input to 0-based
        a--;
        b--;

        cout << st.query(a, b) << '\n';
    }

    return 0;
}
