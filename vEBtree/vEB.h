#ifndef _vEB_H_
#define _vEB_H_
typedef long long ll;

class vEB{
private:
    ll u;
    int bits;
    int downbits;
    ll min;
    ll max;
    vEB *summary;
    vEB **cluster;
    ll high(ll x);
    ll low(ll x);
    ll index(ll h, ll l);
    void emptyInsert(ll x);

public:
    vEB(ll u, bool first=true);
    bool member(ll x);
    ll minimum();
    ll maximum();
    ll successor(ll x);
    ll predecessor(ll x);
    void insert(ll x);
    void Delete(ll x);
    void show_summary();
    void show_set();
    void show_all();
};

#endif // _vEB_H_