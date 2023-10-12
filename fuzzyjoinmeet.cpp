#include <stdio.h>

// Function to calculate the union (join) of two fuzzy sets
void fuzzy_union(int n, float set_A[], float set_B[], float result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = (set_A[i] > set_B[i]) ? set_A[i] : set_B[i];
    }
}

// Function to calculate the intersection (meet) of two fuzzy sets
void fuzzy_intersection(int n, float set_A[], float set_B[], float result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = (set_A[i] < set_B[i]) ? set_A[i] : set_B[i];
    }
}

int main() {
    // Define the fuzzy sets as arrays
    int n = 4; // Number of elements in the sets
    float set_A[] = {0.2, 0.4, 0.6, 0.8};
    float set_B[] = {0.1, 0.3, 0.5, 0.7};
    float union_result[n];
    float intersection_result[n];

    // Calculate the union (join) of the fuzzy sets
    fuzzy_union(n, set_A, set_B, union_result);

    // Calculate the intersection (meet) of the fuzzy sets
    fuzzy_intersection(n, set_A, set_B, intersection_result);

    // Print the original fuzzy sets, the union result, and the intersection result
    printf("Fuzzy Set A: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", set_A[i]);
    }
    printf("\n");

    printf("Fuzzy Set B: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", set_B[i]);
    }
    printf("\n");

    printf("Union (Join) of Sets A and B: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", union_result[i]);
    }
    printf("\n");

    printf("Intersection (Meet) of Sets A and B: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", intersection_result[i]);
    }
    printf("\n");

    return 0;
}
