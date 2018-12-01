#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main()
{
	int n,d,ch[102];
	char str[102];
	cin>>n>>d;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1')
			ch[i]=1;
		else
			ch[i]=0;
	}
	int pos=0;
	int f=0,ans=0;
	while(pos<n-1)
	{
		f=0;
		for(int i=d;i>0;i--)
		{
			if(ch[pos+i]==1 && pos+i<n)
			{
				pos+=i;
				f=1;
				ans++;
				break;
			}
		}		
		if(f==0)
			break;
	}
	if(pos==n-1)
		cout<<ans;
	else
		cout<<"-1";
	return 0;
}