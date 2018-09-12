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
#include<cmath>
using namespace std;

typedef long long ll;
const int maxn = 5e4+5;
const ll inf = 1e8;

struct node{
	int id, st, ed;
	bool operator < (const node &rhs) const{
		return st<rhs.st || (st==rhs.st && ed<rhs.ed); 
	}
}p[maxn];

int ans[maxn];

struct pro{
	int id, ed;
	pro(){}
	pro(int id, int ed):id(id), ed(ed){}
	bool operator < (const pro &rhs) const{
		return rhs.ed<ed;
	}
};

priority_queue<pro> q;

int main(){
	int n;
	while(scanf("%d", &n) == 1 && n) {
		while(!q.empty()){
			q.pop();
		}
		for(int i=0; i<n; i++){
			scanf("%d%d", &p[i].st, &p[i].ed);
			p[i].id = i; 
		} 
		sort(p, p+n);
		int cnt = 1;
		q.push(pro(cnt, p[0].ed));
		ans[p[0].id] = cnt;
		for(int i=1; i<n; i++){
			pro u = q.top();
			if(p[i].st<=u.ed){
				cnt++;
				q.push(pro(cnt, p[i].ed));
				ans[p[i].id] = cnt;
			}
			else{
				q.pop();
				ans[p[i].id] = u.id;
				u.ed = p[i].ed;
				q.push(u);
			}
		}
		printf("%d\n", cnt);
		for(int i=0; i<n; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}

