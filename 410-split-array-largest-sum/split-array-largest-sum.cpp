class Solution {
public:
bool issplitpossible(vector<int>&nums,int mid,int k){
    int n=nums.size();
    int currsum=0;int subarray=1;
    for(int i=0;i<n;i++){
        if(nums[i]+currsum>mid){
            subarray++;
            currsum=nums[i];
        }else{
            currsum+=nums[i];
        }
    }return subarray<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(issplitpossible(nums,mid,k)==true){
                high=mid-1;
            }else{
            low=mid+1;
        }
        }return low;
    }
};