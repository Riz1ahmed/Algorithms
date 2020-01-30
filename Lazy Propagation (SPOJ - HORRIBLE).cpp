/** Lazy Propagation (spoj.com/problems/HORRIBLE)
Given an N size Array (initially 0) and Q query.
There have 2 Type of Query.
0 l r v = Add v to range[l:r].
1 l r = Print sun of range[l:r].
Note: 1-Based Index. **/
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
struct R{ll v,prop;};
const ll MX=1e5;
R tree[MX*3+5];
ll arr[MX+5];

void init(ll node, ll b, ll e){
	if (b==e){
		tree[node]={0,0};
		return;
	}
	ll left=node*2;
	ll mid=(b+e)/2;
	ll right=node*2+1;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]={tree[left].v+tree[right].v, 0};
}
void update(ll node, ll b, ll e, ll l,ll r,ll v){
	if (e<l || b>r) return;
	if (b>=l && e<=r){
	    tree[node].prop+=v;
	    tree[node].v += v*(e-b+1);
        return;
	}
	ll mid=(b+e)/2;
	ll left=node*2;
	ll right=node*2+1;
	update(left,b,mid,l,r,v);
	update(right,mid+1,e,l,r,v);
	tree[node].v = tree[left].v + tree[right].v + tree[node].prop*(e-b+1);
}
ll query(ll node, ll b, ll e, ll l, ll r, ll c){
	if (b>=l && e<=r)
        return tree[node].v + c*(e-b+1);
	if (e<l || b>r) return 0;
	ll mid=(b+e)/2;
	ll left=node*2;
	ll right=node*2+1;
	ll mxl=query(left,b,mid,l,r,c+tree[node].prop);
	ll mxr=query(right,mid+1,e,l,r,c+tree[node].prop);
	return mxl+mxr;
}
int main(){
	ll t,n,q,type,l,r,val; scanf("%*d");
	while (~scanf("%lld %lld",&n,&q)){
		memset(arr,0,sizeof arr[0]*(n+5));
		init(1,1,n);
		for (int i=0; i<q; i++){
			scanf("%lld",&type);
			if (!type){
				scanf("%lld %lld %lld",&l,&r,&val);
				update(1,1,n,l,r,val);
			}else{
				scanf("%lld %lld",&l,&r);
				printf("%lld\n",query(1,1,n,l,r,0));
			}
		}
	}
	return 0;
}
