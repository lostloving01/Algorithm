ass Solution {
public:
    int countPalindromicSubsequences(string S) {
    int n=S.length();
        vector<vector<vector<int>>> f(n,vector<vector<int>> (n,vector<int> (6,0)));
        vector <int> g(4);
        for (int i=1; i<=n; i++) {
            vector <int> g(4,0);
            int temp=0;
            for (int j=0; j<i; j++) {
                if (g[S[j]-'a']==0) temp+=1;
                g[S[j]-'a']+=1;
            }
            f[0][i-1][0]=temp;
            
            for (int j=i; j<n; j++) {
                g[S[j-i]-'a']-=1;
                if (g[S[j-i]-'a']==0) temp-=1;
                if (g[S[j]-'a']==0) temp+=1;
                g[S[j]-'a']+=1; 
                f[j-i+1][j][0]=temp;
            }
        }
        
        for (int i=0; i<n; i++) {
            f[i][i][5]=f[i][i][0];
            if (i<(n-1)) {
                if (S[i]==S[i+1]) {
                    f[i][i+1][S[i]-'a'+1]=1;   
                    f[i][i+1][5]+=1;
                }
                f[i][i+1][5]+=f[i][i+1][0];
            }
        }
        for (int i=2; i<n; i++ ) {
            for (int j=0; j<(n-i); j++) {
                f[j][j+i][5]=f[j][j+i][0];
                if (S[j]==S[j+i]) {
                    for (int k=0; k<=3; k++) {
                        if (k==(S[j]-'a')) {
                            f[j][j+i][k+1]=f[j+1][j+i-1][5]+1;
                        } else {
                            f[j][j+i][k+1]=f[j+1][j+i-1][k+1];
                        }
                        f[j][j+i][5]+=f[j][j+i][k+1];
                        f[j][j+i][5]%=1000000007;
                    }
                } else {
                    f[j][j+i][S[j]-'a'+1]=f[j][j+i-1][S[j]-'a'+1];
                    f[j][j+i][S[j+i]-'a'+1]=f[j+1][j+i][S[j+i]-'a'+1];
                    for (int k=0; k<=3; k++) {
                        if (k!=(S[j]-'a') && k!=(S[j+i]-'a')) {
                            f[j][j+i][k+1]=f[j+1][j+i-1][k+1];
                        }
                        f[j][j+i][5]+=f[j][j+i][k+1];
                        f[j][j+i][5]%=1000000007;
                    }
                }
            }
        }
    return (f[0][n-1][5]);    
    }
};
