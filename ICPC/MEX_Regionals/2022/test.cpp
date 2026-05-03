/**

   * author:    Diego Briaares
   * At:   04.04.2022 13:43:16
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

template<class T>
void read(vector<T> &input, int input_sz, int input_indx = 0) {
	input = vector<T>(input_sz + input_indx);
	for (int i = 0; i < input_sz; i++) {
		cin >> input[i + input_indx];
	}
}

template<class T>
void print(vector<T> &output, int output_sz, int output_indx = 0) {
	for (int i = 0; i < output_sz; i++) {
		cout << output[i + output_indx] << " ";
	}
	cout << "\n";
}

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		vector<int> a(3);
		int n;
		cin >> n;
		read(a, n);
		for (int i = 0; i < n; i++)	{
			a[i] += (-1) * (i & 1) * 10 + 5;
		}
		print(a, n);

	}