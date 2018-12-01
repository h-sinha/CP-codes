#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m=0,a,b,c,pos=0,len,arr[1000002],count=0,init=0;
	cin>>a>>b>>c;
	while(m!=1000000)
	{
		a*=10;
		arr[pos]=a/b;
		if(arr[pos]==c)
		{
			cout<<pos+1<<endl;
			return 0;
		}
		/*else if(arr[pos]==arr[init] && pos!=init)
		{
			count++;
			if(init==0)
				len=pos-init;
			if(len==count)
			{
				cout<<"-1"<<endl;
				return 0;
			}
			init++;
		}
		else if(arr[pos]!=arr[init])
			init=0;*/
		pos++;
		a=a%b;
		m++;
	}
	if(m==1000000)
		cout<<"-1"<<endl;
return 0;
}