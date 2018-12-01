#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef long double ld;
int main()
{
	int change,len,n,k,x,ans=INT_MIN,temp,pos;
	cin>>n>>k>>x;
	std::vector<int> org(105);
	std::vector<int> b(105);
	std::vector<int> c(105);
	FOR(i,0,n)cin>>org[i];
	FOR(i,0,n)
	{
		b[i]=x;
		int k=0;
		FOR(j,0,n)
		{
			if(j==i)k++;
			b[k]=org[j];
			k++;
		}
		change=1,len=n+1;
		while(change)
		{
			change=0;
			FOR(j,0,len-2)
			{
				if(b[j]==b[j+1] && b[j+1]==b[j+2])
				{
					pos=j+2;
					while(pos<len && b[pos]==b[j])
						pos++;
					if(b[pos]!=b[j] || pos==len)pos--;
					while(pos!=j-1){b[pos]=-1;pos--;}
					change=1;
					k=0;
					FOR(l,0,len)
					{
						if(b[l]==-1)continue;
						c[k]=b[l];k++;
					}
					len=k;
					FOR(l,0,len)b[l]=c[l];
				}
			}
		}
	
		if(n-len>ans){ans=n-len;//FOR(i,0,len)//cout<<b[i]<<" ";
	//cout<<endl;
		}
	}
	if(ans==-1)cout<<"0";
	else cout<<ans;
	return 0;
}