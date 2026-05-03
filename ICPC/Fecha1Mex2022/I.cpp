/**

   * author:    Diego Briaares
   * At:   14.05.2022 12:01:53
**/

#include <bits/stdc++.h>
using namespace std;

istream & operator >> (istream &in, pair<int, int> &x) {
	in >> x.first >> x.second;
	return in;
}

ostream & operator << (ostream &out, pair<int, int> &x) {
	out << x.first << " " << x.second;
	return out;
}

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n;
		cin >> n;
		int cnt = 0;
		int N = n;
		while (N) {
			if ((N % 10) != 0 && n % (N % 10) == 0) cnt++;
			N /= 10;
		}
		cout << cnt << "\n";
	}