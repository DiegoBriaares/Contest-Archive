// This algorithm was detailedly instructed by me and was coded by ChatGPT.

#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> t;
    BIT(int n = 0) : n(n), t(n + 1, 0) {}
    void add(int idx, int delta = 1) {
        for (; idx <= n; idx += idx & -idx) t[idx] += delta;
    }
    int sumPrefix(int idx) const {
        int s = 0;
        for (; idx; idx -= idx & -idx) s += t[idx];
        return s;
    }
    int sumRange(int l, int r) const { return sumPrefix(r) - sumPrefix(l - 1); }
};

struct Event {
    long long val;    // c , x_i , d
    int type;         // 0 = c, 1 = point, 2 = d   (c < point < d)
    int a, b;         // index range [a,b]   (for point b is unused)
    int id;           // query id or 0 for points
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> x(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i];

    vector<array<int, 4>> qry(q);
    vector<Event> ev;
    ev.reserve(n + 2 * q);

    for (int id = 0; id < q; ++id) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        qry[id] = {a, b, c, d};
        ev.push_back({c, 0, a, b, id}); // c-event
        ev.push_back({d, 2, a, b, id}); // d-event
    }
    for (int i = 1; i <= n; ++i)
        ev.push_back({x[i], 1, i, 0, 0}); // point event

    auto order = [](const Event &p, const Event &q) {
        if (p.val != q.val) return p.val < q.val;
        if (p.type != q.type) return p.type < q.type; // c < point < d
        if (p.a != q.a) return p.a < q.a;             // tie-break on a
        return p.b < q.b;                             // then on b
    };
    sort(ev.begin(), ev.end(), order);

    BIT bit(n);
    vector<int> before(q), answer(q);

    for (const auto &e : ev) {
        if (e.type == 1) {               // point
            bit.add(e.a, 1);
        } else if (e.type == 0) {        // c-event
            before[e.id] = bit.sumRange(e.a, e.b);
        } else {                         // d-event
            answer[e.id] =
                bit.sumRange(e.a, e.b) - before[e.id];
        }
    }

    for (int v : answer) cout << v << '\n';
    return 0;
}
