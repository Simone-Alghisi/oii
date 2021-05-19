//libreria per poter utilizzare i file con facilità
#include <fstream>
//libreria per poter fare cout e cin e quindi gestire I/O da terminale (la useremo per test)
#include <iostream>

//Inserite le altre librerie che potrebbero servirvi qui

//per evitare di usare std::
using namespace std;

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("pesci_input_1.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int T = 0;
    in >> T;
    //printf("%d\n", T);

    for(int i = 1; i <= T; i++){
        int fishes = 0;
        int N = 0;
        int K = 0;
        in >> N >> K;
        while(N > 0){
            fishes += N;
            N /= K;
        }
        out << "Case #" << i << ": " << fishes << endl;
        //printf("%d\n", fishes);
    }

    return 0;
}