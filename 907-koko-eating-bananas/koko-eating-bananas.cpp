class Solution {
public:
int findmaxi(vector<int>&piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }return maxi;
}
long long eatingspeed(vector<int>&piles,int k){
    int n=piles.size();
    long long totalh=0;
    for(int i=0;i<n;i++){
        totalh+=ceil((double)piles[i]/(double)k);
    }return totalh;
}

    int minEatingSpeed(vector<int>& piles, int h){
        int n=piles.size();
        int low=1;int high=findmaxi(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long totalh=eatingspeed(piles,mid);
            if(totalh<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return low;
        
    }                              
    
};