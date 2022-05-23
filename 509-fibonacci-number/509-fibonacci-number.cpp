class Solution {
public:
    int fib(int n) {
        int first = 1;
        int second = 1;
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        int ans = 0;
        for(int i = n-2;i>0;i--) {
            ans = first+second;
            swap(first,second);
            second = ans;
        }
        return ans;
        
    }
};