#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

#define int long long int
#define ll long long
#define ld long double 
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vpii vector<pii>
#define memset(arr,val) memset(arr,val,sizeof(arr))
#define INF INT64_MAX
#define pb push_back
#define pii pair<int,int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define sti stack<int>
#define pop st.pop();
#define top st.top();
#define push(a) st.push(a);
#define given                   \
    int n;                      \
    cin >> n;
#define take(a, n)              \
    for (int j = 0; j < n; j++) \
        cin >> a[j];
#define show(a, n)              \
    for (int j = 0; j < n; j++) \
        cout << a[j] << ' ';    \
    cout << '\n';
#define all(x) x.begin(), x.end()
#define rep(i,x,y) for(int i=x; i<y; i++)
#define rrep(i,x,y) for(int i=x; i>=y; i--)
#define setbits(n)  __builtin_popcountll(n)
#define bitsize(n) (63 - __builtin_clzll(n))
#define lcm(a,b) (a/__gcd(a, b)*b)
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
// #define MOD1 1000000007
#define MOD1 998244353
#define nl '\n'
#define PI 3.141592653589793238462
void solve() {
    given
    int a, b;
    cin >> a >> b;
    string dir;
    cin >> dir;

    int x = 0, y = 0;
    vvi coord(n, vi(2));
    coord[0][0] = x;
    coord[0][1] = y;

    // Traverse the path and check if we reach the target (a, b)
    for (int i = 0; i < n; i++) {
        switch (dir[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }
        coord[i][0] = x;
        coord[i][1] = y;
        if (x == a && y == b) {
            cout<<"YES"<<nl;
            return;
        }
    }

    // Calculate the change vector after one complete traversal
    vi change(2);
    change[0] = x; // dx after full traversal
    change[1] = y; // dy after full traversal

    // If there's no change in position after one full cycle
    if (change[0] == 0 && change[1] == 0) {
        cout<<"NO"<<nl;
        return;
    }

    // Check if the target (a, b) can be reached by repeating the pattern
    bool isP = false;
    for (int i = 0; i < n && !isP; i++) {
        int dx = a - coord[i][0];
        int dy = b - coord[i][1];

        // Check if (dx, dy) can be reached with multiples of change[0] and change[1]
        if (change[0] != 0 && change[1] != 0) {
            if (dx % change[0] == 0 && dy % change[1] == 0 && (dx / change[0]) == (dy / change[1]) && (dx / change[0]) >= 0) {
                isP = true;
                break;
            }
        } else if (change[0] != 0 && change[1] == 0) {
            if (dx % change[0] == 0 && dx / change[0] >= 0 && coord[i][1] == b) {
                isP = true;
                break;
            }
        } else if (change[1] != 0 && change[0] == 0) {
            if (dy % change[1] == 0 && dy / change[1] >= 0 && coord[i][0] == a) {
                isP = true;
                break;
            }
        }
    }

    if (isP) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
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
