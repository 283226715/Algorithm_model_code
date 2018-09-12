//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
using namespace std;

typedef long long ll;
const int maxn = 1e3+5;

priority_queue<ll, vector<ll>, greater<ll> > q;

int main(){
	ll n;
	while(scanf("%lld", &n) == 1){
		for(int i=0; i<n; i++){
			ll num;
			scanf("%lld", &num);
			q.push(num);
		}
		ll ans = 0;
		while(q.size()>1){
			ll a = q.top(); q.pop();
			ll b = q.top(); q.pop();
			ans += a+b;
			q.push(a+b);
		}
		printf("%lld\n", ans);
		q.pop();
	}
	return 0;
}

