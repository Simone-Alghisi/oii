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
    //inizializzo anche due variabili temporanee per leggere i numeri da sommare
    int tmp1 = 0, tmp2 = 0;
    //infine inizializzo una somma temporanea dove verrà memorizzato il risultato prima di eseguire i controlli
    int tmp_sum = 0;

    //per ogni coppia che deve essere analizzata
    for(int i = 0; i < N; i++){
        //leggo i due numeri che costituiscono la coppia
        in >> tmp1 >> tmp2;
        //memorizzo nella variabile temporanea la loro somma
        tmp_sum = tmp1 + tmp2;
        //verifico che il resto per la divisione per 2 sia 0 (cioe' se e' pari)
        if(tmp_sum % 2 == 0){
            //salvo in max_sum il massimo tra max_sum e tmp_sum
            max_sum = max(max_sum, tmp_sum);
        }
    }

    //stampo il risultato sul file di output
    out << max_sum;
}