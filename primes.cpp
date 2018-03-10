//Given a number N, find all prime numbers upto N ( N included ).

// method used:seive of eratosthenes
//mine sol
vector<int> Solution::sieve(int A) {
    vector <bool> v(A+1);
    v[0]=false;
    v[1]=false;
    vector <int> primes;
    for(int i=2;i<=A;i++)
      v[i]=true;
    for(int i=2;i<=A;i++)
    {
        
        if(v[i]){
           for(int j=2;j*i<=A;j++)
               v[j*i]=false;
            primes.push_back(i);
        }
    }
    return primes;
}

//other
vector<int> Solution::sieve(int A) {
    
    if (A <= 1)
        return vector<int>{};
        
    vector<int> primes;
    int limit = floor(sqrt(A));
    for (int i = 2; i <= limit; i++) {
        bool is_prime = true;
        for (int j = 0; j < primes.size() && primes[j] < i; j++) {
            if (i % primes[j] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            primes.push_back(i);
    }
    
    vector<int> res = primes;
    for (int i = limit+1; i <= A; i++) {
        bool is_prime = true;
        for (auto j: primes) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            res.push_back(i);
    }
    
    return res;
}

