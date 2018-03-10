
//Given a number N, find all factors of N.

vector<int> Solution::allFactors(int A) {
    vector<int> result;
    if ( A > 0 ) {
        
        int n = (int)sqrt(A);
        
        result.push_back(1);
        
        for (int i = 2; i <= n; i++) {
            if ( A % i == 0 ) {
                result.push_back(i);
            }
        }
        
        for (int i = result.size()-1; i>=0; i-- ) {
            if ( A / result[i] > n) {
                result.push_back( A / result[i] );
            }
        }
    } 
    
    return result;
    
}
