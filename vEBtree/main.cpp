#include<iostream>
#include"vEB.h"
#include<string>

using namespace std;

int main(){
    ll u;
    cout << "-------------------" << endl;
    cout << "Set the size of a vEB tree (a power of 2) : ";
    cin >> u;
    vEB V(u);
    cout << "-------------------" << endl << ">> ";
    string command;
    ll x;
    while(cin >> command){
        if (command=="Insert"){
            cin >> x;
            V.insert(x);
            V.show_all();
        }
        else if (command=="Delete"){
            cin >> x;
            V.Delete(x);
            V.show_all();
        }
        else if (command=="Successor" || command=="Succ"){
            cin >> x;
            cout << "Successor(" << x << ") = " << V.successor(x) << endl;
        }
        else if (command=="Predecessor" || command=="Pred"){
            cin >> x;
            cout << "Predecessor(" << x << ") = " << V.predecessor(x) << endl;
        }
        else if (command=="Minimum" || command=="Min"){
            cout << "Minimum value = " << V.minimum() << endl;
        }
        else if (command=="Maximum" || command=="Max"){
            cout << "Maximum value = " << V.maximum() << endl;
        }
        else if(command=="Member"){
            cin >> x;
            if(V.member(x)){
                cout << x << " is a member of V." << endl;
            }
            else{
                cout << x << " is NOT a member of V." << endl;
            }
        }
        else if(command=="show"){
            cin >> command;
            if(command=="all"){
                V.show_all();
            }
            else if(command=="summary"){
                V.show_summary();
            }
            else if(command=="set"){
                V.show_set();
            }
        }
        else if(command=="exit"){
            return 0;
        }
        cout << "-------------------" << endl << ">> ";
    }
}