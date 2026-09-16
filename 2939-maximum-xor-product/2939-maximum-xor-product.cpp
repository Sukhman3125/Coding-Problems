class Solution {
private:
    string bin(long long x){
        string res;
        while(x){
            res += (x&1) + '0';
            x>>=1;
        }
        while(res.size()<50){
            res += '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    int maximumXorProduct(long long a, long long b, int n) {
        string x = bin(a);
        string y = bin(b);
        long long prefX = 0, prefY = 0;
        long long res = 0;
        for(int i=0;i<50;i++){
            res<<=1;
            prefX<<=1;
            prefY<<=1;
            prefX += x[i]-'0';
            prefY += y[i]-'0';
            if(i<50-n) continue; // fixed to '0'
            if((prefX^res)<(prefY^res)){
                res += !bool(x[i]-'0');
            }else{
                res += !bool(y[i]-'0');
            }
        }
        long long MOD = 1e9 + 7;
        return (((a^res)%MOD)*((b^res)%MOD))%MOD;
    }
};