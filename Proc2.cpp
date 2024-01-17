#include <fstream>
#include <queue>
using namespace std;

int main() {
    ifstream fin("proc2.in");
    ofstream fout("proc2.out");

    int n, m;
    typedef pair<int, int> pi;
    vector<pi> tasks;
    vector<int> proc;
    fin>>n>>m;

    proc.reserve(n);
    for(int i=0; i<n; i++)
        proc.push_back(i);

    tasks.reserve(m);
    for(int i=0; i<m; i++){
        int s, d;
        fin>>s>>d;
        tasks.emplace_back(s, d);
    }

    priority_queue<int, vector<int>, greater<int>> free(greater<int>(), proc);  //heapify proc, available processors
    priority_queue<pi, vector<pi>, greater<pi>>busy;  //heap for busy processors, with information when it gets free
    int i=0, t=1;  //i is indexing tasks, t counts the time
    while(i < m){
        while(!busy.empty() && busy.top().first <= t){ //freeing up processors that have completed the task
            free.push(busy.top().second);
            busy.pop();
        }
        if(tasks[i].first == t){
            busy.emplace(tasks[i].first + tasks[i].second, free.top());
            fout<<free.top()+1<<"\n";
            free.pop();
            i++;
        }
        t++;
    }

    fin.close();
    fout.close();
    return 0;
}