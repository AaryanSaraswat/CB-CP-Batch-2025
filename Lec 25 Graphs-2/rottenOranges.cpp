#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
// #define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define pansent(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
// #define int long long

typedef long long lli;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=sz(grid),m=sz(grid[0]);

        int mins = 0;
        vp dir={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pii> q;

        loop(i,0,n) loop(j,0,m) if(grid[i][j]==2) q.push({i,j}); // rotten vale srcs q m daal diye

        while(!q.empty()){
            int s = q.size();
            loop(t,0,s){
                // sara kaam ek hi level k hai
                auto [i,j] = q.front(); q.pop();
                // childs pe iterate
                for( auto [di,dj] : dir){
                    int ni = i+ di,
                        nj = j+dj;
                    if(ni>=0 and ni<n and nj>=0 and nj<m and grid[ni][nj]==1){
                        grid[ni][nj] = 2; // vis mark
                        q.push({ni,nj}); 
                    }
                }
            }
            mins++;
        }

        loop(i,0,n) loop(j,0,m) if(grid[i][j]==1) return -1;
        return (mins==0)?mins:mins-1;
    }
};