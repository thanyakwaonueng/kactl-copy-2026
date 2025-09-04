/**
 * Author: Tanya
 * Description: Demonstration of line intersection test from cses
 */

 #include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define nl '\n'
using namespace std;

typedef long long int ll;
typedef complex<ll> pt;
struct line {
    pt P, Q, D; bool S = false;
    line(pt p, pt q, bool b = false) : P(p), Q(q), D(q - p), S(b) {}
};


#define X real()
#define Y imag()
#define CRS(a, b) (conj(a) * (b)).Y //scalar cross product

bool box_intersected(line E, line F){
    for(int rep=1;rep<=2;++rep){
        if(max(E.Q.Y, E.P.Y) < min(F.Q.Y, F.P.Y) or max(E.Q.X, E.P.X) < min(F.Q.X, F.P.X))return false;
        swap(E, F);
    }
    return true;
}

bool collinear(line E, line F){
    pt F1 = F.P - E.P, F2 = F.Q - E.P, ER = E.D;

    if(CRS(ER, F1) == CRS(ER, F2) and CRS(ER, F1) == 0)return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t; cin >> t;
    for(int _=0;_<t;++_){
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        pt A = pt{x1, y1}, B = pt{x2, y2}, C = pt{x3, y3}, D = pt{x4, y4};
        line E = line(A, B, true), F(C, D, true);

        if(!box_intersected(E, F)){
            cout << "NO" << nl;
        } else {
            if(collinear(E, F)){
                cout << "YES" << nl;
            } else { //additional check
                pt F1 = F.P - E.P, F2 = F.Q - E.P, ER = E.D;

                pt E1 = E.P - F.P, E2 = E.Q - F.P, FR = F.D;

                if( (CRS(ER, F1) > 0 and CRS(ER, F2) > 0) or (CRS(ER, F1) < 0 and CRS(ER, F2) < 0)
                    or (CRS(FR, E1) > 0 and CRS(FR, E2) > 0) or (CRS(FR, E1) < 0 and CRS(FR, E2) < 0)){
                    cout << "NO" << nl;
                } else {
                    cout << "YES" << nl;
                }
            }
        }
    }
}
