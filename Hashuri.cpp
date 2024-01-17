#include <fstream>
#include <vector>
#include <list>
using namespace std;

class Hash{
    vector<list<int>> h;
    const int p;
public:
    Hash(int p);
    void insert(int x);
    void erase(int x);
    bool find(int x);

};

Hash::Hash(int p) : p(p) {
    h.resize(p);
}

void Hash::insert(int x) {
        h[x%p].push_back(x);
}

void Hash::erase(int x) {
    int aux = x%p;
    for(auto it=h[aux].begin(); it!=h[aux].end(); it++)
        if(*it == x) {
            h[aux].erase(it);
            break;
        }
}

bool Hash::find(int x) {
    int aux = x%p;
    for(int & it : h[aux])
        if(it == x) {
            return true;
        }
    return false;
}


int main(){
    ifstream fin("hashuri.in");
    ofstream fout("hashuri.out");
    Hash h(666013);
    int n;
    fin>>n;
    for (int i = 0; i < n; ++i) {
        int op, x;
        fin>>op;
        fin>>x;
        switch(op){
            case 1:
                h.insert(x);
                break;
            case 2:
                h.erase(x);
                break;
            case 3:
                fout<<h.find(x)<<"\n";
                break;
        }
    }


    fin.close();
    fout.close();
    return 0;
}
