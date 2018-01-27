#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 100010
using namespace std;

int n,minx,root,delta,tot;
struct Tree{
	int ch[2],val,fa,siz;
	#define fa(x) tree[x].fa
	#define val(x) tree[x].val
	#define c(x,y) tree[x].ch[y]
	#define siz(x) tree[x].siz
}tree[maxn];
void Update(int x){
	if(!x)return;
	siz(x)=siz(c(x,0))+siz(c(x,1))+1;
}
void Rotate(int p,int x){
	int mark= p==c(x,1),y=c(p,mark^1),z=fa(x);
	if(x==c(z,0))c(z,0)=p;
	else if(x==c(z,1))c(z,1)=p;
	if(y)fa(y)=x;
	c(p,mark^1)=x;fa(p)=z;c(x,mark)=y;fa(x)=p;
	Update(x);
}
void Splay(int p){
	while(fa(p)){
		int x=fa(p),y=fa(x);
		if(!y)Rotate(p,x);
		else if(p==c(x,0)^x==c(y,0))Rotate(p,x),Rotate(p,y);
		else Rotate(x,y),Rotate(p,x);
	}Update(p);root=p;
}
void Insert(int t){
	int now=root,fa=root;
	while(now){
		fa=now;siz(now)++;
		if(t<=val(now))now=c(now,0);
		else now=c(now,1);
	}
	++tot;val(tot)=t;siz(tot)=1;fa(tot)=fa;
	int k=fa;
	if(fa)
		if(t<=val(fa))c(fa,0)=tot;
		else c(fa,1)=tot;
	Splay(tot);
}
int inf=0x7fffffff/2;
int Pre(int t){
	int now=root,fa=0,ans=-inf;
	while(now){
		if(t<=val(now))now=c(now,0);
		else{
		   if(ans<=val(now)){
		  	 ans=val(now);
		 	 fa=now;
		   }
		  now=c(now,1);
		}
	}
	if(fa){Splay(fa);return 0;}
	return 1;
}
int P;
void Erase(int t){
	if(Pre(t))return;
	P+=siz(root)-siz(c(root,1));
	root=c(root,1);
	fa(root)=0;
}
int Kth(int k){
	if(k>siz(root))return -1;
	int now=root;
	k=siz(root)-k+1;
	while(now){
		if(k>siz(c(now,0))){
			k-=siz(c(now,0))+1;
			if(!k)return val(now)+delta;
			now=c(now,1);
		}else now=c(now,0);
	}
}
int main(){
	scanf("%d%d",&n,&minx);
	for(int i=1;i<=n;i++){
		int k;char ch=getchar();
		while(ch<'!')ch=getchar();
		scanf("%d",&k);
		switch(ch){
			case 'I':if(k>=minx)Insert(k-delta);break;
			case 'A':delta+=k;break;
			case 'S':delta-=k;Erase(minx-delta);break;
			case 'F':printf("%d\n",Kth(k));break;
		}
	}printf("%d",P);
	return 0;
}