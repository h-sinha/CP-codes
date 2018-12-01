#include<bits/stdc++.h>
using namespace std;
int f[100];
int fact(int n);
typedef long double ld;
int main()
{
	int i;
	int addp,addm,num,deno,m1=0,p1=0,q2=0,p2=0,m2=0;
	char s1[12],s2[12];
	cin>>s1;
	cin>>s2;
	for(i=0;i<strlen(s1);i++)
	{
		if(s1[i]=='+')
			p1++;
		else
			m1++;
	}
	for(i=0;i<strlen(s2);i++)
	{
		if(s2[i]=='?')
			q2++;
		else if(s2[i]=='+')
			p2++;
		else
			m2++; 	
	}
	if(q2==0)
	{
		if(p1==p2 && m1==m2)
			cout<<"1.000000000000"<<endl;
		else
			cout<<"0.000000000000"<<endl;
		return 0;
	}
	deno=pow(2,q2);
	addp=p1-p2;
	addm=m1-m2;
	if(addp<0 || addm<0 || (addp+addm)>q2)
	{
		cout<<"0.000000000000"<<endl;
		return 0;
	}
	if((addp+addm)==q2)
			num=fact(q2)/(fact(addp)*fact(q2-addp));
	else if (addp==0)
	{
		if((q2-addp)%2!=0)
		{
			cout<<"0.000000000000"<<endl;
			return 0;
		}
		num=(fact(q2)/(fact(addm)*fact(q2-addm)))*(fact(q2-addm)/(fact((q2-addm)/2)*fact((q2-addm)/2)));
	}
	else if (addm==0)
	{
		if((q2-addp)%2!=0)
		{
			cout<<"0.000000000000"<<endl;
			return 0;
		}
		num=(fact(q2)/(fact(addp)*fact(q2-addp)))*(fact(q2-addp)/(fact((q2-addp)/2)*fact((q2-addp)/2)));
	}
	else
	{
		if((q2-addm-addp)%2!=0)
		{
			cout<<"0.000000000000"<<endl;
			return 0;
		}
		num=(fact(q2)/(fact(addp)*fact(q2-addp)))*(fact(q2-addp-addm)/(fact((q2-addp-addm)/2)*fact((q2-addp-addm)/2)))*(fact(q2-addp)/(fact(q2-addp-addm)*fact(addm)));
	}
	printf("%.12lf\n",double(num)/double(deno));
	return 0;
}
int fact(int n)
{
	if(n==1|| n==0)
		return 1;
	if(f[n]!=0)
		return f[n];
	else
		f[n]=n*fact(n-1);
	return f[n];
}