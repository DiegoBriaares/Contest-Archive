class Solution {
public:
    int p[100000];
    int sz[100000];

    int Find(int v) {
        if (v == p[v]) {
            return v;
        }
        return Find(p[v]);
    }

    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u == v) {
            return;
        }
        if (sz[u] < sz[v]) {
            p[u] = v;
            sz[v] += sz[u];
        }
        else {
            p[v] = u;
            sz[u] += sz[v];
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[m * i + j] = m * i + j;
                sz[m * i + j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                if (i + 1 < n && grid[i + 1][j] == '1') {
                    Union(m * i + j, m * (i + 1) + j);
                }
                if (j + 1 < m && grid[i][j + 1] == '1') {
                    Union(m * i + j, m * i + j + 1);
                }
            }
        }
        set<int> S;
        for (int i = 0; i < n; i++) {
            for (int j= 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    S.insert(Find(m * i + j));
                }
            }
        }
        return (int)S.size();
    }
};
