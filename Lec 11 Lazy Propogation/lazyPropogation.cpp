#include <bits/stdc++.h>
using namespace std;

vector<int> tree, a, lazy;

int merge(int a, int b)
{
    return (a + b);
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
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
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
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

void propogate(int index, int l, int r)
{
    // leaf node nahi hai to
    if (l != r)
    {
        lazy[2 * index] += lazy[index];
        lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
}

void rangeUpdate(int l, int r, int index, int ql, int qr, int val)
{

    // mein yhn aya hu
    // agar lazy tree m kuch pada hai to use resolve kardo
    if (lazy[index] != 0)
    {
        // resolve
        tree[index] += lazy[index] * (r - l + 1);
        // propogate
        propogate(index, l, r);
    }

    // complete overlap
    if (ql <= l and r <= qr)
    {
        tree[index] += val * (r - l + 1);
        if (l != r)
        {
            lazy[2 * index] += val;
            lazy[2 * index + 1] += val;
        }
        return;
    }

    // no overlap
    if(qr<l or ql>r) return;

    // partial overlap
    int mid=(l+r)/2;
    rangeUpdate(l,mid,2*index,ql,qr,val);
    rangeUpdate(mid+1,r,2*index+1,ql,qr,val);
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

int query(int l, int r, int index, int ql, int qr)
{
    // mein yhn aya hu
    // agar lazy tree m kuch pada hai to use resolve kardo
    if (lazy[index] != 0)
    {
        // resolve
        tree[index] += lazy[index] * (r - l + 1);
        // propogate
        propogate(index, l, r);
    }
    
    // complete overlap
    if (ql <= l and qr >= r)
        return tree[index];

    // non overlap
    if (qr < l or ql > r)
        return 0; // defualt value according to need

    // overlap
    int mid = (l + r) / 2;
    int queryLeft = query(l, mid, index * 2, ql, qr);
    int queryRight = query(mid + 1, r, index * 2 + 1, ql, qr);
    return merge(queryLeft, queryRight);
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n, 0);
    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0); // init by default value
    for (auto &i : a)
        cin >> i;
    build(0, n - 1, 1);
}

int main()
{

    return 0;
}