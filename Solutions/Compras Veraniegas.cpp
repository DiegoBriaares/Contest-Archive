#include <bits/stdc++.h>
#define lld long long int
#define IZQ (med * 2)
#define DER (med * 2 + 1)
using namespace std;
const int MAXN = 200002;

int n, Q;
lld arr[MAXN];

struct segment_tree {
    int tree[MAXN * 5];

    int men(int a, int b) {
        return arr[a] < arr[b] ? a : b;
    }

    void construye(int nodo, int ini, int fin) {
        if(ini == fin) {
            tree[nodo] = ini;
        } else {
            int med = (ini + fin) / 2;
            construye(IZQ, ini, med);
            construye(DER, med + 1, fin);
            tree[nodo] = men(tree[IZQ], tree[DER]);
        }
    }

    int query(int nodo, int ini, int fin, int i, int j, lld d) {
        if(ini > j || fin < i) return 0;
        if(arr[tree[nodo]] > d) return 0;
        if(ini == fin) return tree[nodo];
        int med = (ini + fin) / 2;
        int I = query(IZQ, ini, med, i, j, d);
        return I ? I : query(DER, med + 1, fin, i, j, d);
    }

    int query(int i, int j, lld d) {
        if(i > j) return 0;
        return query(1, 1, n, i, j, d);
    }
};
segment_tree ST;

lld query(int i, int j, lld d) {
    int x = ST.query(i, j, d);
    while(x) {
        d %= arr[x];
        i = x + 1;
        x = ST.query(i, j, d);
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[0] = max(arr[0], arr[i] + 1);
    }
    ST.construye(1, 1, n);
    for(int i = 1; i <= Q; i++) {
        lld d;
        int a, b;
        cin >> d >> a >> b;
        cout << query(a, b, d) << "\n";
    }
    return 0;
}
