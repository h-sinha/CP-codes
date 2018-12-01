#include<bits/stdc++.h>
using namespace std;
char ch[102];
int mem[1002][102],flag=0,ans;
void func(int num,int index);
int num[102];
int main()
{
	int countz=0;
	cin>>ch;
	for (int i = 0; i < strlen(ch); i++)
	{
		num[i]=ch[i]-48;
		if(num[i]==0)
			countz++;
	}
	func(0,0);
	if(flag==1)
	{
		cout<<"YES"<<endl;
		cout<<ans<<endl;
		return 0;
	}
	if(flag==0 && countz!=0)
	{
		cout<<"YES"<<endl;
		cout<<"0"<<endl;
		return 0;
	}
	if(flag==0)
		cout<<"NO"<<endl;
	return 0;
}
void func(int n,int index)
{
	int temp,aux=0;
	if(index>strlen(ch))
		return;
	if(mem[n][index]!=0)
		return;
	if(n%8==0 && n!=0)
	{
		ans=n;
		flag=1;
		return;
	}
	mem[n][index]=1;
	temp=n/10;
	aux=aux*10+temp%10;
	aux=aux*10+n%10;
	func(aux*10+num[index],index+1);
	func(n,index+1);
}