#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
std::map<int, int> aux;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len,k,f=0;
	cin>>k;
	int temp=k;
	char ch[102];
	cin>>ch;
	len=strlen(ch);
	FOR(i,0,len)counter[ch[i]-'a']++;
	FOR(i,0,26)if(counter[i]!=0)k--;
	if(len==1)
	{
		if(temp!=1)cout<<"IMPOSSIBLE";
		else
		{
			if(ch[0]!='?')cout<<ch[0];
			else cout<<"a";
		}
		return 0;
	}
	int co=0;
	FOR(i,0,len/2)if(ch[i]=='?' && ch[len-i-1]=='?')co++;
	if(len%2 && ch[len/2]=='?')co++;
	int start=0;
	for (int i = 0; i <= len/2; i++)
	{
		if(ch[i]!=ch[len-i-1] && ch[i]!='?' && ch[len-i-1]!='?')
		{
			cout<<"IMPOSSIBLE";
			return 0;
		}
		else if(ch[i]==ch[len-i-1] && ch[i]!='?')continue;
		else if(ch[i]!=ch[len-i-1] && ch[i]!='?' && ch[len-i-1]=='?')
			ch[len-i-1]=ch[i];
		else if(ch[i]!=ch[len-i-1] && ch[i]=='?' && ch[len-i-1]!='?')
			ch[i]=ch[len-i-1];
		else
		{
			if(counter[0]==0)k--;
			if(co==k)
			{
				while(counter[start]!=0 && start<26)start++;
				f=1;
			}
			ch[i]=char(start+'a');
			ch[len-i-1]=ch[i];
			counter[start]++;
			co--;
			if(f)k--;
		}
	}
	start=0;
	FOR(i,0,len)aux[ch[i]-'a']++;
	FOR(i,0,26)if(aux[i])start++;
	if(start<temp){cout<<"IMPOSSIBLE";return 0;}
	FOR(i,0,len)cout<<ch[i];
	return 0;
}