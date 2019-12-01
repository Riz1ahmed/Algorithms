#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MX=100000;
ll tree[MX*3+5];
ll arr[MX+5];
void init(ll node, ll b, ll e){
	if (b==e){
		tree[node]=arr[b];
		return;
	}
	ll left=node*2;
	ll mid=(b+e)/2;
	ll right=node*2+1;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=max(tree[left],tree[right]);
}
ll query(ll node, ll b, ll e, ll i, ll j){
	if (b>=i && e<=j)
		return tree[node];
	if (e<i || b>j)
		return 0;
	ll mid=(b+e)/2;
	ll left=node*2;
	ll right=node*2+1;
	ll l_mx=query(left,b,mid,i,j);
	ll r_mx=query(right,mid+1,e,i,j);
	return max(l_mx,r_mx);
}
void update(ll node, ll b, ll e, ll pos){
	if (e==b && e==pos){
		tree[node]=0;
		return;
	}
	if (e<pos || b>pos) return;
	ll mid=(b+e)/2;
	ll left=node*2;
	ll right=node*2+1;
	update(left,b,mid,pos);
	update(right,mid+1,e,pos);
	tree[node]=max(tree[left],tree[right]);
}
int main(){
	ll t,cs=1,n,q,type,pos,l,r,i,val;
	scanf("%lld",&t);
	while (t--){
		scanf("%lld %lld",&n,&q);
		for (i=1; i<=n; i++) arr[i]=i;
		init(1,1,n);
		for (i=0; i<q; i++){
			scanf("%lld",&type);
			if (type==1){
				scanf("%lld",&pos);
				update(1,1,n,pos);
			}else{
				scanf("%lld %lld",&l,&r);
				ll ans=query(1,1,n,l,r);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
