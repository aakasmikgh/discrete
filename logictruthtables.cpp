#include <stdio.h>

int main() {
    int p, q;

    printf("Truth Table for Logical Operators\n\n");
    printf("P\tQ\tAND\tOR\tNOT P\tP -> Q\tP <-> Q\n");
    printf("--------------------------------------------\n");

    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            int conjunction = p && q;
            int disjunction = p || q;
            int negation_p = !p;
            int implication = (!p) || q;
            int bi_implication = (p && q) || (!p && !q);

            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p, q, conjunction, disjunction, negation_p, implication, bi_implication);
        }
    }

    return 0;
}
