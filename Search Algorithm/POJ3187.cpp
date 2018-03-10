//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 15;
const int inf = 1e7;

int a[maxn][maxn];

int main(){
	int n, sum;
	while(scanf("%d%d", &n, &sum) == 2){
		for(int i=1; i<=n; i++){
			a[1][i] = i;
		}
		do{
			int tmp = 0;
			for(int i=2; i<=n; i++){
				for(int j=1; j<=n-i+1; j++){
					a[i][j] = a[i-1][j]+a[i-1][j+1];
				}
			}
			if(a[n][1] == sum){
				for(int i=1; i<=n; i++){
					if(i>1) printf(" ");
					printf("%d", a[1][i]);
				}
				printf("\n");
				break;
			}
		}while(next_permutation(a[1]+1, a[1]+n+1));
	} 
	return 0;
} 
