// #include<bits/stdc++.h>
// #define int long long
// #define N 111111
// #define INF 0x3f3f3f3f
// using namespace std;

// int n,q,lnum=0,rnum=0,x,t;
// int pos[N],des[N];
// char dest[N];
// struct Point
// {
// 	int id,pos;
// }ld[N],rd[N];

// namespace IOstream
// {
// 	#define int long long
// 	#define print(a,b) prints(a),putchar(b)
// 	int BUF[22],BUFSIZE,IONUM,SIGN;
// 	char GET;

// 	inline int input()
// 	{
// 		IONUM=0,SIGN=1;
// 		GET=getchar();
// 		while (GET<'0'||GET>'9')
// 		{
// 			if (GET=='-')
// 				SIGN=-1;
// 			GET=getchar();
// 		}
// 		while (GET>='0'&&GET<='9')
// 		{
// 			IONUM=(IONUM<<3)+(IONUM<<1)+(GET&15);
// 			GET=getchar();
// 		}
// 		return SIGN*IONUM;
// 	}

// 	inline void prints(int IONUM)
// 	{
// 		if (IONUM<0)
// 			IONUM=-IONUM,putchar('-');
// 		do
// 			BUF[++BUFSIZE]=IONUM%10,IONUM/=10;
// 		while (IONUM);
// 		while (BUFSIZE)
// 			putchar(BUF[BUFSIZE--]+'0');
// 	}

// }
// using namespace IOstream;

// bool cmp(Point a,Point b)
// {
// 	return a.pos<b.pos;
// }

// int find(int x,int t)
// {
// 	Point q;
// 	q.id=0,q.pos=pos[x];
// 	int lpos=lower_bound(ld+1,ld+lnum+1,q,cmp)-ld,rpos=lower_bound(rd+1,rd+rnum+1,q,cmp)-rd,last=0;
// 	if (des[x]==-1)
// 	{
// 		rpos--;
// 		if ((!rpos)||ld[lpos].pos-rd[rpos].pos>t*2)
// 			last=x;
// 		else
// 		{
// 			int l=1,r=min(lnum-lpos+1,rpos)+1,mid=0;
// 			while ((l+r)/2!=mid)
// 			{
// 				mid=(l+r)/2;
// 				if (ld[lpos+mid-1].pos-rd[rpos-mid+1].pos<=t*2)
// 					l=mid;
// 				else
// 					r=mid;
// 			}
// 			if (lpos+l<=lnum&&ld[lpos+l].pos-rd[rpos-l+1].pos<=t*2)
// 				last=ld[lpos+l].id;
// 			else
// 				last=rd[rpos-l+1].id;
// 		}
// 	}
// 	else
// 	{
// 		if (lpos>lnum||ld[lpos].pos-rd[lpos].pos>t*2)
// 			last=x;
// 		else 
// 		{
// 			int l=1,r=min(lnum-lpos+1,lpos)+1,mid=0;
// 			while ((l+r)/2!=mid)
// 			{
// 				mid=(l+r)/2;
// 				if (ld[lpos+mid-1].pos-rd[lpos-mid+1].pos<=t*2)
// 					l=mid;
// 				else
// 					r=mid;
// 			}
// 			if (l!=lpos&&ld[lpos+l-1].pos-rd[lpos-l].pos<=t*2)
// 				last=rd[lpos-l].id;
// 			else
// 				last=ld[lpos+l-1].id;
// 		}
// 	}
// 	return abs(pos[last]+des[last]*t);
// }

// signed main()
// {
// 	n=input(),q=input();
// 	for (int i=0;i<n;i++)
// 		pos[i]=input();
// 	cin>>dest;
// 	for (int i=0;i<n;i++)
// 	{
// 		if (dest[i]=='L')
// 			des[i]=-1,ld[++lnum].id=i,ld[lnum].pos=pos[i];
// 		else
// 			des[i]=1,rd[++rnum].id=i,rd[rnum].pos=pos[i];
// 	}
// 	sort(ld+1,ld+lnum+1,cmp);
// 	sort(rd+1,rd+rnum+1,cmp);
// 	while (q--)
// 	{
// 		x=input()-1,t=input();
// 		print(find(x,t),'\n');
// 	}
// 	return 0;
// }
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define fi firsts
#define se second
#define mk make_pair
#define pb push_back

#define N 200005
#define M 1000000007
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,q,pos[N],dir[N],ta,tb,ID,T;
struct Node{int id,pos;}l[N],r[N];
inline bool cmp(Node a,Node b)
{
		 return a.pos<b.pos;
}
int work()
{
		int fin;
		if (dir[ID]==-1)
		{
				int now=lower_bound(l+1,l+ta+1,(Node){0,pos[ID]},cmp)-l; 
				int rnow=lower_bound(r+1,r+tb+1,(Node){0,pos[ID]},cmp)-r;
				--rnow;
				if (!rnow||l[now].pos-r[rnow].pos>T*2) fin=ID;
				else 
				{
						int L=1,R=min(ta-now+1,rnow)+1,mid=0;
						while ((L+R)>>1!=mid)
						{
								mid=(L+R)>>1;
								if (l[now+mid-1].pos-r[rnow-mid+1].pos<=T*2) L=mid; else R=mid; 
						}
						if (now+L<=ta&&l[now+L].pos-r[rnow-L+1].pos<=T*2) fin=l[now+L].id;
						else fin=r[rnow-L+1].id;
				}
		}
		else 
		{
				int lnow=lower_bound(l+1,l+ta+1,(Node){0,pos[ID]},cmp)-l;
				int rnow=lower_bound(r+1,r+tb+1,(Node){0,pos[ID]},cmp)-r;
				if (lnow>ta||l[lnow].pos-r[rnow].pos>T*2) fin=ID;
				else 
				{
						int L=1,R=min(ta-lnow+1,rnow)+1,mid=0;
						while ((L+R)>>1!=mid)
						{
								mid=(L+R)>>1;
								if (l[lnow+mid-1].pos-r[rnow-mid+1].pos<=T*2) L=mid; else R=mid;
						}
						if (L!=rnow&&l[lnow+L-1].pos-r[rnow-L].pos<=T*2) fin=r[rnow-L].id;
						else fin=l[lnow+L-1].id;
				}
		}
		return abs(pos[fin]+dir[fin]*T);
}
char c[N];
inline int read(){
		int x,f=0; char c;
		while (c=getchar(),(c<'0'||c>'9')&&c!='-');
		if (c=='-') f=1,c=getchar();
		x=c-'0';
		while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
		if (f) return -x; 
		return x;
}
class FindingKids{
	public:
		long long getSum()
		{
			n=read(); q=read();
			for (i=0;i<n;++i) pos[i]=read();
			scanf("%s",c);
			for (i=0;i<n;++i)
			{
    		    if (c[i]=='L') dir[i]=-1,l[++ta]=(Node){i,pos[i]};
    		    else dir[i]=1,r[++tb]=(Node){i,pos[i]}; 
			}
			sort(l+1,l+ta+1,cmp);
			sort(r+1,r+tb+1,cmp);
			long long ans=0;
			for (;q--;)
    		{
				ID=read(); T=read();
				--ID;
				printf("%d\n",work());
			}
			return ans;
		}
}MRT;

int main()
{
	 MRT.getSum();
}

