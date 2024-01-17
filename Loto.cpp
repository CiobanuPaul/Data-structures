#include <fstream>
#include <unordered_map>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("loto.in");
    ofstream fout("loto.out");
    int n, S;
    vector<int> nums;
    fin>>n>>S;
    for(int i=0; i<n; i++){
        int x;
        fin>>x;
        if(x<=S)
            nums.push_back(x);
    }
    unordered_map<int, tuple<int, int, int>> sums;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            for(int k=j; k<n; k++){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum <= S)
                    sums[sum] = make_tuple(nums[i], nums[j], nums[k]);
            }

    bool ok = false;
    for(auto it: sums){
        if(sums.find(S-it.first) != sums.end()){
            vector<int> v;
            v.push_back(get<0>(it.second));
            v.push_back(get<1>(it.second));
            v.push_back(get<2>(it.second));
            v.push_back(get<0>(sums[S-it.first]));
            v.push_back(get<1>(sums[S-it.first]));
            v.push_back(get<2>(sums[S-it.first]));
//            sort(v.begin(), v.end());
            for(auto elem: v)
                fout<<elem<<" ";
            ok = true;
            break;
        }
    }
    if(!ok)
        fout<<-1;

    fin.close();
    fout.close();
    return 0;
}
