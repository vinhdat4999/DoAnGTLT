#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
using namespace std;
int a[100][100], lastX, lastY, n;
void show()
{
	for(int i=0;i<n*n;i++)
	{
		for(int j=0;j<n*n;j++)
			cout<<setw(2)<<a[i][j]<<" ";
		cout<<endl;
	}
}
void input()
{
	fstream f;
	f.open("input9x9.txt", ios::in);
	f>>n;
	for(int i=0;i<n*n;i++)
		for(int j=0;j<n*n;j++)
			f>>a[i][j];
	f.close();
}
void output()
{
	fstream f;
	f.open("output.txt", ios::out);
	for(int i=0;i<n*n;i++)
	{
		for(int j=0;j<n*n;j++)
			f<<setw(2)<<a[i][j]<<" ";
		f<<endl;
	}
	f.close();
}
bool checkReplace(int x, int y, int k)
{
//	kiem tra hang thu x
	for(int j=0;j<n*n;j++)
		if(a[x][j]==k)
			return true;
//	kiem tra cot thu y
	for(int i=0;i<n*n;i++)
		if(a[i][y]==k)
			return true;
//	kiem tra vung nxn chua o do
	int tempX=(int)(x/n)*n;
	int tempY=(int)(y/n)*n;
	for(int i=tempX;i<tempX+n;i++)
		for(int j=tempY;j<tempY+n;j++)
			if(a[i][j]==k)
				return true;
	return false;
}
int findLastX()
{
	int i,j;
	for(i=n*n-1;i>=0;i--)
		for(int j=n*n-1;j>=0;j--)
		if(a[i][j]==0)
			return i;
}
int findLastY()
{
	int i,j;
	for(i=n*n-1;i>=0;i--)
		for(int j=n*n-1;j>=0;j--)
		if(a[i][j]==0)
			return j;
}
void Try(int i, int j)
{
	while(a[i][j]!=0)
	{
		if(j==n*n-1)
		{
			i++;
			j=0;
		}
		else
			j++;
	}
	for(int k=1;k<=n*n;k++)
	{
		if(checkReplace(i,j,k)==false)
		{
			a[i][j]=k;
			if(i==lastX && j==lastY)
			{
				show();
				output();
				cout<<endl;
				break;
			}
			else
			{
				if(j==n*n-1)
					Try(i+1,0);
				else
					Try(i,j+1);
			}
			a[i][j]=0;
		}
	}
}
int main()
{
	input();
	lastX=findLastX();
	lastY=findLastY();
	cout<<"     DE BAI\n";
	show();
	cout<<"\n\n Nhan phim bat ky de giai...\n";
	getch();
	cout<<endl<<endl;
	cout<<"     LOI GIAI\n";
	Try(0,0);
	return 0;
}

