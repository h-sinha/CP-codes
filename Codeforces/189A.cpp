#include<bits/stdc++.h>
using namespace std;
int func(int length);
int n,a,b,c,mem[4002];
int main()
{
	cin>>n>>a>>b>>c;
	cout<<func(n)<<endl;
	return 0;
}
int func(int length)
{
	int temp;
	if(length<0)
		return -INT_MAX;
	if(length==0)
		return 0;
	if(mem[length]!=0)
		return mem[length];
	temp=max(1+func(length-a),1+func(length-b));
	mem[length]=max(temp,1+func(length-c));
	return mem[length];
}