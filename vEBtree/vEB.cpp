#include "vEB.h"
#include<iostream>

using namespace std;


vEB::vEB(ll u, bool first) : min(-1), max(-1){
    bits=-1;
    this->u = u;
    if(u==2){
        summary=NULL;
        cluster=NULL;
    }
    else{
        long long temp = u;
        while(temp){
            bits++;
            temp>>=1;
        }
        downbits=bits/2;
        summary = new vEB(1<<(bits-downbits), false);
        if(first){
            cout << "vEB tree of size " << (1<<(bits-downbits)) << " has been created as a summary." << endl;
        }
        cluster = new vEB*[1<<(bits-downbits)];
        for (int i=0; i<(1<<(bits-downbits)); i++){
            cluster[i] = new vEB(1<<downbits, false);
            if(first){
            cout << "vEB tree of size " << (1<<downbits) << " has been created as a cluster of index " << i << endl;
            }
        }
    }
}

ll vEB::high(ll x){
    return x >> downbits;
}
ll vEB::low(ll x){
    return x%(1<<downbits);
}
ll vEB::index(ll h, ll l){
    return (h<<downbits) + l;
}

bool vEB::member(ll x){
    if(x == min || x == max) return true;
    else if (u == 2) return false;
    else{
        return cluster[high(x)] -> member(low(x));
    }
}

ll vEB::minimum(){
    return min;
}

ll vEB::maximum(){
    return max;
}

ll vEB::successor(ll x){
    if (u==2){
        if (x==0 && max==1){
            return 1;
        }
        else return -1;
    }
    else if(min!=-1 && x<min){
        return min;
    }
    else
    {
        if (low(x) < cluster[high(x)]->maximum()){    // クラスタ内の探索
            return index(high(x), cluster[high(x)]->successor(low(x)));
        }
        else
        {
            ll succ = summary->successor(high(x));
            if (succ==-1){
                return -1;
            }
            else{
                return index(succ, cluster[succ]->minimum());
            }
        }
    }
}

ll vEB::predecessor(ll x){
    if (u==2){
        if (x==1 && min==0){
            return 0;
        }
        else return -1;
    }
    else          // 本ではmaxを返すケースを入れているが論理的にはいらないはず
    {
        if (low(x) > cluster[high(x)]->minimum()){  // クラスタ内の探索
            return index(high(x), cluster[high(x)]->predecessor(low(x)));
        }
        else{
            ll pred = summary->predecessor(high(x));
            if (pred==-1){
                if (min!=-1 && x>min){
                    return min;
                }
                else return -1;
            }
            else{
                return index(pred, cluster[pred]->maximum());
            }
        }
    }
}

void vEB::emptyInsert(ll x){
    min = x;
    max = x;
}

void vEB::insert(ll x){
    if (min == -1){
        emptyInsert(x);
    }
    else
    {
        if (min != -1 && x < min){
            ll temp = x;
            x = min;
            min = temp;
        }
        if (u > 2){            
            if (cluster[high(x)]->minimum() == -1){
                cluster[high(x)]->emptyInsert(low(x));
                summary->insert(high(x));
            }
            else {
                cluster[high(x)]->insert(low(x));
            }
        }
        if (max < x){
            max = x;
        }
    }
}

void vEB::Delete(ll x){
    if (min == max){
        min = -1;
        max = -1;
    }
    else if (u == 2){            // 本ではelseifにして一行多い
        if (x==0) min = 1;
        else max = 0;
    }
    else{
        if (x == min){
            ll first_cluster = summary->minimum();
            // minを上書きして削除, 値の復元忘れず！
            min = index(first_cluster, cluster[first_cluster]->minimum());
            x = min;
        }
        cluster[high(x)]->Delete(low(x));
        if (cluster[high(x)]->minimum() == -1){
            summary->Delete(high(x));
            // maxの更新
            if (x == max){
                ll sum_max = summary->maximum();
                // clusterがすべて空になった場合
                if (sum_max == -1){
                    max = min;
                }
                else{
                    max = index(sum_max, cluster[sum_max]->maximum()); 
                }
            }
        }
        // maxの更新(xのクラスタに元が残っている場合)
        else if (x == max){
            max = index(high(x), cluster[high(x)]->maximum());
        }
    }
}

void vEB::show_summary(){
    cout << "u : " << u << " min:" << min << " max:" << max << endl;
    if (u != 2){
        cout << "summary : ";
        for(int i=0; i<(1<<(bits-downbits)); i++){
            if(summary->member(i)){
                cout << 1 << " ";
            }
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void vEB::show_set(){
    if (min==-1){
        cout << "The set is EMPTY." << endl;
    }
    else{
        cout << "Members in the set: ";
        for(int i=0; i<u; i++){
            if (member(i)) cout << i << " ";
        }
        cout << endl;
    }
}

void vEB::show_all(){
    show_summary();
    show_set();
}