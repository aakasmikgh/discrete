#include <stdio.h>

// Function to check if a relation is symmetric
int isSymmetric(int relation[][3], int n) {
    for (int i = 0; i < n; i++) {
        int a = relation[i][0];
        int b = relation[i][1];
        int isPresent = 0;

        // Check if the reverse pair is present in the relation
        for (int j = 0; j < n; j++) {
            if (relation[j][0] == b && relation[j][1] == a) {
                isPresent = 1;
                break;
            }
        }

        if (!isPresent) {
            return 0; // Not symmetric
        }
    }
    return 1; // Symmetric
}

// Function to check if a relation is antisymmetric
int isAntisymmetric(int relation[][3], int n) {
    for (int i = 0; i < n; i++) {
        int a = relation[i][0];
        int b = relation[i][1];

        // Check if both (a, b) and (b, a) are present and a != b
        for (int j = 0; j < n; j++) {
            if (i != j && relation[j][0] == b && relation[j][1] == a) {
                return 0; // Not antisymmetric
            }
        }
    }
    return 1; // Antisymmetric
}

// Function to check if a relation is reflexive
int isReflexive(int relation[][3], int n) {
    for (int i = 0; i < n; i++) {
        int a = relation[i][0];
        int b = relation[i][1];

        if (a != b) {
            int isPresent = 0;

            // Check if (a, a) is present in the relation
            for (int j = 0; j < n; j++) {
                if (relation[j][0] == a && relation[j][1] == a) {
                    isPresent = 1;
                    break;
                }
            }

            if (!isPresent) {
                return 0; // Not reflexive
            }
        }
    }
    return 1; // Reflexive
}

// Function to check if a relation is transitive
int isTransitive(int relation[][3], int n) {
    for (int i = 0; i < n; i++) {
        int a = relation[i][0];
        int b = relation[i][1];

        for (int j = 0; j < n; j++) {
            int c = relation[j][0];
            int d = relation[j][1];

            if (b == c) {
                int isPresent = 0;

                // Check if (a, d) is present in the relation
                for (int k = 0; k < n; k++) {
                    if (relation[k][0] == a && relation[k][1] == d) {
                        isPresent = 1;
                        break;
                    }
                }

                if (!isPresent) {
                    return 0; // Not transitive
                }
            }
        }
    }
    return 1; // Transitive
}

int main() {
    int n;

    printf("Enter the number of pairs in the relation: ");
    scanf("%d", &n);

    int relation[n][3]; // Each row represents a pair (a, b)

    printf("Enter the pairs (a b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &relation[i][0], &relation[i][1]);
    }

    int symmetric = isSymmetric(relation, n);
    int antisymmetric = isAntisymmetric(relation, n);
    int reflexive = isReflexive(relation, n);
    int transitive = isTransitive(relation, n);

    if (symmetric) {
        printf("The relation is symmetric.\n");
    } else {
        printf("The relation is not symmetric.\n");
    }

    if (antisymmetric) {
        printf("The relation is antisymmetric.\n");
    } else {
        printf("The relation is not antisymmetric.\n");
    }

    if (reflexive) {
        printf("The relation is reflexive.\n");
    } else {
        printf("The relation is not reflexive.\n");
    }

    if (transitive) {
        printf("The relation is transitive.\n");
    } else {
        printf("The relation is not transitive.\n");
    }

    return 0;
}