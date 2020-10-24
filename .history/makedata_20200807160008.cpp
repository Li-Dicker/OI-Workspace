#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int FA[maxn],N;

int union_find(int x)//并查集判环 
{
	if(FA[x]==x)return x;
	else return FA[x]=union_find(FA[x]);//返回时进行赋值查找效率变为：O(1) 
}
int main()
{
	N=200000;                     //通过改变N的规模改变数据规模大小 
	cout<<N<<'\n';
	
	// for(int i=1;i<=N;i++)
	// {
	// 	//随机数的奇偶性决定正负 
	// 	if(rand()%2){cout<<rand()%N<<' ';}
	// 	else cout<<-rand()%N<<' ';
	// }
	// cout<<'\n';
	
	for(int i=1;i<=N;i++)FA[i]=i;//父节点初始化 
	int mid=N*700;//边的随机数量应该要多一些，以保证整个图的连通 
	while(mid--)
	{
		int a=rand()%N+1,b=rand()%N+1;
		int fa=union_find(a),fb=union_find(b);
		if(fa==fb)continue;//父节点相同时连这条边将成环 
		else
		{	
//		    cout<<"a: "<<a<<" b: "<<b<<'\n';
//		    cout<<"fa: "<<fa<<" fb: "<<fb<<'\n';
//这个地方之前写错了 
			FA[fa]=fb;
			cout<<a<<' '<<b<<'\n';//否则连这条边 
		}
	}
}