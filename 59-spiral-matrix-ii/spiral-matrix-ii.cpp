class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 1));
        // ALL WORK DONE HERE
        int sr = 0, enr = n - 1, sc = 0, enc = n - 1;
        int num = 1;
        if(n==2){
            return {{1,2},{4,3}};
        }
        while (sc < enc) {
            // first row
            for (int i = sr; i <= enr; i++) {
                mat[sc][i] = num;
                num++;
            }
            // last column
            if (sc + 1 != n) {
                for (int i = sc + 1; i <= enc; i++) {
                    mat[i][enr] = num;
                    num++;
                }
            }

            // last row
            if (enr - 1 > 0) {
                for (int i = enr - 1; i >= sr; i--) {
                    mat[enc][i] = num;
                    num++;
                }
            }

            // left col
            for (int i = enc - 1; i > sc; i--) {
                mat[i][sr] = num;
                num++;
            }
            sr++;
            enr--;
            sc++;
            enc--;
        }
        if(n%2!=0){
            int cen=n/2;
            mat[cen][cen]=(n*n);
        }
        return mat;
    }
};