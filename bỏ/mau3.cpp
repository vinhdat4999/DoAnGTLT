#include<iostream>
using namespace std;
int a[100];
void Nhap()
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
int checkRepla(int n)
{
	int j;
	for(j=n*9;j<n*9+9;j++)
		cout<<j<<" ";
	for(j=n;j<=72+n;j+=9)
		cout<<j<<" ";
	for(int i=((27*(n/3))+(3*(n%3)));i<=(27*(n/3))+(3*(n%3))+18;i+=9)
		for(int j=i;j<=i+2;j++)
			cout<<j<<" ";
}
int checkReplace(int i, int x)
{
//	int j;
//	for(j=n*9;j<n*9+9;j++)
//	{
//		if(a[j]==x)
//			return 0;
//	}
//	for(j=n;j<=72+n;j+=9)
//	{
//		if(a[j]==x)
//			return 0;
//	}
//	for(int i=((27*(n/3))+(3*(n%3)));i<=(27*(n/3))+(3*(n%3))+18;i+=9)
//		for(int j=i;j<=i+2;j++)
//		{
//			if(a[j]==x)   
//				return 0;
//		}
//	return 1;
	int k,t,t1,t2;
	int kth, ktc, kto; 
	int tmpX, tmpY; 
	//kiem tra hang thu i da co cai nao trung chua
	t1=i%9; 
	t2=i/9; 
	for (k=(t2*9); k<(t2*9+9); k++)
		if (a[k]==x) 
			return 0; 
	//kiem tra cot thu j da co cai nao trung chua
	for (k=0; k<9; k++) 
		if (a[k*9+t1]==x) 
			return 0; 
	//kiem tra trong o 3x3
	tmpX= t2%3; 
	tmpY= t1%3; 
	for (k=t2-tmpX; k<=t2-tmpX+2; k++) 
		for (t=t1-tmpY; t<=t1-tmpY+2; t++)
			if (a[k*9+t]==x) 
				return 0; 
			return 1;
}
int findLastBox()
{
	int i;
	for(i=80;i>=0;i--)
		if(a[i]==0)
			return i;
	return -1;
}
int main()
{
	Nhap();
	for(int i=0;i<81;i++)
	{
		if(a[i]==0)
		{
			for(int j=1;j<=9;j++)
			{
				if(checkReplace(i,j)==1)
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
//	cout<<endl;
//	cout<<" Nhap n : ";
//	int n;
//	cin>>n;
//	checkRepla(n);
//	cout<<findLastBox();
return 0;
}
