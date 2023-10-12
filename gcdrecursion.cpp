#include <stdio.h>

// Function to find the HCF of two numbers using recursion
int findHCF(int num1, int num2) {
    if (num2 != 0) {
        return findHCF(num2, num1 % num2);
    } else {
        return num1;
    }
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int hcf = findHCF(num1, num2);

    printf("The HCF of %d and %d is %d\n", num1, num2, hcf);

    return 0;
}
