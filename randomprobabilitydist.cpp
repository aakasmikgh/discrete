#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int N =10;
int main(int argc,char**argv){
int p =0, i;
for(i =0; i < N; i++){
p =rand()%400;
if(p >360)
printf("%d ",0);
else if(p <0)
printf("%d ",0);
else
printf("%f ", p *0.1/360);
}
printf("...");
return 0;
}