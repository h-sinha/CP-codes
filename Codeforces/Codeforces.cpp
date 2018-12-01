#include<stdio.h>
int main()
{
	int arr[110],n,k,x,sum=0,i;
	scanf("%d%d%d\n",&n,&k,&x);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	for(i=n-k;i<n;i++)
	{
		sum-=arr[i];
	}
	sum+=k*x;
	printf("%d",sum);
	return 0;
}