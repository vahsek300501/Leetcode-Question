class Solution {
    public int dieSimulator(int n, int[] rollMax) {
	int[][][] mem = new int[n+1][7][16];
	return cal(n, 0, 0, rollMax, mem);
}
// tail is the tail number of sequence, consectiveNum is the consective num of the sequence tail.
private int cal(int leftRolls, int tail, int consectiveNum, int[] rollMax, int[][][] mem) {
	if (leftRolls <= 0) return 1;
	int ans = 0;
	if (mem[leftRolls][tail][consectiveNum] > 0) {
		return mem[leftRolls][tail][consectiveNum];
	}
	for (int k = 1; k <= 6; ++k) {
		// new tail
		if (k != tail && rollMax[k-1] >= 1) {
			ans = (ans + cal(leftRolls-1, k, 1, rollMax, mem))%1000000007;
		}
		// same tail
		if (k == tail && rollMax[k-1] >= consectiveNum+1) {
			ans = (ans + cal(leftRolls-1, k, consectiveNum+1, rollMax, mem))%1000000007;
		}
	}
	mem[leftRolls][tail][consectiveNum] = ans;
	return ans;
}
}