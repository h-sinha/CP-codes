#include<stdio.h>
long long int memory[2001][2001];
long long int multiple(long long int j,long long int n,long long int k);
int main()
{
	long long int n,k,arr[1002],i,temp1=0;
	scanf("%lld %lld",&n,&k);
	for(i=1;i<=n;i++)
	{
			temp1+=multiple(i,n,k-1)%1000000007;
	}
	
	printf("%lld\n",temp1%1000000007);
	return 0;
}
long long int multiple(long long int j,long long int n,long long int k)
{
	int i;
	long long int temp=0;
	if(k==0)
	{
		return 1;
	}
	else if (j>n)
		return 0;
	else if (memory[j][k]!=0)
		return memory[j][k];
	else
	{
		for(i=1;i<=n/j;i++)
		{
			memory[j*i][k-1]=multiple(j*i,n,k-1)%1000000007;
			temp+=memory[j*i][k-1];
		}	
		return temp%1000000007;
	} 	
}