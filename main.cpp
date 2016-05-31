#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {

	matrix<int> a(4, 5), b(3, 3);

	a[0][0] = 99;
	a[0][1] = 80;

	a[3][4] = 1;

	for (matrix<int>::iterator it(a.begin()); it != a.end(); ++it)
		cout << *it << ' ';


	cin.ignore();

}
