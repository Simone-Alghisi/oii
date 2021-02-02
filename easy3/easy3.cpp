#include <fstream>
#include <iostream>
using namespace std;

int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");
    
    //istanzio una variabile che conterra' il numero di coppie da analizzare...
    int N;
    //...e le attribuisco il valore presente nel file
    in >> N;

    //inizializzo la somma massima a -1 (poiche' nel caso in cui non vi siano somme pari bisogna restituire quel valore)
    int max_sum = -1;
    //istanzio una variabile che conterrà un valore temporaneo, che dovrò controllare
    int tmp = 0;
    //inizializzo anche due vettori temporanei per salvare coppie di numeri pari e dispari
    int odd[2] = {-1, -1}, even[2] = {-1, -1};

    //per ogni numero che devo analizzare
    for(int i = 0; i < N; i++){
        //leggo il numero dal file
        in >> tmp;
        //verifico che il resto per la divisione per 2 sia 0 (cioe' se e' pari)
        if(tmp % 2 == 0){
            //verifico se uno dei due elementi della coppia è minore del numero che ho letto in input
            if(even[0] < tmp || even[1] < tmp){
                //assegno il maggiore dei due in posizione 0
                even[0] = max(even[0], even[1]);
                //e sostituisco l'altro con tmp
                even[1] = tmp;
            }
        } else {
            //nel caso in cui invece il numero considerato e' dispari

            //verifico se uno dei due elementi della coppia è minore del numero che ho letto in input
            if(odd[0] < tmp || odd[1] < tmp){
                //assegno il maggiore dei due in posizione 0
                odd[0] = max(odd[0], odd[1]);
                //e sostituisco l'altro con tmp
                odd[1] = tmp;
            }
        }
    }

    //verifico che esista una coppia di numeri pari
    if(even[0] != -1 && even[1] != -1){
        //e scelgo il maggiore tra max_sum e la somma della coppia
        max_sum = max(max_sum, even[0] + even[1]);
    }

    //faccio lo stesso per i numeri dispari
    if(odd[0] != -1 && odd[1] != -1){
        max_sum = max(max_sum, odd[0] + odd[1]);
    }

    //stampo il risultato sul file di output
    out << max_sum;

    return 0;
}