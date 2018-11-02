#include <iostream>
#include <bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define ll long long int
using namespace std;
 
int dist[20][20][11];
int x,y;
int a[]={-1,0,0,1};
int b[]={0,-1,1,0};
int ans;
ll mx;
int l;
//int it=0;
bool issafe(vector<vector<char> >& map,int i,int j){
	if(i>=x || i<0 || j>=y || j<0)
	  return false;
	else if(map[i][j]=='x')
	   return false;
	else
	  return true;
}
 
void getdist(vector<vector<char> >& map,vector<pi>& dirty,int i){
	queue<pi> q;
	int x1,y1;
	x1=dirty[i].first;
	y1=dirty[i].second;
 
	dist[x1][y1][i]=0;
	q.push(mp(x1,y1));
	while(!q.empty()){
		x1=q.front().first;
		y1=q.front().second;
		q.pop();
		for(int j=0;j<4;j++){
			if(issafe(map,x1+a[j],y1+b[j]) && dist[x1+a[j]][y1+b[j]][i]==-1){
				dist[x1+a[j]][y1+b[j]][i]=dist[x1][y1][i]+1;
				q.push(mp(x1+a[j],y1+b[j]));
			}
		}
	}
}
 
int solve(vector<vector<char> >& map,vector<pi>& dirty,vector<vector<int> >& dp,int i,ll mask){
	if(mask==mx){
		return 0;
	}
//	it++;
//	if(it>100)
//	  return 0;
//	cout<<mask<<"    ";
	if(dp[i][mask]!=-1){
	//	cout<<"hello"<<endl;
		return dp[i][mask];
	}
	int rat=INT_MAX;  
	for(int j=0;j<l;j++){
		//cout<<mask<<endl;
		if((mask&(1<<j))==0  && dist[dirty[j].first][dirty[j].second][i]!=-1){
		//	cout<<mask<<" "<<j<<endl;
			rat=min(rat,solve(map,dirty,dp,j,(mask | (1<<j)))+dist[dirty[j].first][dirty[j].second][i]);
		}
	}
//	cout<<endl;
	return dp[i][mask]=rat;
}
int main() {
 
	while(cin>>y>>x){
		if(!x && !y)
		  break;
		vector<vector<char> > map(x,vector<char>(y));
		int x1,y1;
		vector<pi> dirty;
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
 
				cin>>map[i][j];
				if(map[i][j]=='o'){
				   x1=i;
				   y1=j;
				}
				else if(map[i][j]=='*'){
					dirty.push_back(mp(i,j));
				}
			}
		}
		dirty.push_back(mp(x1,y1));
		l=dirty.size();
        memset(dist,-1,sizeof(dist));
		for(int i=0;i<l;i++){
			getdist(map,dirty,i);
		}
		ans=INT_MAX;
		mx=1<<l;
		mx--;
       // cout<<mx<<endl;
		vector<vector<int> >dp(l,vector<int>(1<<l,-1));
		ans=solve(map,dirty,dp,l-1,(1<<(l-1)));
		if(ans==INT_MAX)
		  cout<<-1<<endl;
		else
		  cout<<ans<<endl;
 
	}
	return 0;
}
