#include <fstream>
#include <tuple>
#include <deque>
using namespace std;
int main() {
    ifstream fin("vila2.in");
    ofstream fout("vila2.out");
    int n, k, max =0;
    fin>>n>>k;
    deque<tuple<int, int>> minim;
    deque<tuple<int, int>> maxim;

    for(int i=0; i<=n; i++){
        while(!minim.empty() && get<1>(minim.front()) < i-k)
            minim.pop_front();
        while(!maxim.empty() && get<1>(maxim.front()) < i-k)
            maxim.pop_front();
        int x;
        fin>>x;
        while(!maxim.empty() && get<0>(maxim.back())<=x)
            maxim.pop_back();
        while(!minim.empty() && get<0>(minim.back())>=x)
            minim.pop_back();
        maxim.emplace_back(x, i);
        minim.emplace_back(x, i);

        int aux = get<0>(maxim.front()) - get<0>(minim.front());
        if(aux > max)
            max = aux;
    }

    fout<<max;
    fin.close();
    fout.close();
    return 0;
}
