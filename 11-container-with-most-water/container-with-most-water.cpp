class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int i=0, j=height.size()-1;
        while(i<j){ 
            int width = j-i;
            int ht = min(height[i], height[j]);
            int currWater = width*ht;
            maxWater = max(maxWater,currWater);
            height[i]<height[j]?i++:j--;
        }
        return maxWater;
    }
};