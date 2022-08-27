#include "decl.hpp"

struct UnionFind {
    // par[i] := parent of i
    vector<int> par, rank, siz;

    // initialization
    UnionFind(int N) : par(N, -1), rank(N, 0), siz(N, 1) {}

    int root(int x) {
        /* returns the root of x */
        if (par[x] == -1) return x;
        // 経路圧縮
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        /* unite the trees where x and y belong */
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        par[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        siz[rx] += siz[ry];
    }

    bool same(int x, int y) {
        /* returns true if x and y belong to the same tree */
        return root(x) == root(y);
    }

    int size(int x) {
        /* returns the size of the tree that includes x */
        return siz[root(x)];
    }
};