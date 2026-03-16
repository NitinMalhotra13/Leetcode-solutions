class Fancy {
public:
    const long long MOD = 1e9+7;
    vector<long long> a;
    long long mul = 1, add = 0;

    long long modpow(long long x,long long y){
        long long r=1;
        while(y){
            if(y&1) r=r*x%MOD;
            x=x*x%MOD;
            y>>=1;
        }
        return r;
    }

    Fancy(){}

    void append(int val) {
        long long inv = modpow(mul, MOD-2);
        a.push_back((val - add + MOD) % MOD * inv % MOD);
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if(idx >= a.size()) return -1;
        return (a[idx] * mul + add) % MOD;
    }
};
