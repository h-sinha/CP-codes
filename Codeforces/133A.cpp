#include <stdio.h>
#include<string.h>
int main()
{
	int i;
	char arr[100],f=0;
	scanf("%s",&arr);
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i]=='H'||arr[i]=='Q'||arr[i]=='9')
		{
			printf("YES");
			f=1;
			break;
		}
		else
			f=0;	
	}
	if(f==0)
		printf("NO");
	return 0;
}