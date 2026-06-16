class Solution {
public:
    void solveDfs(vector<vector<int>>& image, int sr, int sc, int color, int drow[], int dcol[], int initialColor){
        image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();

        for(int i = 0; i<4; i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == initialColor && image[nrow][ncol] != color){
                solveDfs(image,nrow,ncol,color,drow,dcol,initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //Edge Case
        int initialColor = image[sr][sc];
        if(initialColor == color){
            return image;
        }
        //Top,Right,Bottom,Left
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        solveDfs(image,sr,sc,color,drow,dcol,initialColor);
        return image;

    }
};