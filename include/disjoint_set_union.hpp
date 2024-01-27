#pragma once
#include <bits/stdc++.h>

class DisjointSetUnion
{
    public:
    DisjointSetUnion(int n);
    int _find(int x);
    void _union(int x, int y);
    private:
    std::vector<int> parent;
    std::vector<int> size;
};