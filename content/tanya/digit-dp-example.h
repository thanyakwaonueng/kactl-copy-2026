/**
 * Author: Tanya
 * Description: 
 */
 ll dp[20][11][2][2];
vector<int> num;

ll construct(int pos, int d, int flag, bool isStarted){
    if(pos == (int)num.size()){
        //return isStarted;
        return 1;
    }

    if(dp[pos][d][flag][isStarted] != -1)return dp[pos][d][flag][isStarted];

    int LMT;
    if(flag == 0){
        LMT = num[pos];
    } else {
        LMT = 9;
    }

    //placing current digits
    ll res = 0;
    for(int i=0;i<=LMT;++i){
        if((i == 0 and isStarted and i == d) or (i != 0 and i == d))continue;
        //by the condition adjacent digits must not be the same
        int nflag = flag;
        if(i < LMT and flag == 0)nflag = 1;

        res += construct(pos+1, i, nflag, (isStarted or i>0));
    }

    return dp[pos][d][flag][isStarted] = res;
}
