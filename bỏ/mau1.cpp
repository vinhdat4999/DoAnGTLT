#include<iostream>
using namespace std;
int a[100];
void input()
{
	int i, temp;
	FILE *f;
	f = fopen("input.txt", "r");
	for(i=0;i<81;i++)
		{
			fscanf(f,"%d",&temp);
			a[i]=temp;
		}
	fclose(f);
}
void show()
{
	for(int i=0;i<81;i++)
	{
		if(i%9==0)
			cout<<endl;
		cout<<a[i]<<" ";
	}
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
	tempX= t2%3; 
	tempY= t1%3; 
	for (k=t2-tempX; k<=t2-tempX+2; k++) 
		for (t=t1-tempY; t<=t1-tempY+2; t++)
			if (a[k*9+t]==x)
				return true;
	return false;	
}
int findLastK()
{
	int i;
	for(int i=80;i>=0;i--)
	{
		if(a[i]==0)
			return i;
	}
}
int main()
{
	input();
	cout<<" DE BAI ";
	show();
	cout<<endl<<endl;
	for(int i=0;i<81;i++)
	{
		if(a[i]==0)
		{
			for(int j=1;j<=9;j++)
			{
				if(checkReplace(i,j)==false)
				{
					a[i]=j;
					break;
				}
			}
		}
	}
	for(int i=0;i<81;i++)
	{
		if(i!=0 && i%9==0)
			cout<<endl;
		cout<<a[i]<<" ";
	}
	return 0;
}
