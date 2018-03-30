class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N=grid.size();
        vector<vector<vector<int>>> f(2*N,vector<vector<int>> (N,vector<int>(N,-1)));
        if (N==1) return grid[0][0];
        f[0][0][0]=grid[0][0];
        
        for (int i=1; i<=(2*(N-1)); i++) {
            for (int j=max(0,i-N+1); j<=min(i,N-1); j++) {
                for (int k=max(0,i-N+1); k<=j; k++) {
                    if (grid[j][i-j]!=-1 && grid[k][i-k]!=-1) {
                        if (j!=0 && k!=0) {
                            f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-1]);
                        }
                        if (j!=0 && (i-k)!=0) {
                            f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]);
                        }
                        if ((i-j)!=0 && (k!=0)) {
                            f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]);
                        }
                        if ((i-j)!=0 && (i-k)!=0) {
                            f[i][j][k]=max(f[i][j][k],f[i-1][j][k]);
                        }
                    }
                    if (f[i][j][k]>=0) {
                        if (j!=k) {
                            f[i][j][k]+=(grid[j][i-j]+grid[k][i-k]);
                        } else {
                            f[i][j][k]+=grid[j][i-j];
                        }
                    }
                }
            }
        }
        return max(f[2*(N-1)][N-1][N-1],0);
    }
};
