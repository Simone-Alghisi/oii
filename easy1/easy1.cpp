#include <fstream>
#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");
    
    //istanzio una variabile che conterra' il numero di elementi da analizzare...
    int N;
    //...e le attribuisco il valore presente nel file
    in >> N;

    //istanzio una variabile che userò per memorizzare il numero massimo 
    int max_number = INT_MIN;
    //istanzio una variabile che conterrà un valore temporaneo, che dovrò controllare
    int tmp = 0;

    //per ogni numero che devo analizzare
    for(int i = 0; i < N; i++){
        //leggo un numero dal file...
        in >> tmp;

        /**
         * ...e assegno a max_number il massimo tra tmp e se' stesso: come mai?
         * banalmente è possibile che il numero che ho dichiarato come "massimo" sia
         * più grande di quello precedente, altrimenti varrà il contrario
        **/
        max_number = max(max_number, tmp);
    }

    //stampo il risultato sul file di output
    out << max_number;
}