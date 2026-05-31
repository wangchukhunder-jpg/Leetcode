class Solution {
public:
long long cnt=0;
void merge(vector<int>&nums,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
   
}
void ms(vector<int>&nums,int low,int high){
    if(low>=high)return;
    int mid=(low+high)/2;
    ms(nums,low,mid);
    ms(nums,mid+1,high);
    countpair(nums,low,mid,high);
    merge(nums,low,mid,high);
    
}
void countpair(vector<int>&nums,int low, int mid, int high){
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && (long long)nums[i]>2LL*nums[right])right++;
        cnt+=right-(mid+1);
    }
}

    int reversePairs(vector<int>& nums){
        ms(nums,0,nums.size()-1);
        return cnt;
    }
};