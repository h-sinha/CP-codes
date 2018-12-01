#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,num,count1=0,count2=0;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>num;
		if(num==1)
			count1++;
		else
			count2++;
	}
	if(count1>count2)
		cout<<count2+(count1-count2)/3;
	else
		cout<<count1;
	return 0;
}