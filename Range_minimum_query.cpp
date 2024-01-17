#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");
    int n, m;
    fin >> n >> m;
    int p = 31 - __builtin_clz(n);  //log2(n)
    int A[p+1][n+1];
    for (int i = 1; i <= n; i++)
        fin >> A[0][i];
    int cn = n;
    for (int i = 1; i <= p; i++) {//indexing through lines
        const int put = 1 << (i-1);
        for (int j = 1; j + put <= cn; j++)
            A[i][j] = min(A[i - 1][j], A[i - 1][j + put]);
        cn = cn - put;   //the length of the line gets lower as i grows
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        int p2 = 31 - __builtin_clz(b - a + 1);
        fout << min(A[p2][a], A[p2][b - (1 << p2) + 1]) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
