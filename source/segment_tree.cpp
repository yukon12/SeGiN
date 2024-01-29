#include <segment_tree.hpp>

SegmentTree::SegmentTree(std::vector<int> a)
{
    n = a.size();
    tree = std::vector<int>(2*n, 0);

    for(int i = 0; i < n; i++)
    {
        tree[n+i] = a[i];
    }

    for(int i = n-1; i > 0; i--)
    {
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void SegmentTree::updateAdd(int p, int v)
{
    p += n;
    
    while(p>0)
    {
        tree[p] += v;
        p /= 2;
    }
}

void SegmentTree::updateSet(int p, int v)
{
    p += n;
    tree[p] = v;
    p /= 2;

    while(p>0)
    {
        tree[p] = tree[2*p] + tree[2*p+1];
        p /= 2;
    }
}

int SegmentTree::query(int l, int r)
{
    int result = 0;
    l += n;
    r += n;

    while(l<=r)
    {
        if(l%2==1)
        {
            result += tree[l];
            l++;
        }
        if(r%2==0)
        {
            result += tree[r];
            r--;
        }

        l /= 2;
        r /= 2;
    }

    return result;
}