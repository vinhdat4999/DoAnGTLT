#include<iostream>
#include<fstream>
using namespace std;
int a[100], last;
void show()
{
	for(int i=0;i<81;i++)
	{
		if(i!=0 && i%9==0)
			cout<<endl;
		cout<<a[i]<<" ";
	}
}
void input()
{
	int i;
	fstream f;
	f.open("input.txt", ios::in);
	for(i=0;i<81;i++)
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
	for(i=0;i<81;i++)
		{
			if(i!=0 && i%9==0)
				f<<endl;
			f<<a[i]<<" ";
		}
	f.close();
}
bool checkReplace(int n, int x)
{
	int i,k,t;
	int t1, t2, tempX, tempY;
	t1=n%9;
	t2=n/9;
	for(i=9*t2;i<9*t2+9;i++)
	{
		if(a[i]==x)
			return true;
	}
	for(i=0;i<9;i++)
	{
		if(a[9*i+t1]==x)
			return true;
	}
	
//	tempX= t2%3; 
//	tempY= t1%3; 
//	for (k=t2-tempX; k<=t2-tempX+2; k++) 
//		for (t=t1-tempY; t<=t1-tempY+2; t++)
//			if (a[k*9+t]==x)
//				return true;
	return false;	
}
int findLast()
{
	int i;
	for(int i=80;i>=0;i--)
	{
		if(a[i]==0)
			return i;
	}
}
void Try(int i)
{
	while(a[i]!=0)
		i++;
	for(int j=1;j<=9;j++)
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
	output();
	cout<<endl<<endl;
	cout<<"     LOI GIAI\n";
	Try(0);
	return 0;
}

