#include<iostream>
#include<fstream>
using namespace std;
int a[100][100], lastX, lastY;
void show()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
void input()
{
	fstream f;
	f.open("input.txt", ios::in);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			f>>a[i][j];
	f.close();
}
void output()
{
	fstream f;
	f.open("output.txt", ios::out);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			f<<a[i][j]<<" ";
		f<<endl;
	}
	f.close();
}
bool checkReplace(int x, int y, int n)
{
//	kiem tra cot thu x
	for(int j=0;j<9;j++)
		if(a[x][j]==n)
			return true;
//	kiem tra hang thu y
	for(int i=0;i<9;i++)
		if(a[i][y]==n)
			return true;
//	kiem tra vung 3x3 chua o do
	int tempX=(int)(x/3)*3;
	int tempY=(int)(y/3)*3;
	for(int i=tempX;i<tempX+3;i++)
		for(int j=tempY;j<tempY+3;j++)
			if(a[i][j]==n)
				return true;
	return false;
}
int findLastX()
{
	int i,j;
	for(i=8;i>=0;i--)
		for(int j=8;j>=0;j--)
		if(a[i][j]==0)
			return i;
}
int findLastY()
{
	int i,j;
	for(i=8;i>=0;i--)
		for(int j=8;j>=0;j--)
		if(a[i][j]==0)
			return j;
}
void Try(int i, int j)
{
	while(a[i][j]!=0)
	{
		if(j==8)
		{
			i++;
			j=0;
		}
		else
			j++;
	}
	for(int k=1;k<=9;k++)
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
				if(j==8)
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
	cout<<endl<<endl;
	cout<<"     LOI GIAI\n";
	Try(0,0);
	return 0;
}

