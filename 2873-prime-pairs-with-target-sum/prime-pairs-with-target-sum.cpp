class Solution {
public:

    void sieve(int N,vector<bool>&is_prime,vector<int>&primes)
    {
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <=N; ++i)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <=N; j += i)
                    is_prime[j] = false;
            }
        }
        for (int i = 2; i <=N; ++i)
        {
            if (is_prime[i])
                primes.push_back(i);
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<int>prime;
        vector<bool>is_prime(n+1,true);
        sieve(n,is_prime,prime);
        sort(prime.begin(),prime.end());
        int i=0,j=prime.size()-1;
        vector<vector<int>>ans;
        while(i<=j){
            int s=prime[i]+prime[j];
            if(s==n){
                ans.push_back({prime[i],prime[j]});
                i++;
                j--;
            }
            else if(s>n){
                j--;

            
            }
            else{
                i++;
            }
        }
        return ans;

    }
};