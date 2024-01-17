#include <fstream>
#include <vector>
using namespace std;

class Heap{
    vector<pair<int, int>> heap; //each element has its value and a number indicating when it was inserted in the heap
    vector<int> nums;  //nums[i] returns the position in the heap of the (i+1)-th element inserted
public:
    void insert(int x){
        heap.emplace_back(x, nums.size());
        int p = heap.size()-1;
        while((p-1)/2 >= 0 && heap[(p-1)/2].first > heap[p].first){
            auto aux = heap[(p-1)/2];
            heap[(p-1)/2] = heap[p];
            heap[p] = aux;
            nums[heap[p].second] = p;     //updating its stored index
            p = (p-1)/2;
        }
        nums.push_back(p);
    }

    void erase(int i){
        int p = nums[i-1];
        heap[p] = heap.back();
        heap.pop_back();
        while(2*p+1 < heap.size()){
            if(2*p+2 < heap.size() && heap[2*p+1].first >= heap[2*p+2].first){
                if(heap[2*p+2].first < heap[p].first){
                    auto aux = heap[2*p+2];
                    heap[2*p+2] = heap[p];
                    heap[p] = aux;
                    nums[heap[p].second] = p;
                    p = 2*p+2;
                }
                else break;
            }
            else if(heap[2*p+1].first < heap[p].first){
                auto aux = heap[2*p+1];
                heap[2*p+1] = heap[p];
                heap[p] = aux;
                nums[heap[p].second] = p;
                p = 2*p+1;
            }
            else break;
        }
        if(p<heap.size()) {
            while ((p - 1) / 2 >= 0 && heap[(p - 1) / 2].first > heap[p].first) {
                auto aux = heap[(p - 1) / 2];
                heap[(p - 1) / 2] = heap[p];
                heap[p] = aux;
                nums[heap[p].second] = p;     //updating its stored index
                p = (p - 1) / 2;
            }
            nums[heap[p].second] = p;
        }
        nums[i-1] = -1;
    }

    int getMin(){
        return heap[0].first;
    }
};


int main() {
        ifstream fin("heapuri.in");
        ofstream fout("heapuri.out");
        int n;
        fin>>n;
        Heap h;
        for(int i=0; i<n; i++){
            int op;
            fin>>op;
            switch (op) {
                case 1:
                    int x;
                    fin>>x;
                    h.insert(x);
                    break;
                case 2:
                     int index;
                     fin>>index;
                     h.erase(index);
                     break;
                case 3:
                    fout<<h.getMin()<<"\n";
                    break;
            }
        }
        return 0;
}
