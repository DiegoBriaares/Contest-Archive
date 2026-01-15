class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();

        pair<int, pair<int, int>> st;
        st = make_pair(matrix[0][0], make_pair(0, 0));
        set<pair<int, pair<int, int>>> Q;
        Q.insert(st);
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};
        while (!Q.empty()) {
            st = *Q.begin();
            Q.erase(Q.begin());
            int i, j, v;
            i = st.second.first;
            j = st.second.second;
            v = matrix[i][j];
            vis[i][j] = true;
            // Encontramos el k-esimo menor?
            k--;
            if (k == 0) {
                return v;
            }
            // Visitar estados adyacentes
            int nxt_i, nxt_j;
            for (int it = 0; it < 2; it++) {
                nxt_i = i + dx[it];
                nxt_j = j + dy[it];
                if (nxt_i >= n || nxt_j >= n) {
                    continue;
                }
                Q.insert(make_pair(matrix[nxt_i][nxt_j], 
                make_pair(nxt_i, nxt_j)));
            }
        }
        return -1;
    }
};
