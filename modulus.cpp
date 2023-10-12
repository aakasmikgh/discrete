#include <stdio.h>

#include <conio.h>
int main()
{
int n1,n2,quotient,reminder;
printf("Enter two numbers:\n");
scanf("%d %d",&n1,&n2);
quotient = n1/n2;
reminder = n1 - quotient * n2;
printf("Remainder = %d\n",reminder);
}