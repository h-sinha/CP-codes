#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
char str[55],arr[55][55];
	char ch[102];
int n,m,ans=0,i,j,starti,startj,endi,endj;
int func(int left,int right,int up,int down);
int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>str;
		for (j = 0; j <m ; j++)
		{
			if(str[j]=='.')
				arr[i][j]='.';
			if(str[j]=='#')
				arr[i][j]='#';
			if(str[j]=='S')
			{
				arr[i][j]='S';
				starti=i;
				startj=j;
			}
			if(str[j]=='E')
				arr[i][j]='E';
		}
	}
	cin>>ch;
	if(func(48,49,50,51))
		ans++;
	if(func(48,49,51,50))
		ans++;
	if(func(48,50,49,51))
		ans++;
	if(func(48,50,51,49))
		ans++;
	if(func(48,51,49,50))
		ans++;
	if(func(48,51,50,49))
		ans++;
	if(func(49,48,50,51))
		ans++;
	if(func(49,48,51,50))
		ans++;
	if(func(49,50,48,51))
		ans++;
	if(func(49,50,51,48))
		ans++;
	if(func(49,51,48,50))
		ans++;
	if(func(49,51,50,48))
		ans++;
	if(func(50,49,48,51))
		ans++;
	if(func(50,49,51,48))
		ans++;
	if(func(50,48,49,51))
		ans++;
	if(func(50,48,51,49))
		ans++;
	if(func(50,51,49,48))
		ans++;
	if(func(50,51,48,49))
		ans++;
	if(func(51,49,50,48))
		ans++;
	if(func(51,49,48,50))
		ans++;
	if(func(51,50,49,48))
		ans++;
	if(func(51,50,48,49))
		ans++;
	if(func(51,48,49,50))
		ans++;
	if(func(51,48,50,49))
		ans++;
	cout<<ans;
	return 0;
}
int func(int left,int right,int up,int down)
{
	int posi=starti,posj=startj;
	for(i=0;i<strlen(ch);i++)
	{
		if(int(ch[i])==left)
			posj--;
		if(int(ch[i])==right)
			posj++;
		if(int(ch[i])==up)
			posi++;
		if(int(ch[i])==down)
			posi--;
		if(arr[posi][posj]=='E')
			return 1;
		if(arr[posi][posj]=='#')
			return 0;
		if(posi<0||posi>=n||posj<0||posj>=m)
			return 0;
	}
	return 0;
}