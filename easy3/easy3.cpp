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
    //infine inizializzo una somma temporanea dove verrà memorizzato il risultato prima di eseguire i controlli
    int tmp_sum = 0;

    //per ogni numero che devo analizzare
    for(int i = 0; i < N; i++){
        //leggo il numero dal file
        in >> tmp;
        //verifico che il resto per la divisione per 2 sia 0 (cioe' se e' pari)
        if(tmp % 2 == 0){
            //salvo in max_sum il massimo tra max_sum e tmp_sum
            max_sum = max(max_sum, tmp_sum);
        } else {
            //altrimenti il numero che sto analizzando e' dispari
        }
    }

    //stampo il risultato sul file di output
    out << max_sum;
}