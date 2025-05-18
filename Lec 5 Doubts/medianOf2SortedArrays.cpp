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

    double getAns(vi &a,vi &b){
        int n=sz(a),m=sz(b);
        int total=(n+m),half=(total)/2;
        int st=0,en=n;
        while(st<=en){
            int i1=st+(en-st)/2;
            int i2=half-i1;

            int lefti1=(i1-1>=0)?a[i1-1]:-1e9, righti1=(i1<n)?a[i1]:1e9;
            int lefti2=(i2-1>=0)?b[i2-1]:-1e9, righti2=(i2<m)?b[i2]:1e9;

            if(lefti1<=righti2 and lefti2<=righti1){
                if(total&1) return min(righti1,righti2);
                return (max(lefti1,lefti2)+min(righti1,righti2))/2.0;
            }
            else if(lefti1>righti2) en=i1-1;
            else st=i1+1;
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if(sz(nums1)>sz(nums2)) nums1.swap(nums2); 
        if(sz(nums1)>sz(nums2)) return getAns(nums2,nums1); 
        return getAns(nums1,nums2);
    }
};