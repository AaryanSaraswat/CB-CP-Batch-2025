#include <bits/stdc++.h>
using namespace std;

vector<int> tree, a;

int merge(int a,int b){
    return min(a,b);
}

void build(int l, int r, int index)
{
    // base case
    if (l == r)
    {
        tree[index] = a[l];
        return;
    }

    // middle node
    int mid = (l + r) / 2;
    build(l, mid, 2 * index);         // left tree build hua
    build(mid + 1, r, 2 * index + 1); // right tree build hua
    tree[index] = merge(tree[2 * index] , tree[2 * index+1]);
}

void update(int l, int r, int index, int pos, int val)
{

    // base case
    if (l == r)
    {
        tree[index] = val;
        return;
    }

    // middle node
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(l, mid, index * 2, pos, val);
    else
        update(mid + 1, r, index * 2 + 1, pos, val);
    tree[index] = merge(tree[2 * index] , tree[2 * index+1]);
}

int query(int l,int r,int index,int ql,int qr){
    // complete overlap
    if(ql<=l and qr>=r) return tree[index];

    // non overlap
    if(qr<l or ql>r) return 1e18; // defualt value according to need

    // overlap
    int mid=(l+r)/2;
    int queryLeft= query(l,mid,index*2,ql,qr);
    int queryRight= query(mid+1,r,index*2+1,ql,qr);
    return merge(queryLeft, queryRight);
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n, 0);
    tree.resize(4 * n, 0);
    for (auto &i : a)
        cin >> i;
    build(0, n - 1, 1);
}

int main()
{

    return 0;
}