class Solution {
public:
int reqwieght(vector<int>&weights,int cap){
    int n=weights.size();
    int day=1; int load=0;
    for(int i=0;i<n;i++){
        if(load+weights[i]>cap){
            day=day+1;
            load=weights[i];
        }else{
            load+=weights[i];
        }
    }return day;
}
int findsum(vector<int>&weights){
    int n=weights.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=weights[i];
    }return sum;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=findsum(weights);
        while(low<=high){
            int mid=(low+high)/2;
            if(reqwieght(weights,mid)<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return low;
    }
};