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
    int m;
    cin>>m;
    vector<vector<int>> grid(n,vector <int> (m));
    int num;
    for(int i = 0; i < n; i++){
        cin>>num;
        for(int j = m - 1; j >=0 ; j--){
            grid[i][j] = num%10;
            num /= 10;
        }
    }
    int layers = min(n / 2, m / 2);
    vector<vector<int>> seq(layers);
    for(int i = 0; i < layers; i++){
        int cons = i;
        for(int j = i; j < m - i; j++) seq[i].push_back(grid[cons][j]);
        cons = m - i- 1;
        for(int j = i + 1; j < n - i; j++) seq[i].push_back(grid[j][cons]);
        cons = n - i - 1;
        for(int j = m - i - 2; j >= i; j--) seq[i].push_back(grid[cons][j]);
        cons = i;
        for(int j = n - i- 2; j> i; j--) seq[i].push_back(grid[j][cons]);
    }
    int sum = 0;
    for(int i = 0; i < layers; i++){
        int size = seq[i].size();
        if(size > 3){
        for(int j = 0; j < seq[i].size(); j++){
            int k = (j + 1) % size;
            int l = (j + 2) % size;
            int o = (j + 3) % size;
            if(seq[i][j] == 1 && seq[i][k] == 5 && seq[i][l] == 4 && seq[i][o] == 3) sum++;
        }
        }
    }
    cout<<sum<<nl;
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