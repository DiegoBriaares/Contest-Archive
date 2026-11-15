#include <bits/stdc++.h>

using namespace std;

#define price first
#define party second
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll MaxN = 3102;
const ll INF = 999999999999999;

ll ans;
ll n, m;
ll our_votes;
bool buyed[MaxN];
int votants[MaxN];
vector<pair<ll, ll> > votes;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    ll p, c;
    cin >> p >> c;
    if (p == 1) {
      our_votes++;
    }
    else {
      votes.push_back(mp(c, p));
    }
  }
  ans = INF;
  sort(all(votes));
  for (int x = our_votes; x <= n; x++) {
    ll cost = 0;
    int amount = our_votes;
    for (int i = 0; i < MaxN; i++) {
      votants[i] = 0;
      buyed[i] = false;
    }
    for (int i = 0; i < votes.size(); i++) {
      votants[votes[i].party]++;
    }
    for (int i = 0; i < votes.size(); i++) {
      if (votants[votes[i].party] >= x) {
        votants[votes[i].party]--;
        cost += votes[i].price;
        buyed[i] = true;
        amount++;
      }
    }
    for (int i = 0; i < votes.size() && amount < x; i++) {
      if (!buyed[i]) {
        cost += votes[i].price;
        amount++;
      }
    }
    ans = min(ans, cost);
  }
  cout << ans << "\n";
}

