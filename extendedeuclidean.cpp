//WAP to implement euclidean and extended euclidean algorithm.
#include<iostream>
using namespace std;
int gcd(int a,int b){
	while(b!=0){
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
int extendedgcd(int a,int b,int &x,int&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int x1,y1;
	int gcd=extendedgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return gcd;
}
int main(){
	int a,b;
	cout<<"Enter two nums:";
	cin>>a>>b;
	cout<<"GCD of "<<a<<" and "<<b<<" using euclidean algorithm is: "<<gcd(a,b)<<endl;
	int x,y;
	int gcd_extended=extendedgcd(a,b,x,y);
	cout<<"GCD of "<<a<<" and "<<b<<" using extended euclidean algorithmn is: "<<gcd_extended<<endl;
	cout<<"Coefficients x and y:"<<x<<" ,"<<y<<endl;
	return 0;
}
