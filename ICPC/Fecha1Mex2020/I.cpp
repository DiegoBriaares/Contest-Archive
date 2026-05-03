/**

   * Made by:    Diego Briaares
   * At:   16.02.2021 23:08:26
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void test_case() {
	string s;
	cin >> s;
	vector<int> rule(5, 0);
	int conse = true;
	set<char> d;
	d.insert('.');
	d.insert('#');
	d.insert('$');
	d.insert('%');
	d.insert('&');
	d.insert('/');
	d.insert('(');
	d.insert(')');
	for (int i = 0; i < s.size(); i++) {
	    if (s[i] >= 'a' && s[i] <= 'z') rule[0] = 1;
		if (s[i] >= 'A' && s[i] <= 'Z') rule[1] = 1;
		if (s[i] >= '0' && s[i] <= '9') {
			rule[2] = 1;
			if (i >= 1 && s[i - 1] >= '0' && s[i - 1] <= '9' && (s[i - 1] == s[i] + 1 || s[i - 1] == s[i] - 1)) conse = false;
		}
		if (d.find(s[i]) != d.end()) rule[3] = true;
	}
	if (s.size() >= 10) rule[4] = true;
	rule[2] = (rule[2] == conse);
	int c = 0;
	for (int i = 0; i < 5; i++) c += rule[i];

	if (c < 3) {
		cout << "Rejected\n";
	}
	else if (c == 3) {
		cout << "Weak\n";
	}
	else if (c == 4) {
		cout << "Good\n";
	}
	else {
		cout << "Strong\n";
	}
}

	int main () {
		optimize();
		int t;
		cin >> t;
		int a = 1;
		while (t--) {
			cout << "Assertion number #" << a << ": ";
			test_case();
			a++;
		}
	}