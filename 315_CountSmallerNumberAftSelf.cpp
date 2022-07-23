"""
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
"""
class Solution {
public:
    void merge(int l, int m, int r, vector<pair<int,int>> &arr, vector<int> &ans){
        
        vector<pair<int, int>> temp(r-l+1);
        int i = l, j = m+1, k = 0;
        
        while(i<=m && j<=r){
            if(arr[i].first <= arr[j].first)
            {
                temp[k++]=arr[j++];
            }
            else{
               ans[arr[i].second]+=(r-j+1);
                temp[k++]=arr[i++];
            }
        }
        while(i<=m)
        {
            temp[k++] = arr[i++];
        }
        while(j<=r){
            temp[k++] = arr[j++];
        }
        
        for(int left = l; left<=r; left++)
        {
            arr[left]= temp[left-l];
        }
    }
    void mergeSort(vector<pair<int,int>> &arr, int l, int r, vector<int> &ans)
    {
        if(l<r)
        {
            int mid = l+(r-l)/2;
            mergeSort(arr, l, mid, ans);
            mergeSort(arr, mid+1, r, ans);
            merge(l, mid, r, arr, ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> arr;
        
        for(int i=0; i<n ;i++)
        {
            arr.push_back({nums[i], i});
        }
        vector<int> ans(n,0);
        mergeSort(arr, 0, n-1, ans);
        return ans;
    }
};