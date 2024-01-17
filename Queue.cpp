#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream fin("queue.in");
ofstream fout("queue.out");

void print_push(int which, int nr){
    fout<<"push("<<which<<","<<nr<<") ";
}
void print_pop(int which){
    fout<<"pop("<<which<<") ";
}

void write(int nr){
    fout<<"write("<<nr<<") ";
}

void read(int nr){
    fout<<"read("<<nr<<") ";
}

int main() {

    int n;
    fin>>n; fin.get();
    vector<int> st1;
    vector<int> st2;

    for(int i=0; i<n; i++){
        string s;
        getline(fin, s);
        fout<<i+1<<": ";

        if(s[1] == 'u') {
            int pos = s.find('(');
            int nr = stoi(s.substr(pos + 1, s.size() - pos - 2));
            read(nr);
            st1.push_back(nr);
            print_push(1, nr);
            fout<<"\n";
        }
        else{
            int nr;
            if(!st2.empty()){
                nr = st2.back();
                st2.pop_back();
                print_pop(2);
            }
            else{
                while(st1.size() > 1) {
                    st2.push_back(st1.back());
                    st1.pop_back();
                    print_pop(1);
                    print_push(2, st2.back());

                }
                nr = st1.back();
                st1.pop_back();
                print_pop(1);
            }
            write(nr);
            fout<<"\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
