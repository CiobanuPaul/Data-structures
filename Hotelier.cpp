#include <iostream>
using namespace std;
int v[10];
int main() {
    int n;
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        if(c >= '0' && c <='9'){
            v[int(c) - 48] = 0;
        }
        else if(c == 'L'){
            for(int j=0; j<=9; j++)
                if(v[j] == 0){
                    v[j] = 1;
                    break;
                }
        }
        else if(c == 'R'){
            for(int j=9; j>=0; j--)
                if(v[j] == 0){
                    v[j] = 1;
                    break;
                }
        }
    }
    for(int i=0; i<=9; i++)
        cout<<v[i];
    return 0;
}
