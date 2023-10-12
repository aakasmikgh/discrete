//Program to find if the given set is injective, bijective or surjective
#include <stdio.h>

int isInjective(int arr[], int n) {
    int range[1000] = {0}; // Assuming a range of elements from 1 to 1000

    for (int i = 0; i < n; i++) {
        if (range[arr[i]] == 0) {
            range[arr[i]] = 1;
        } else {
            return 0; // Not injective, two elements map to the same element
        }
    }

    return 1; // Injective
}

int isSurjective(int arr[], int n, int m) {
    int range[1000] = {0}; // Assuming a range of elements from 1 to 1000

    for (int i = 0; i < n; i++) {
        range[arr[i]] = 1;
    }

    for (int i = 1; i <= m; i++) {
        if (range[i] == 0) {
            return 0; // Not surjective, some elements in the second set are not covered
        }
    }

    return 1; // Surjective
}

int main() {
    int n, m;

    printf("Enter the size of the first and second set: ");
    scanf("%d%d", &n,&m);

   // printf("Enter the size of the second set: ");
    //scanf("%d", &m);

    if (n != m) {
        printf("The function is neither injective nor surjective.\n");
    } else {
        int arr[n];
        printf("Enter the function mapping from the first set to the second set:\n");

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int injective = isInjective(arr, n);
        int surjective = isSurjective(arr, n, m);

        if (injective && surjective) {
            printf("The function is bijective.\n");
        } else if (injective) {
            printf("The function is injective but not surjective.\n");
        } else if (surjective) {
            printf("The function is surjective but not injective.\n");
        } else {
            printf("The function is neither injective nor surjective.\n");
        }
    }

    return 0;
}

