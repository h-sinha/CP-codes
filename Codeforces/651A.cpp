#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a1,a2,counter=0;
	cin>>a1>>a2;
	while(a1>0 && a2>0)
	{
		if(a1>a2)
		{
			a1-=2;
			a2+=1;
			if(a1>=0)
				counter++;
		}
		else
		{
			a2-=2;
			a1+=1;
			if(a2>=0)
				counter++;
		}	
	}
	cout<<counter<<endl;
	return 0;
}