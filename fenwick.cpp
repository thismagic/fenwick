#include "bits/stdc++.h"

using namespace std;

struct fenwick {
    vector<int> tree;
    fenwick(int n) {
        tree.assign(n + 1,0);
    }
 
    void add(int i,int x) {
        for(; i < tree.size(); i |= i + 1) tree[i] += x;
    }
 
    int sum(int i) {
        int s = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) s += tree[i];
        return s;
    }
 
    int get(int l,int r) {
        if(l > r) {
            return sum(r) + sum(tree.size() - 1) - (l ? sum(l - 1) : 0);
        }
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};
