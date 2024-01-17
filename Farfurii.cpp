#include <fstream>
using namespace std;
int main() {
    ifstream fin("farfurii.in");
    ofstream fout("farfurii.out");
    int n;
    long long int k;
    fin>>n>>k;
    //Daca avem 1 2 3 4 8 7 6 5 -> avem 4*3/2 = 6 inversiuni (Gauss, 3+2+1)
    //Iar acesta este cel mai mic lexicografic
    //Daca nu avem k = o suma a lui Gauss, gasim cea mai mica suma Gauss mai mare decat k
    //Vom aranja numerele ca in forma de mai sus, dar vom scoate unul din numere a.i. sa ramanem cu k inversiuni
    //Pt exemplul de mai sus, daca avem k=5, vom scoate pe 7 a.i. sa nu mai avem inversiunea (8, 7)  --> 1 2 3 4 7 8 6 5   -->>> 5 inversiuni

    int nr = 0;
    while(1LL*nr*(nr+1)/2 < k)
        nr++;
    for(int i=1; i<=n-nr-1; i++)
        fout<<i<<" ";
    int deScos = n - (1LL*nr*(nr+1)/2 - k);
    fout << deScos <<" ";
    for(int i=n; i>n-nr-1; i--)
        if(i != deScos)
            fout<<i<<" ";
    fin.close();
    fout.close();
    return 0;
}
//k=7, nr = 4
//1 2 3 8 7 6 5 4