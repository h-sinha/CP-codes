#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int ans=0;
	char ch[100];
	cin>>ch;
	for (int i = 0; i < strlen(ch); i++)
	{
		if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u')
			ans++;
		if(ch[i]=='1'||ch[i]=='3'||ch[i]=='5'||ch[i]=='7'||ch[i]=='9')
			ans++;
	}
	cout<<ans;
	return 0;
}