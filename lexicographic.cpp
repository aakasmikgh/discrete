#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	string input;
	cout<<"Enter a string:";
	cin>>input;
	sort(input.begin(),input.end());
	cout<<"Lexicographic ordering of letters in entered string:"<<input<<endl;
	return 0;
}