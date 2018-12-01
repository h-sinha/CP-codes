#include<stdio.h>
#include<string.h>
int main()
{
	int  a,i,f=1,temp,temporary,t;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		f=1;
		if(a%i==0)
		{
			temporary=i;
			while(i>0)
			{
				temp=i%10;
				//if(temporary==477)
				//printf("temp %d",temp);
				if(temp!=4 && temp!=7)
					{
						f=0;
						break;
					}
				else
				   i/=10;
			}
				//if(temporary==477)
				//	printf("f%d",f);
			if(f==1)
			{
				//printf("temp=%d",temporary);
				break;
			}
			else
			{
				i=temporary;
			}
		}
	}
	if(f==0)
		printf("NO");
	else
		printf("YES");
	return 0;
}