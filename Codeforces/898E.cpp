#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main()
{
	ll n,counter=0,ans=0,cnt=0;
	cin>>n;
	std::vector<ll> v(n+1);
	int aux[1000000];
	for (int i = 1; i <=n; i++)
	{
		cin>>v[i];
		if(v[i]==0)
			cnt++;
		int iRoot = static_cast<int>(sqrt(static_cast<float>(v[i])) + .5f);
		ll temp=int(sqrt(v[i]));
		if(abs(v[i]-(temp*temp))>=abs((iRoot*iRoot)-v[i]))
			aux[i-1]=abs((iRoot*iRoot)-v[i]);
		else
			aux[i-1]=abs(v[i]-(temp*temp));
	}
	cout<<endl;
	sort(aux,aux+n);
	for (int i = 0; i <=n; i++)
	{
			if(aux[i]<0)
				continue;
			else if(counter==n/2)
			{
				break;
			}
			else
				{
					ans+=aux[i];
					counter++;
				}
	}
	ll countz=0;
	for(int i=0;i<n;i++)
	{
		if(aux[i]==0)
			countz++;
	}
	if(countz>n/2)
	{
		ll diff=countz-cnt;
		if(cnt>n/2)
		{
			ans+=2*(cnt-n/2);
			ans+=diff;
		}
		else
		{
			ans+=(diff-(n/2-cnt));
		}
	}
	cout<<ans<<endl;
	return 0;
}