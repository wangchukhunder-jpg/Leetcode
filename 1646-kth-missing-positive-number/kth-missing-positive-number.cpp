class Solution {
public:

    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;int high=n-1;
        while(low<=high){
             int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }return low+k; // high+1 =low and it came from arr[high]+more where more is k-missing ,so overall it becomes and missing is arr[high]-high  so put it all at last it become low+k;
    }
};