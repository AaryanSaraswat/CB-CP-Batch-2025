#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define present(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
#define int long long

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;


void solve(){
    int n,m; cin>>n>>m;
    vvi grid(n,vi(m)); // 0 -> open space 1-> obstacle 
    for(auto &r:grid) for(auto &i:r) cin>>i;
    
    vp dir={{0,1},{1,0}};

    queue<vi>q; // {i,j,dist}
    // src se start
    q.push({0,0,0});
    grid[0][0] = 1; 
    while (!q.empty())
    {
        auto v = q.front(); q.pop();
        int i=v[0],j=v[1], dist=v[2];

        if(i==n-1 and j==m-1) {
            cout<<dist<<" ";
            break;
        }

        // childs pe iterate
        for( auto [di,dj] : dir){
            int ni = i+ di,
                nj = j+dj;
            if( ni>=0 and ni<n and nj>=0 and nj<m and grid[ni][nj]!=1){
                grid[ni][nj] = 1; // vis mark
                q.push({ni,nj,dist+1}); 
            }
        }
    }
    cout<<-1<<endl;
}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        
    }
    return 0;
}
