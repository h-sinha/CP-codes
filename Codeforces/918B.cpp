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
struct server{
	char ch1[11];
	char ch2[18];
};
struct com{
	char ch1[11];
	char ch2[18];
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	server s[n+1];
	com c[m+1];
	FOR(i,0,n)
	{
	//	scanf("%s[^ ]",s[i].ch1);
	//	scanf("%s[^ ]",s[i].ch2);
		cin>>s[i].ch1>>s[i].ch2;
	//	cout<<s[i].ch2<<" "<<i<<endl;
	//	s[i].ch2[temp]=';';
	//	s[i].ch2[temp+1]='\0';
	}
	int f=1;
	//char c[i].ch1[11],c[i].ch2[18];
	FOR(i,0,m)
	{
		cin>>c[i].ch1>>c[i].ch2;
		//cout<<strlen(c[i].ch2)<<endl;
			FOR(j,0,n)
			{
				f=1;
				int temp=strlen(s[j].ch2);
				if(temp!=strlen(c[i].ch2)-1)continue;
				FOR(k,0,temp)
				{
					if(s[j].ch2[k]!=c[i].ch2[k]){f=0;break;}
				}
				if(f)
				{
					cout<<c[i].ch1<<" "<<c[i].ch2<<" "<<"#"<<s[j].ch1<<endl;
					break;
				}
			}
	}

	return 0;
}		}
			}
	}

	return 0;
}