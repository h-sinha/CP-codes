#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int x,y;
	int z,n,countp=0,countm=0;
	cin>>n;
	for (z = 0; z< n; z++)
	{
		cin>>x>>y;
		if(x>0)
			countp++;
		else
			countm++;
	}
	if(countp==0 || countm==0)
		cout<<"Yes"<<endl;
	else if((countp==1 && countm>0) || (countm==1 && countp>0))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}