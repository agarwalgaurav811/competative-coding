/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    queue < pair<__typeof(A),int> > q;
    q.push(make_pair(A,0));
    map<long long,vector<int> > M;
    while(!q.empty())
    {
        auto(v) = q.front().first;
        int cur_level = q.front().second;
        q.pop();
        if(v!=NULL){
        if(M.find(cur_level)!=M.end())
            M[cur_level].push_back(v->val);
        else{
            M[cur_level]= vector<int>(1,v->val);
           // M[cur_level].clear();
        }
        q.push(make_pair(v->left,cur_level+1));
        q.push(make_pair(v->right,cur_level+1));
        }
    }
    vector<vector<int> > ans(M.size());
    for(long long i=0;i<M.size();i++){
      //  cout<<M[i][0]<<endl;
        ans[i]=vector<int>(M[i].begin(),M[i].end());
    }
    return ans;
}
