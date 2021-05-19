#include <fstream>
#include <iostream>

using namespace std;

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int N;
    in >> N; 
    
    int first, second;
    int max_difference = -1;
    //leggo direttamente il primo valore dal file
    in >> first;
    //ciclo dal secondo valore in poi
    for(int i = 1; i < N; i++){
        //leggo il secondo valore
        in >> second;
        //attenzione: dovete fare il modulo 
        max_difference = max(max_difference, max(first - second, second - first));
        //assegno a first il valore appena letto
        first = second;
    }

    out << max_difference;

    return 0;
}