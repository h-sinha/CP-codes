#include<stdio.h>
#include<string.h>
int main()
{
int i,f=0;
char ch[100];
scanf("%s",ch);
  for(i=1;i<strlen(ch);i++)
                {
                        if(ch[i]<123 && ch[i]>96)
                                f=1;

                }

 if(ch[0]<123 && ch[0]>96)
        {
		if(f==0)
		{
			ch[0]-=32;
			for(i=1;i<strlen(ch);i++)
			{
                		ch[i]+=32;
			}
		}
        }
 else if(f==0 && ch[0]<91 && ch[0]>64)
 {
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]<91 && ch[i]>64)
	{
		ch[i]+=32;
	}
	
	}
 }

printf("%s",ch);
return 0;
}