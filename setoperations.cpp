#include <iostream>
using namespace std;
struct set{

int a[10],b[10],c[20],i,flag,m,n;

void un(){
	 cout<<endl<<"Union of the two sets: ";
  for(i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  for(int j=0;j<n;j++)
  {
    flag=0;
    for(i=0;i<n;i++)
    {
      if(a[i]==b[j])
      {
        flag=1;
        break;
      }
    }
        if(flag!=1)
    {
      cout<<b[j]<<" ";
    }
  }
}
void in(){
	cout<<endl<<"Intersection is: ";
  for(int j=0;j<n;j++)
  {
    for(i=0;i<n;i++)
    {
      if(a[i]==b[j])
      {
        cout<<a[i]<<" ";
        break;
      }
    }
  }
}
void ca(){
	cout<<endl<<"Complement of A is: ";
	int k=0,l,i,j,d[10];
for( i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(c[j]==a[i])
             break;
        }
        if(j==n)
        {
            for(l=0;l<k;l++)
            {
                if(d[l]==a[i])
                 break;
            }
            if(l==k)
            {
                d[k]=c[i];
                k++;
            }
        }
        
    }
     for(i=0;i<k;i++)
     {
         cout<<d[i]<<" ";
     }
}
void diff(){
	cout<<endl<<"A-B is: ";
	int k=0,l,i,j,d[10];
    for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[j]==a[i])
             break;
        }
        if(j==n)
        {
            for(l=0;l<k;l++)
            {
                if(c[l]==a[i])
                 break;
            }
            if(l==k)
            {
                d[k]=a[i];
                k++;
            }
        }
        
    }
     for(i=0;i<k;i++)
     {
         cout<<d[i]<<" ";
     }
}
void cb(){
	cout<<endl<<"Complement of B is: ";
	int k=0,l,i,j,d[10];
for( i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(c[i]==b[j])
             break;
        }
        if(j==n)
        {
            for(l=0;l<k;l++)
            {
                if(d[l]==b[i])
                 break;
            }
            if(l==k)
            {
                d[k]=c[i];
                k++;
            }
        }
        
    }
     for(i=0;i<k;i++)
     {
         cout<<d[i]<<" ";
     } 
}
void sd(){
	cout<<endl<<"Symmetric diff. is: ";
	int l,d[10],sy[10],i,j,k=0,m=0,e[10],n1;
	for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[j]==a[i])
             break;
        }
        if(j==n)
        {
            
            for(l=0;l<k;l++)
            {
                if(e[l]==a[i])
                 break;
            }
            if(l==k)
            {
                e[k]=a[i];
                k++;
            }
        }
        
    }
    for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[i]==a[j])
             break;
        }
        if(j==n)
        { 
            for(l=0;l<m;l++)
            {
                if(d[l]==b[i])
                 break;
            }
            if(l==m)
            {
                d[m]=b[i];
                m++;
            }
        }
        
}
    for(i=0;i<k;i++)
    {
        sy[n1]=e[i];
        n1++;
    }
    for(i=0;i<m;i++)
    {
        sy[n1]=d[i];
        n1++;
    }
     for(i=0;i<n1;i++)
     cout<<sy[i]<<" ";
 
}
void cp(){
	cout<<endl<<"Cartesian product is: ";
	cout<<"{";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"("<<a[i]<<","<<b[j]<<")"<<" ";
        }
    }
    cout<<"}";

}

}s;
 main()
{
	int y;
	cout<<"Enter no. of element in universal set: ";
	cin>>s.m;
	cout<<"Enter set of universal: ";
	for(int i=0;i<s.m;i++){
		cin>>s.c[i];
	}
	cout <<"Enter no. of elements in A & B: ";
	cin>>s.n;
	cout<<"Enter set A: ";
	for(int i=0;i<s.n;i++){
		cin>>s.a[i];
	}
	cout<<"Enter set B: ";
	for( int i=0;i<s.n;i++){
		cin>>s.b[i];
	}

			s.un();
		    s.in();
		    s.ca();
		    s.diff();
		    s.cb();
			s.sd();
			s.cp();
}
          
