#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>      

int64_t n;
char a[1000000];

void read() {
	std::ifstream f("data.in");
	f >> n;
	for (int i = 0; i < n; i++) f >> a[i];
	f.close();
}

void validate(std::istream& f) {
	char t = 'B';
	int s = 0;
	for (int i = 0; i < n; i++) {
	    char c;
		if (!(f >> c)) {
			std::cout << "0.0\n";
			return;
		}
		if (c == 'R') t++;
		else if (c == 'L') t--;
		else if (c == 'M') s++;
		else {
			std::cout << "0.0\n";
			return;
		}
		if (t > 'C' || t < 'A' || t == a[i]) {
			std::cout << "0.0\n";
			return;				
		}
	}
	if (f >> t) {
		std::cout << "0.0\n";
		return;
	}
	std::cout << "1.0\n";
	return;
}

	int main () {
		read();
		validate(std::cin);

	}