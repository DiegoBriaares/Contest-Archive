/**

   * author:    Diego Briaares
   * At:   04.04.2022 13:35:16
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

istream & operator >> (istream &in, pair<int, int> &x) {
	in >> x.first >> x.second;
	return in;
}

ostream & operator << (ostream &out, pair<int, int> &x) {
	out << x.first << " " << x.second;
	return out;
}

	int main () {
		optimize();
		pair<int, int> a;
		cin >> a;
		a.first++;
		cout << a << "\n";
	}