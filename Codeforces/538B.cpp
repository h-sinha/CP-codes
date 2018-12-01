#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,add=1,max=-INT_MAX,temp;
	cin>>n;
	vector<int> v(20);
	while(n)
	{
		temp=n%10;
		for (int i = 19; i > (19-temp); i--)
			v[i]+=add;
		if(temp>max)
			max=temp;
		add*=10;
		n/=10;
	}
	cout<<max<<endl;
	for (int i = 0; i < 20; i++)
	{
		if(v[i])
			cout<<v[i]<<" ";
	}
	return 0;
}