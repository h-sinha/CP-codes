#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
#define pb push_back
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int modu=1000000007;
int mini(int a,int b,int c,int d,int e,int f,int g,int h);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char ch[100002];
	cin>>ch;
	int len=strlen(ch);
	FOR(i,0,len)counter[ch[i]]++;
	cout<<mini(counter['B'],counter['u']/2,counter['l'],counter['b'],counter['a']/2,counter['s'],counter['u'],counter['r']);
	return 0;
}
int mini(int a,int b,int c,int d,int e,int f,int g,int h)
{
	int temp=min(a,b);
	int temp1=min(temp,c);
	int temp2=min(temp1,d);
	int temp3=min(temp2,e);
	int temp4=min(temp3,f);
	int temp5=min(temp4,g);
	int temp6=min(temp5,h);
	return temp6;

}