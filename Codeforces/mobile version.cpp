#include<stdio.h>
#include<math.h>
int main()
{
	long long n,m,a;
	scanf("%I64d %I64d %I64d",&n,&m,&a);
	if (m%a==0 && n%a==0)
		{
			printf("%I64d",(m/a)*(n/a));
		}
			else if (m%a!=0 && n%a==0)
			{
				printf("%I64d",((m/a)+1)*(n/a));

			}
			 else if (m%a==0 && n%a!=0)
			 {
				 printf("%I64d",(m/a)*((n/a)+1));

			 }
			 else 
			 {
				 printf("%I64d",((m/a)+1)*((n/a)+1));

			 }


	return 0;
}