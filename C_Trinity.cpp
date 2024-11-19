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

void solve() {
    given
    vi arr(n);
    take(arr, n)
    sort(arr.begin(), arr.end());
    int left = 0, right = 0;
    int it = n - 1;
    while(arr[it] >= arr[0] + arr[1]) it--;
    right = n - 1 - it;
    it = 0;
    while(arr[it] + arr[it + 1] <= arr[n - 1]) it++;
    left = it;
    int ans = min(left, right);
    left = 0, right = n - 1;

    while(left + (n - 1 - right) < ans){
        if(arr[left + 1] - arr[left] > arr[right] - arr[right - 1]) left++;
        else right--;
        if(arr[left] + arr[left + 1] > arr[right]) break;
    }
    if(left + (n - 1 - right) == ans) cout<<ans<<nl;
    else cout<<left+(n - 1 - right)<<nl;
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