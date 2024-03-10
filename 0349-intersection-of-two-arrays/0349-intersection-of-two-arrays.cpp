class Solution {
public:
    bool binarySearch(vector<int>& arr,int n,int num) {
        int s = 0;
        int e = n-1;
        while(s<=e) {
            int mid = s + ((e-s)/2);
            if(arr[mid] == num)
                return true;
            else if(arr[mid] > num) {
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        set<int> answers;
        int n = nums2.size();
        int n1 = nums1.size();
        for(int i=0;i<n;i++) {
            if(binarySearch(nums1,n1,nums2.at(i)))
                answers.insert(nums2.at(i));
        }
        vector<int> ans(answers.begin(),answers.end());
        return ans;
    }
};