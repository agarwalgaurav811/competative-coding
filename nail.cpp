int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
	//	unordered_map<int,int> m;
		vector<pi> v;
		int mx=0;
		for(int j=0;j<n;j++){
			int x,y;
			cin>>x>>y;
			v.push_back(mp(x,y));
		//	m[x]=max(m[x],y);
			mx=max(mx,y);
		}
		sort(v.begin(),v.end());
		int count=0;
		int range=mx;
		int l=v.size();
		bool remain=true;
		for(int i=0;i<l;i++){
			
			if(v[i].f>range){
			  count++;
			  range=v[i].s;
			  remain=true;
			}
			else if(v[i].f==range){
				count++;
				range=mx;
				remain=false;
			}
			else{
			 range=min(range,v[i].s);
			 remain=true;
			}
		}
		if(remain)
		  count++;
		cout<<count<<endl;
	}
	return 0;
}
