#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream fin("paranteze.in");
    ofstream fout("paranteze.out");
    int n;
    fin >> n;
    vector<string> stack;
    int max = 0;
    for(int i=0; i<n; i++){
        char c;
        fin>>c;
        if(c=='(' || c=='[' || c=='{') {
           switch(c){
                case '(':
                    stack.emplace_back(")");
                    break;
                case '[':
                    stack.emplace_back("]");
                    break;
                case '{':
                    stack.emplace_back("}");
                    break;
            }
        }
        else if(!stack.empty()){
            if (stack.back() == string(1, c)){
                stack.pop_back();
                if(!stack.empty() && isdigit(stack.back()[0])) {
                    int nr = stoi(stack.back()) + 2;
                    stack.back() = to_string(nr);
                    if(nr > max)
                        max = nr;
                }
                else {
                    stack.emplace_back("2");
                    if(2 > max)
                        max = 2;
                }
            }
            else if(isdigit(stack.back()[0]) && stack.size() > 1 && stack[stack.size()-2] == string(1, c)){
                int nr = stoi(stack.back()) + 2;
                stack.pop_back();
                stack.pop_back();
                if(!stack.empty() && isdigit(stack.back()[0])) {
                    nr = stoi(stack.back()) + nr;
                    stack.back() = to_string(nr);
                }
                else {
                    stack.push_back(to_string(nr));
                }
                if (nr > max)
                    max = nr;
            }
            else
                stack.clear();
        }
    }
    fout<<max;

    fin.close();
    fout.close();
    return 0;
}
