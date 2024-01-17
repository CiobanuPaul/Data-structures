#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ifstream fin("pariuri.in");
    ofstream fout("pariuri.out");
    unordered_map<int, int> timpi;
    int n;
    fin>>n;
    for(int i=0; i<n; i++){
        int m;
        fin>>m;
        for(int j=0; j<m; j++){
            int t, b;
            fin>>t>>b;
            if(timpi.find(t) == timpi.end())
                timpi[t] = b;
            else
                timpi[t] += b;
        }
    }
    fout<<timpi.size()<<"\n";
    for(auto it: timpi){
        fout<<it.first<<" "<<it.second<<" ";
    }

    fin.close();
    fout.close();
    return 0;
}
