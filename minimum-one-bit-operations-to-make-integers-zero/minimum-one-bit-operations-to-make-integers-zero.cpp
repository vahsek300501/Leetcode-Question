class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int len = 0;
        int cur = n;
        while(cur){
            len++;
            cur = cur>>1;
        }
        int res =  (1<<(len-1)) + minimumOneBitOperations( n ^ ( 3 << (len-2) ) );
        return res;
    }
};