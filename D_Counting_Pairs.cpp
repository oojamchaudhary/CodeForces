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

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
int bin(vector<int> &a, int left, int r, int k, int y) {
    int l = left;
    if (k > a.back()) return 0;

    while (l <= r) {
        int mid = l + ((r - l) / 2);
        if (a[mid] == k || (a[mid] > k && (mid == 0 || a[mid - 1] < k))) {
            while (mid >= left && a[mid] >= k) mid--;
            if (mid < left || a[mid] < k) mid++;
            
            int count = 0;
            while (mid < a.size() && a[mid] <= y) {
                count++;
                mid++;
            }
            return count;
        }
        if (a[mid] > k) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

void solve() {
    int n, x, y;
    cin>>n>>x>>y;
    vi a(n);
    take(a, n)
    sort(a.begin(), a.end());
    //show(a, n)
    int ans = 0;
    for(int i = 0; i < n; i++){
        //cout<<i << " "<< ans << nl;
        ans += bin(a, i + 1, n - 1, x - a[i], y - a[i]);
    }
    cout<<ans<<nl;
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