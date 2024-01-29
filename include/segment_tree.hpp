#pragma once
#include <bits/stdc++.h>

class SegmentTree
{
    public:
    SegmentTree(std::vector<int> a);
    void updateAdd(int p, int v);
    void updateSet(int p, int v);
    int query(int l, int r);
    private:
    int n;
    std::vector<int> tree;
};