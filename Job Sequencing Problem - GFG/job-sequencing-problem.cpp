// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compareJobs(Job &firstJob, Job &secondJob) {
        if (firstJob.profit > secondJob.profit)
            return true;
        if (firstJob.profit == secondJob.profit && firstJob.dead < secondJob.dead)
            return true;
        return false;
    }
    vector<int> JobSchedulingUtil(vector<Job> arr, int n) {
        sort(arr.begin(), arr.end(), compareJobs);
        int maxEndingTime = INT_MIN;
        for (Job tmpJob : arr) {
            if (tmpJob.dead > maxEndingTime)
                maxEndingTime = tmpJob.dead;
        }
        vector<int> scheduledTime;
        for (int i = 0; i <= maxEndingTime; i++) {
            scheduledTime.push_back(-1);
        }

        int totalJobs = 0;
        int maxProfit = 0;

        for (auto cntJob : arr) {
            int j = cntJob.dead;
            while (j >= 1) {
                if (scheduledTime[j] == -1) {
                    scheduledTime[j] = cntJob.id;
                    totalJobs++;
                    maxProfit += cntJob.profit;
                    break;
                }
                j--;
            }
        }
        vector<int> ans = {totalJobs, maxProfit};
        return ans;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        vector<Job> jobArr;
        jobArr.reserve(n);
        for (int i = 0; i < n; i++) {
            jobArr.push_back(arr[i]);
        }
        return JobSchedulingUtil(jobArr, n);
    }
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends