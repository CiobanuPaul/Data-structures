#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Arbint{
    vector<int> tree;
    int n;
    int maxi;

    void update_(int node, int le, int ri, int pos, int val){
        if(le == ri)
            tree[node] = val;
        else{
            int mid = (le+ri)/2;
            if(pos <= mid){
                update_(node*2, le, mid, pos, val);
            }
            else {
                update_(node * 2 + 1, mid + 1, ri, pos, val);
            }

            tree[node] = max(tree[node*2], tree[node*2+1]);
        }
    }


    void query_(int node, int le, int ri, int a, int b){
        if(a <= le && ri <= b)
            maxi = max(maxi, tree[node]);
        else{
            int mid = (le + ri) / 2;
            if (a <= mid)
                query_(node * 2, le, mid, a, b);
            if (b > mid)
                query_(node * 2 + 1, mid + 1, ri, a, b);
        }
    }

public:

    void update(int pos, int val){
        update_(1, 1, n, pos, val);
    }

    int query(int a, int b){
        maxi = -1;
        query_(1, 1, n, a, b);
        return maxi;
    }

    Arbint(int n){
        tree.resize(4*n);
        this->n = n;
    }
};



int main() {
    ifstream fin("arbint.in");
    ofstream fout("arbint.out");
    int n, m;
    fin>>n>>m;
    Arbint t(n);
    for (int i=1; i<=n; i++) {
        int x;
        fin>>x;
        t.update(i, x);
    }
    for(int i=0; i<m; i++){
        int opt, a, b;
        fin>>opt>>a>>b;
        if(opt == 0)
            fout<<t.query(a, b)<<"\n";
        else
            t.update(a, b);
    }

    fin.close();
    fout.close();
    return 0;
}
