int LCS(int i,  int j){
    if(i == li || j == lj)
        return 0;
    if(!dp[i][j]){
        if(a[i] == b[j])
            dp[i][j] = LCS(i + 1, j + 1) + 1;
        else
            dp[i][j] = max(LCS(i + 1, j), LCS(i, j + 1));
    }
    return dp[i][j];
}
