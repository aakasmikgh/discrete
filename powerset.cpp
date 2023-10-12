#include<iostream>
using namespace std;
void findsubsets(int set[],int n){
	for(int i=0;i<(1<<n);i++)
	{
		cout<<"{";
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				cout<<set[j]<<","<<"";
			}
		}
		cout<<"}"<<endl;
	}
}
int main() 
{
int n;
cout<<"Enter the number of elements in the set: ";
cin>>n; 
int set[100];
cout<<"Enter the elements of the set:";
for(int i=0;i<n;i++)
{
	cin>>set[i];
}
cout<<"The subsets of the entered set are:"<<endl;
findsubsets(set,n);
return 0;

}
