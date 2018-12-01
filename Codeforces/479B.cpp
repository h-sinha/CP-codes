#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,counter=0,maxpos,minpos;
	cin>>n>>k;
	std::vector<int> v(n+1);
	std::vector<int> ans1(1002);
	std::vector<int> ans2(1002);
	int max=INT_MIN,min=INT_MAX;
	for (int i = 0; i < n; i++)
	{
		cin>>v[i];
		if(v[i]>max)
		{
			max=v[i];
			maxpos=i;
		}
		if(v[i]<min)
		{
			min=v[i];
			minpos=i;
		}
	}
	int diff=max-min;
	while(counter<k && diff>1)
	{
		ans1[counter]=maxpos+1;
		ans2[counter]=minpos+1;
		v[maxpos]--;
		v[minpos]++;
		counter++;
		max=INT_MIN;
		min=INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if(v[i]>max)
			{
				max=v[i];
				maxpos=i;
			}
			if(v[i]<min)
			{
				min=v[i];
				minpos=i;
			}
		}
		diff=max-min;
	}
	cout<<diff<<" "<<counter<<endl;
	for (int i = 0; i < counter; i++)
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	return 0;
}