#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <random>
using namespace std;

struct nodo{
    vector<int> vic;
    bool type0 = false;
    int erdos = INT_MAX;
};

int erdos(vector<nodo> grafo, int node, vector<bool> &done);

int main(){
    ifstream in("interruttori_input_1.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for(int i = 1; i <= T; i++){
        int N, A, B;
        vector<nodo> grafo;
        in >> N >> A >> B;
        grafo.resize(N);
        vector<bool> done(N, false);
        vector<int> elements(N);

        for(int j = 0; j < N; j++){
            elements[j] = j;
        }

        for(int y = 0; y < A; y++){
            int zero;
            in >> zero;
            //cout << zero << endl;
            grafo[zero].type0 = true;
        }

        //cout << "----" << endl;

        for(int y = 0; y < B; y++){
            int from, to;
            in >> from >> to;
            //cout << from << " " << to << endl;
            grafo[from].vic.push_back(to);
            grafo[to].vic.push_back(from);
        }

        //cout << "inizio erdos" << endl;
        
        int bulb = 0;
        int nSwitch = 0;
        int tmp = 0;
        int tmpSwap = 0;
        default_random_engine generator;
        for(int y = 0; y < N; y++){
            uniform_int_distribution<int> distribution(0,N-1-y);
            int index = distribution(generator);
            int element = elements[index];
            if(!done[element]){
                cout << "erdos di " << element << endl;
                tmp = erdos(grafo, element, done);
                if(tmp > nSwitch){
                    nSwitch = tmp;
                    bulb = element;
                }
            }
            elements[index] = elements[N-1-y];
        }
        //cout << "finisco erdos" << endl;

        out << "Case #" << i << ": " << bulb << " " << nSwitch << endl;
    }
    
}

int erdos(vector<nodo> grafo, int node, vector<bool> &done){
    queue<int> q;
    q.push(node);
    grafo[node].erdos = 0;
    while(!q.empty()){
        int estratto = q.front();
        q.pop();
        //cout << "estraggo " << estratto << " con erdos " << grafo[estratto].erdos << endl;
        if(grafo[estratto].type0){
            //cout << "ritorno " << grafo[estratto].erdos << endl;
            int current = estratto;
            do{
                done[current] = true;
                //cout << "sono passato da " << current << endl;
                for(int i=0; i<grafo[current].vic.size(); i++){
                    int adiacente = grafo[current].vic[i];
                    if(grafo[adiacente].erdos < grafo[current].erdos){
                        current = adiacente;
                        break;
                    }
                }
            }while(grafo[current].erdos > 0 && !done[current]);

            return grafo[estratto].erdos + 1;
        }
        for(int i=0; i<grafo[estratto].vic.size(); i++){
            int adiacente = grafo[estratto].vic[i];
            //cout << "inserisco " << adiacente << endl;
            if(grafo[adiacente].erdos == INT_MAX){
                q.push(adiacente);
                grafo[adiacente].erdos = grafo[estratto].erdos+1;
            }
        }
    }
    return INT_MIN;
}