/**

   * Made by:    Diego Briaares
   * At:   07.11.2021 18:38:03
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}


long long A;

    int main () {
        optimize();
        int m, n;
        cin >> m >> n;  
        vector<pair<long long, long long>> bp(m);
        for (int i = 0; i < m; i++) cin >> bp[i].first >> bp[i].second;
        sort(bp.begin(), bp.end());
        vector<pair<long long, long long>> p;
        p.push_back(bp[0]);
        for (int i = 1; i < m; i++) {
            if (bp[i].second < p.back().second) p.push_back(bp[i]);
        }
        vector<pair<long long, long long>> bc(n);
        for (int i = 0; i < n; i++) cin >> bc[i].first >> bc[i].second;
        sort(bc.begin(), bc.end());
        reverse(bc.begin(), bc.end());
        vector<pair<long long, long long>> c;
        c.push_back(bc[0]);
        for (int i = 1; i < n; i++) {
            if (bc[i].second > c.back().second) c.push_back(bc[i]);
        }
        reverse(c.begin(), c.end());
        function<void(int, int, int, int)> solve = [&] (int lp, int rp, int lc, int rc) {
            if (lp > rp || lc > rc) return;
            int mid = (lp + rp) >> 1;
            long long area = -(long long) 1e18;
            int opt = -1;
            for (int i = lc; i <= rc; i++) {
                if (c[i].second > p[mid].second || c[i].first > p[mid].first) {
                    if ((long long)((c[i].second - p[mid].second) * (c[i].first - p[mid].first)) > area) {
                        area = (long long) ((c[i].second - p[mid].second) * (c[i].first - p[mid].first));
                        opt = i;
                    }
                }
            }
            if (opt != -1) {
                solve(lp, mid - 1, lc, opt);
                solve(mid + 1, rp, opt, rc);
                A = max(A, area);
            }
        };
        solve(0, (int)p.size() - 1, 0, (int) c.size() - 1);
        cout << A << "\n";
    }