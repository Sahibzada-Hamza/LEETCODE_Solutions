class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid(m, vector<char>(n, '#'));
        grid[0][0] = '.';
        int i=0,j=0;
        if (n != 1) {
            i = 0, j = 1;
            int alt = 0;
            while (i < m && j < n) {
                grid[i][j] = '.';
                if (alt % 2 == 0)
                    i++;
                else
                    j++;
                alt++;
                // right
            }
        }
        else i=0,j=0;
        if(j==n)j=n-1;
        if(i==m)i=m-1;
        while(i<m){
            grid[i][j]='.';
            i++;
        }
        if(i==m)i=m-1;
        while (j < n)
            grid[i][j++] = '.';

        // conversion
        vector<string> ans;
        for (auto st : grid) {
            string str = "";
            for (char st2 : st) {
                str += st2;
            }
            ans.push_back(str);
        }
        return ans;
    }
};