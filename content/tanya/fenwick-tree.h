/**
 * Author: Tanya
 * Description: use 1 base indexing
 */
vector<long long>bit;

void add(int i, int k){
    while(i<(int)bit.size()){
        bit[i]+=k;
        i+=i&-i;
    }
}

ll F(int i){
    ll sum=0;
    while(i>0){
        sum+=bit[i];
        i-=i&-i;
    }
    return sum;
}

void build_bit(vl &a){
    bit=a;
    for(int i=1;i<(int)bit.size();++i){
        int p=i+(i&-i);//index to parent
        if(p<(int)bit.size())bit[p]+=bit[i];
    }
}
