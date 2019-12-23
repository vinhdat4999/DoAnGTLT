#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int a[100000], last, n;
void show()
{
	for(int i=0;i<n*n*n*n;i++)
	{
		if(i!=0 && i%(n*n)==0)
			cout<<endl;
		cout<<setw(2)<<a[i]<<" ";
	}
}
void input()
{
	int i;
	fstream f;
	f.open("input.txt", ios::in);
	f>>n;
	for(i=0;i<n*n*n*n;i++)
		{
			f>>a[i];
		}
	f.close();
}
void output()
{
	int i;
	fstream f;
	f.open("output.txt", ios::out);
	for(i=0;i<n*n*n*n;i++)
		{
			if(i!=0 && i%(n*n)==0)
				f<<endl;
			f<<setw(2)<<a[i]<<" ";
		}
	f.close();
}
bool checkReplace(int m, int x)
{
	int i,k,t;
	int t1, t2, tempX, tempY;
	t1=m%(n*n);
	t2=m/(n*n);
	for(i=(n*n)*t2;i<(n*n)*t2+(n*n);i++)
	{
		if(a[i]==x)
			return true;
	}
	for(i=0;i<(n*n);i++)
	{
		if(a[(n*n)*i+t1]==x)
			return true;
	}
	tempX= t2%n; 
	tempY= t1%n; 
	for (k=t2-tempX; k<=t2-tempX+(n-1); k++) 
		for (t=t1-tempY; t<=t1-tempY+(n-1); t++)
			if (a[k*(n*n)+t]==x)
				return true;
	return false;	
}
int findLast()
{
	int i;
	for(int i=(n*n*n*n)-1;i>=0;i--)
	{
		if(a[i]==0)
			return i;
	}
}
void Try(int i)
{
	while(a[i]!=0)
		i++;
	for(int j=1;j<=(n*n);j++)
	{
		if(checkReplace(i,j)==false)
		{
			a[i]=j;
			if(i==last)
			{
				show();
				output();
				cout<<endl;
				break;
			}
			else
				Try(i+1);
			a[i]=0;
		}
	}
}
int main()
{
	input();
	last=findLast();
	cout<<"     DE BAI\n";
	show();
	cout<<endl<<endl;
	cout<<"     LOI GIAI\n";
	Try(0);
	return 0;
}

