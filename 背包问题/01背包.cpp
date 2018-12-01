#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<bitset>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

#include<iomanip>
#include<iostream>


#define debug cout<<"aaa"<<endl
#define d(a) cout<<a<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 100 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int dp[N*10000];
bool p[N][N*10000];

struct node{
	int w,v;
}a[N];

int main(){
	int n,W;
	mem(dp,0);
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].w,&a[i].v);
	}
	for(int i=1;i<=n;i++){
		for(int j=W;j>=a[i].w;j--){
			if(dp[j]<dp[j-a[i].w]+a[i].v){
				dp[j]=dp[j-a[i].w]+a[i].v;
				p[i][j]=1;
			}
		}
	}
	//��¼·�� 
	vector<int> v;
	int i=n,j=W;
	while(i>0&&j>0){
		if(p[i][j]==1){
			v.push_back(i);
			j-=a[i].w;
		}
		i--;
	}
	printf("%d\n",dp[W]);
	return 0;
}
