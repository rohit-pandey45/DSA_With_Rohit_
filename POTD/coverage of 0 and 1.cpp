class Solution {
public:

    bool hasOneLeft(int i, int j, vector<vector<int>>& mat) {
        for (int col = j - 1; col >= 0; col--)
            if (mat[i][col] == 1) return true;
        return false;
    }

    bool hasOneRight(int i, int j, vector<vector<int>>& mat) {
        for (int col = j + 1; col < mat[0].size(); col++)
            if (mat[i][col] == 1) return true;
        return false;
    }

    bool hasOneUp(int i, int j, vector<vector<int>>& mat) {
        for (int row = i - 1; row >= 0; row--)
            if (mat[row][j] == 1) return true;
        return false;
    }

    bool hasOneDown(int i, int j, vector<vector<int>>& mat) {
        for (int row = i + 1; row < mat.size(); row++)
            if (mat[row][j] == 1) return true;
        return false;
    }

    int findCoverage(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int coverage = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    int cnt = 0;

                    if (hasOneLeft(i, j, mat)) cnt++;
                    if (hasOneRight(i, j, mat)) cnt++;
                    if (hasOneUp(i, j, mat)) cnt++;
                    if (hasOneDown(i, j, mat)) cnt++;

                    coverage += cnt;
                }
            }
        }

        return coverage;
    }
};