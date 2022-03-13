#include <iostream>
#include <stdexcept>
#include "mat.hpp"
using namespace std;
using namespace ariel;

int main() {
    int a, b;
    char c, d;

	cout << isprint(4) << endl;

	cout << "Please enter mat height, width and two chars for the design" << endl;

    cin >> a >> b >> c >> d;

	cout << ariel::mat(a, b, c, d) << endl;
}
