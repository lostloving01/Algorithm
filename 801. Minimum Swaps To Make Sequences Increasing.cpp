class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector <int> f(n,INT_MAX),g(n,INT_MAX);
        
        f[0]=0; g[0]=1;
        for (int i=1; i<n; i++) {
            if (A[i]>A[i-1] && B[i]>B[i-1]) {
                f[i]=f[i-1];
                g[i]=g[i-1]+1;
            }
            if (A[i]>B[i-1] && B[i]>A[i-1]) {
                f[i]=min(f[i],g[i-1]);
                g[i]=min(g[i],f[i-1]+1);
            }
        }
        return min(f[n-1],g[n-1]);
        
    }
};
