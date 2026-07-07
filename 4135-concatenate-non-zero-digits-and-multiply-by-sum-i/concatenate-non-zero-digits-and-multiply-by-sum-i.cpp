class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        long long x=1;
        long long sum=0;
        while(n>0){
            int y=n%10;
            if(y!=0){
                sum+=y;
                ans=ans+y*x;
                x*=10;
            }
            n/=10;

        }
        return ans*sum;

    }
};