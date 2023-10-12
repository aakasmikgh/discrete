#include<iostream>
using namespace std;


int check_injective(int function[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (function[i] == function[j]) {
                return 0;  
            }
        }
    }
    return 1;  
}

int check_surjective(int function[], int size, int codomain[], int codomain_size) {
    int found_count = 0;
    for (int i = 0; i < codomain_size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (function[j] == codomain[i]) {
                ++found_count;
                break;
            }
        }
    }
    return (found_count == codomain_size) ? 1 : 0;  
}

int check_bijective(int function[], int size, int codomain[], int codomain_size) {
    int injective = check_injective(function, size);
    int surjective = check_surjective(function, size, codomain, codomain_size);
    return (injective && surjective);  
}

int main() {
    int domain[] = {1, 2, 3};
    int codomain[] = {1, 4, 9, 16};
    int function[] = {1, 4, 16};

    int domain_size = sizeof(domain) / sizeof(domain[0]);
    int codomain_size = sizeof(codomain) / sizeof(codomain[0]);
    int function_size = sizeof(function) / sizeof(function[0]);

    int is_bijective = check_bijective(function, function_size, codomain, codomain_size);
    int is_injective=check_injective(function, function_size);
    int is_surjective=check_surjective(function, function_size, codomain, codomain_size);

   cout << "Is Bijective: " << (is_bijective ? "Yes" : "No") << endl;
   cout<< "Is Injective:"<< (is_injective?"Yes":"No")<<endl;
   cout<< "Is Surjective:"<< (is_surjective?"Yes":"No")<<endl;

    return 0;
}
