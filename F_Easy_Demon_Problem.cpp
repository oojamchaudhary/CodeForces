#include <bits\stdc++.h>
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
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<int> a(n);
    vector<int> b(m);
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    long long totalSum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            totalSum +=  a[i] * b[j];
    
    unordered_map<long long, int> hs;
    for (int i = 0; i < n; ++i) {
        long long rowSum = 0;
        for (int j = 0; j < m; ++j)
            rowSum += a[i] * b[j];
        
        for (int j = 0; j < m; ++j) {
            long long colSum = 0;
            for (int k = 0; k < n; ++k)
                colSum += a[k] * b[j];
            
            long long adjustedSum = totalSum - (rowSum + colSum - a[i] * b[j]);
            hs[adjustedSum]++;
        }
    }
    
    for (int i = 0; i < x; ++i) {
        long long val;
        cin >> val;
        if (hs[val]>=1) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    fastIO;
    solve();
    
}