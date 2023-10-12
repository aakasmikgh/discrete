#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double number;
    cout << "Enter a number: ";
    cin >> number;

    // Calculate the ceiling and floor using the ceil() and floor() functions from the <cmath> library
    double ceilValue = ceil(number);
    double floorValue = floor(number);

    cout << "Ceiling of " << number << " is: " << ceilValue << endl;
    cout << "Floor of " << number << " is: " << floorValue << endl;

    return 0;
}

