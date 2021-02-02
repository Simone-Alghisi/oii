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
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    return 0;
}