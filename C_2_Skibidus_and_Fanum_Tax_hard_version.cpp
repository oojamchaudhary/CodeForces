#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';

// Binary search to find the first index where b[idx] >= target
int fin(vector<int>& b, int target) {
    int left = 0, right = b.size() - 1, ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (b[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());
    if (n == 1) {
        yes
        return;
    }

    a[0] = min(a[0], b[0] - a[0]);

    for (int i = 1; i < n; i++) {
        int x = a[i - 1] + a[i];
        int y = fin(b, x);
        if (y >= m) y = m - 1;

        int curr = a[i];
        a[i] = min(a[i], b[y] - a[i]);

        if (a[i] < a[i - 1]) {
            a[i] = max(curr, b[y] - curr);
            if (a[i] < a[i - 1]) {
                no
                return;
            }
        }
    }
    yes
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
