#include<bits/stdc++.h>
int countarr[100002];
using namespace std;
int main()
{
	int m,i,l,r,len;
	char ch[100002];
	cin>>ch;
	cin>>m;
	len=strlen(ch);
	countarr[0]=0;
	for(i=0;i<len;i++)
	{
		if(ch[i]==ch[i+1])
			countarr[i+1]=1;
		countarr[i+1]+=countarr[i];
	}
	for (i = 0; i < m; i++)
	{
		cin>>l>>r;
		cout<<countarr[r-1]-countarr[l-1]<<endl;
	}
	return 0;
}