#include<bits/stdc++.h>
using namespace std;
void copy(int k);
char check[52][52],ch[52];
int main()
{
	int f=1,i,j,count=1;
	cin>>ch;
	strcpy(check[0],ch);
	for(i=1;i<strlen(ch);i++)
	{
		copy(i);
		f=0;
		for(j=0;j<i;j++)
		{
			if(strcmp(check[j],check[i])==0)
				f=1;
		}
		if(f==0)
			count++;

	}
	cout<<count;
	return 0;
}
void copy(int k)
{
	int i;
	check[k][0]=check[k-1][strlen(ch)-1];
	for (i = 0; i < strlen(ch)-1; i++)
			check[k][i+1]=check[k-1][i];
}