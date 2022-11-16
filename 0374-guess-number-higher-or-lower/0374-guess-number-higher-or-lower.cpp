/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 0;
        int e = n;
        while(s<=e) {
            int mid = s+((e-s)/2);
            int result = guess(mid);
            if(result == 0){
                return mid;
            }
            else if(result == 1) {
                s = mid+1;
            }
            else {
                e = mid -1;
            }
        }
        return -1;
    }
};