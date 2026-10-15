class Solution {
public:

    int apnaLowerBound(int s, int e, vector<int>& potions, int minPotion){
        int possibleIndex = -1;
        int mid = 0;
        while(s<=e){
            mid = s + (e-s)/2;
            if(potions[mid] >= minPotion){
                possibleIndex = mid;
                e = mid-1;
            }else{
                s = mid +1;
            }
        }
        return possibleIndex;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();
        sort(begin(potions), end(potions));
        int maxPotionValue = potions[n-1];
        vector<int> ans;

        for(int i=0; i<m; i++){
            int spell = spells[i];
            long long minPotion = ceil((1.0*success)/spell);
            if(minPotion>maxPotionValue){
                ans.push_back(0);
                continue;
            }
            int index = apnaLowerBound(0, n-1, potions, minPotion);
            int count = n-index;
            ans.push_back(count);
        } 
        return ans;
    }
};