#include<iostream>
using namespace std;
int a[100],dem=0;
void input()
{
	int i, temp;
	FILE *f;
	f = fopen("output.txt", "r");
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
	int i,k,t,s;
	int t1, t2, tempX, tempY;
	t1=n%9;
	t2=n/9;
	s=0;
	for(i=9*t2;i<9*t2+9;i++)//hang
	{
		s+=a[i];
	}
	if(s!=45)
			return true;
	s=0;
	for(i=0;i<9;i++)
	{
		s+=a[9*i+t1];
	}
	if(s!=45)
			return true;
	s=0;
	tempX= t2%3; 
	tempY= t1%3; 
	for (k=t2-tempX; k<=t2-tempX+2; k++) 
		for (t=t1-tempY; t<=t1-tempY+2; t++)
			s+=a[k*9+t];
			if (s!=45)
				return true;
	return false;	
}
main()
{
	input();
	show();
	for(int i=0;i<81;i++)
		for(int j=1;j<=9;j++)
			if(checkReplace(i,j)==true)
			{
				dem++;
			}
	if(dem==0)
		cout<<"OK";
	else
		cout<<" Fail";
}
