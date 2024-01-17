#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isABC(vector<int>& v, int le, int ri){
    //the first elem is the root, the first part of the vector has smaller elements than the root
    //and the second part has greater elements
    if(le >= ri)
        return true;
    int root = v[le];
    int i = le+1;
    while(i<= ri && v[i] < root){
        i++;
    }
    int m = i;
    for(i=m; i<= ri; i++)
        if(v[i] < root)
            return false;

    return isABC(v, le+1, m-1) && isABC(v, m, ri);
}

void print(vector<int>& v){
    for(auto it=v.begin()+1; it!=v.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";
}


void allBstPreorders(int N) {
    vector<int> v(N+1);
    for(int i=1; i<=N; i++)
        v[i] = i;

    //taking all permutations and checking if they're ABC's
    do{
        if(isABC(v, 1, N))
            print(v);

    }while(next_permutation(v.begin()+1, v.end()));
}

int main() {
    int N;
    cin >> N;
    allBstPreorders(N);
    return 0;
}
