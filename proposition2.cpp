#include <iostream>
using namespace std;

int main() {
    // Print compound proposition truth table
    cout << "p | q | r | (p^!p)| (p<->r)|!(p<->r)|(p^!p)->!(p<->r)| !pvqv!r" << endl;
    cout << "--------------------------------------------------------------" << endl;

    int isValid = 1;  // Assume the compound proposition is valid initially

    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                int pandnotp = (p && !p);  // p^¬p
                int pbir = ((p && r) || (!p && !r));  // p<->r
                int notpbir = !pbir;  // ¬(p<->r)
                int result = ((pandnotp || notpbir) == (!p || q || !r)) ? 1 : 0;  // (p^¬p)->¬(p<->r)?¬p v q v ¬r
                cout << p << "  |  " << q << "  |  " << r << "  |  " << pandnotp << "  |  " << pbir << "  |  " << notpbir << "  |  " 
				<< !(pandnotp && notpbir) << "  |  " << (!p || q || !r) << endl;
                
                // Check if the result is false (0), and if so, set isValid to false
                if (result == 0) {
                    isValid = 0;
                }
            }
        }
    }

    // Check the validity of the compound proposition
    if (isValid) {
        cout << "Valid" << endl;
    } else {
        cout << "Not valid" << endl;
    }

    return 0;
}


