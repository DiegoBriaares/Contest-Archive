/**

   * author:    Diego Briaares
   * At:   14.05.2022 12:15:41
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
		int area = 0;
		for (int i = 1; 2 * i < n - 1; i++){
			area = max(area, i * ((n - 2 * i) / 2));
		}
		cout << area << "\n";
			
	}