#include <iostream>
using namespace std;
int main() {
    // Print compound proposition truth table
    cout << "p\tq\t(p->q)\t(p->!p)\t!p\t((p->q)^(p->!p))\t!p" << endl;
    cout << "--------------------------------------------------------" << endl;

    int isValid = 1;  // Assume the compound proposition is valid initially

    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            int pimpq = (!p || q);  // p->q
            int pimpnotp = (!p || !p);  // p->¬p
            int notp = !p;  // ¬p
            int lhs=pimpq && pimpnotp;
            int result = ((pimpq && pimpnotp) == notp) ? 1 : 0;  // (p->q)^(p->¬p)?¬p
            cout << p <<"\t"<<q<<"\t"<<pimpq<<"\t"<<pimpnotp<<"\t"<<notp<<"\t\t"<<lhs<<"\t\t"<<notp<<endl;
            
            // Check if the result is false (0), and if so, set isValid to false
            if (result == 0) {
                isValid = 0;
            }
        }
    }

    // Check the validity of the compound proposition
    if (isValid) {
        cout << "Valid" << endl;
    } else {
        cout << "Not valid" << endl;
    }
}
    
