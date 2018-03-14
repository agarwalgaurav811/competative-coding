//You are given a sequence of points and the order in which you need to cover the points.
//Give the minimum number of steps in which you can achieve it. You start from the first point.

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int n=A.size();
    int move=0;
    for(int i=0;i<n-1;i++)
    {
        int x=A[i+1]-A[i];
        int y=B[i+1]-B[i];
        if(x<0)
          x=-x;
        if(y<0)
          y=-y;
        int m=max(x,y);
            move+=m;

    }
    return move;
    
}
