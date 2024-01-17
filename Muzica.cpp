#include <fstream>
#include <unordered_map>
using namespace std;


int main() {
    ifstream fin("muzica.in");
    ofstream fout("muzica.out");
    int n, m;
    fin>>n>>m;
    int A, B, C, D, E;
    fin>>A>>B>>C>>D>>E;
    unordered_map<int, int> vasile;

    for(int i=0; i<n; i++){
        int x;
        fin>>x;
        vasile[x] = 0;
    }

    int count = 0;
    if(vasile.find(A) != vasile.end()){
        vasile[A] = 1;
        count++;
    }
    if(vasile.find(B) != vasile.end() && vasile[B] == 0){
        vasile[B] = 1;
        count++;
    }
    for(int i=2; i<m; i++){
        int aux = (1LL*B*C + 1LL*A*D)%E;
        if(vasile.find(aux) != vasile.end() && vasile[aux] == 0){
            vasile[aux] = 1;
            count++;
        }
        A=B;
        B=aux;
    }
    fout<<count;
    fin.close();
    fout.close();
    return 0;
}
