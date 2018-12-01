#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,f=0;
	char first[20],ans[50],last[20];
	cin>>first;
	cin>>last;
	for(i=0;i<strlen(first)-1;i++)
	{
		ans[i]=first[i];
		if(first[i]<=last[0] && first[i+1]>=last[0])
		{
			ans[i+1]=last[0];
			ans[i+2]='\0';
			f=1;
			break;
		}
		else if(first[i]>=last[0] && first[i+1]>=last[0])
		{
			ans[i+1]=last[0];
			ans[i+2]='\0';
			f=1;
			break;
		}
	}
	if(i==strlen(first)-1 && f==0)
	{
		ans[i]=first[i];
		ans[i+1]=last[0];
		ans[i+2]='\0';
	}
	cout<<ans;
	return 0;
}