class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n= deck.size();
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        vector<int>ans(n);
        for(int card:deck){
            int indx=q.front();
            q.pop();
            ans[indx]=card;
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }return ans;

        
    }
};