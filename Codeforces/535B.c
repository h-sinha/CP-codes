#include <stdio.h>
#include <math.h>
int main()
{
	long long int n;
	scanf("%lld", &n);
	int count = 0;
	long long int ans = 0, cur = 1, digit;
	while(n>0)
	{
		digit = n%10;
		if(digit == 7)ans += cur;
		n /= 10;
		cur *= 2;
		count++;
	}
	ans--;
	ans += pow(2,count);
	printf("%lld\n",ans);
}