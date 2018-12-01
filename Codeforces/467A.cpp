#include<stdio.h>
int main()
{
	int n,p[500],q[500],count=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		scanf("%d",&q[i]);
	}
	 for(i=0;i<n;i++)
        {
		if(q[i]-p[i]>=2)
			count++;
	}
	 printf("%d",count);
	return 0;
}