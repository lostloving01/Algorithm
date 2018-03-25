class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector <vector<int>> P(n),Q(n);
        vector <vector<int>> f(K+2,vector<int> (n,INT_MAX));
        vector <int> queue,stop;
        int open=0,close=0,result=INT_MAX;
        
        for (auto x: flights) {
            P[x[0]].push_back(x[1]);
            Q[x[0]].push_back(x[2]);
        }
        
        queue.push_back(src);
        stop.push_back(0);
        f[0][src]=0;
        
        while (open<=close) {
            int k=stop[open];
            int start=queue[open];
            if (k==(K+1)) break;
            for (int i=0; i<P[start].size(); i++) {
                if ((f[k][start]+Q[start][i])<f[k+1][P[start][i]]) {
                    f[k+1][P[start][i]]=f[k][start]+Q[start][i];
                    close+=1;
                    queue.push_back(P[start][i]);
                    stop.push_back(k+1);
                }
                if (P[start][i]==dst) {
                    result=min(result,f[k+1][P[start][i]]);
                }
            }
            open+=1;
        }
        
        if (result==INT_MAX) {
            return -1;
        } else {
            return result;
        }
            
    }
};
