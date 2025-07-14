#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<int> bit;
    Fenwick(int n): n(n), bit(n + 1, 0) {}
    void add(int idx, int v){ for(;idx<=n; idx+=idx&-idx) bit[idx]+=v; }
    int sum(int idx) const { int s=0; for(;idx; idx-=idx&-idx) s+=bit[idx]; return s; }
    int range(int l,int r) const { return sum(r)-sum(l-1); }
};

struct Query{int a,b,id;};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; if(!(cin>>n>>q)) return 0;

    vector<long long> h(n+1);
    for(int i=1;i<=n;++i) cin>>h[i];

    /* ---------- L[i]: first >=-height on the left ---------- */
    vector<int> L(n+1,0), st;
    for(int i=1;i<=n;++i){
        while(!st.empty() && h[st.back()] < h[i]) st.pop_back();   // strict <
        L[i] = st.empty()? 0 : st.back();
        st.push_back(i);
    }

    vector<int> ord(n);
    iota(ord.begin(),ord.end(),1);
    sort(ord.begin(),ord.end(),[&](int x,int y){ return L[x] < L[y]; });

    vector<Query> qs(q);
    for(int i=0;i<q;++i){ cin>>qs[i].a>>qs[i].b; qs[i].id=i; }
    sort(qs.begin(),qs.end(),[](auto&x,auto&y){ return x.a<y.a; });

    Fenwick bit(n);
    vector<int> ans(q);
    int p=0;
    for(auto &qu:qs){
        while(p<n && L[ord[p]] < qu.a){ bit.add(ord[p],1); ++p; }
        ans[qu.id]=bit.range(qu.a,qu.b);
    }
    for(int x:ans) cout<<x<<"\n";
}
