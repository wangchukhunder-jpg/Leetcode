class Solution {
public:
bool possible(vector<int>&bloomDay,int m,int k,int day){
    int n=bloomDay.size();
    int cnt=0;int nob=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }else{
            nob+=(cnt/k);
            cnt=0;
        }
    }nob+=cnt/k;
    return nob>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) { 
        int n=bloomDay.size();
        long long val=m * 1LL * k *1LL;
        if(val>n)return -1;
        int mini=INT_MAX;int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,m,k,mid)==true){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return low;
        
    }         
};