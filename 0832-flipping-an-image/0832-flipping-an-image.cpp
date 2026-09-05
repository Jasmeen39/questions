class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        //int left=0, right=m-1;
        for(int i=0; i<n; i++){
            int left=0, right=m-1;
            while(left<=right){
                int temp= image[i][left]^1;
                image[i][left]=image[i][right]^1;
                image[i][right]=temp;
                left++;
                right--;
            }
        }
        return image;
    }
};