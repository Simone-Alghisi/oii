# Contenuto

La cartella contiene un file chiamato **base.cpp** che potete copiare e utilizzare come scheletro per ogni esercizio che affronteremo. Qui sotto trovate inoltre i costrutti più utilizzati del C/C++ con una loro breve descrizione.

## Codice C++

In questa sezione avete la possibilità di dare un'occhiata alla sintassi dei costrutti più utilizzati in C/C++ nel caso in cui aveste dubbi o non conosceste il funzionamento.

### If-Else

L'if-else è un costrutto che vi permette di eseguire una determinata operazione (contenuta nel ramo if) al verificarsi di una data condizione. Nel caso in cui la condizione si rivelasse essere falsa, verrà eseguito il codice contenente nel ramo else

```C++
if(a == 4){
    //codice da eseguire nel caso in cui la condizione sia vera (quindi il valore di a e' 4)
} else {
    //codice da eseguire nel caso in cui la condizione e' falsa (il valore di a non e' 4)
}
```

Notare che non è necessario avere per forza il ramo else

```C++
if(a == 4){
    //codice da eseguire nel caso in cui la condizione sia vera (quindi il valore di a e' 4)
}
//se la condizione e' falsa si passa alle istruzioni successive
```

Inoltre è possibile concatenare più if-else nel seguente modo:

```C++
if(a == 4){
    //codice da eseguire nel caso in cui la condizione sia vera (quindi il valore di a e' 4)
} else if(a == 3) {
    //codice da eseguire nel caso in cui la condizione precedente e' falsa e il valore di a e' 3
} else if(a == 2) {
    //codice da eseguire nel caso in cui la condizione precedente e' falsa e il valore di a e' 2
} else {
    //codice da eseguire nel caso in cui tutte le condizioni precedenti sono false
}
```

### For

Il for è un costrutto che vi permette di ripetere più volte del codice all'interno: la sua struttura si compone di

* una variabile che viene inizializzata ad un valore (es: int i = 0)
* una condizione di arresto, per sapere quando interrompere il ciclo (es: i < N)
* una condizione per poter incrementare il valore della variabile iniziale: questa è fondamentale per poter fare in modo che il vostro ciclo abbia una durata finita

```C++
for(int i = 0; i < N; i++){
    //codice da eseguire
}
```

Nell'esempio precedente il ciclo verrà eseguito esattamente N volte, questo perchè, dopo ogni esecuzione del codice, verrà incrementata la variabile i e, prima di ogni nuova esecuzione, verificata la condizione i < N: questo porterà dunque al seguente flusso di esecuzione

1. i viene inizializzata a 0
2. viene verificato se i < N
3. se i < N 
    * si esegue il codice
    * si incrementa il valore di i di 1
    * si ripete dal punto 2
4. se i >= N si esce dal ciclo

**N.B.** il For è un costrutto ottimo da utilizzare quando sapete di voler ripetere l'esecuzione del codice un numero determinato di volte (nell'esempio, N volte)

### While

Il costrutto while viene utilizzato anch'esso per ripetere l'esecuzione di un determinato codice: a differenza del for la sua struttura è un po' più semplice e il suo uso è indicato nel caso in cui si voglia eseguire del codice fino al verificarsi di una data condizione (che potrebbe non essere deterministica, es: fino a quando non leggo un numero pari)

```C++
bool isTrue = true;

while(isTrue){
    //codice da eseguire

    //condizione per cui la variabile isTrue diventa falsa e il while termina
    if(a == 4){
        isTrue = false;
    }
}
```

In questo caso il flusso di esecuzione è il seguente:

1. si verifica se la condizione isTrue è vera
2. se così fosse
    * si esegue il codice nel while
    * si verifica se il valore di a è 4 e in quel caso si imposta isTrue a falso
    * si ripete dal punto 2
3. altrimenti si esce dal while

**ATTENZIONE:** a differenza del for è necessario inserire all'interno del while un'istruzione che modifichi il valore della condizione da controllare, altrimenti il programma andrà in loop all'infinito

### Lettura da File

Per poter leggere da un file in modo facile è necessario
* includere prima del main la libreria *fstream*
* specificare il file su cui si vuole leggere (useremo sempre input.txt)

Per chiarire ogni dubbio utilizziamo un esempio:

```C++
//libreria per poter utilizzare i file con facilità
#include <fstream>

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");

    //variabile dove memorizzare il valore letto dal file
    int N;
    //metodo per poter leggere un singolo numero dal file
    in >> N;

    int R, S;
    //...è possibile inoltre leggere più di un elemento dal file in una sola volta
    in >> R >> S;

    return 0;
}
```

**ATTENZIONE:** Per poter leggere dal file *input.txt* è necessario che nella cartella dove viene eseguito il programma sia presente il file specicato. Nel caso in cui non ci fosse:

* premere tasto destro del mouse
* cliccare su Nuovo
* cliccare su Documento di testo
* scegliere come nome del file input (l'estensione di default è sempre .txt)

### Scrivere su File

**ATTENZIONE:** se avete già incluso la libreria *fstream* per leggere da un file, non includetela nuovamente (a C non piacciono queste cose)

Per poter scrivere su un file in modo facile è necessario
* includere prima del main la libreria *fstream*
* specificare il file su cui si vuole scrivere (useremo sempre output.txt)

Per chiarire ogni dubbio utilizziamo un esempio:

```C++
//libreria per poter utilizzare i file con facilità
#include <fstream>

//struttura base del programma
int main(){
    //file da cui leggere
    ofstream out("output.txt");

    //è possibile scrivere banalmente un numero
    out << 42;

    int N = 42;
    //oppure anche il valore contenuto in una variabile
    out << N;

    return 0;
}
```

**ATTENZIONE:** Ogni volta che viene utilizzato *out* si scrive su una nuova riga del file, tuttavia nel momento in cui aprite il file la prima volta (*ofstream out("output.txt");*) cancellate il suo contenuto. In questo caso non è necessario creare il file *output.txt*: nel caso in cui non fosse presente verrà creato direttamente dal programma

### max e min

max e min sono due funzioni molto comode che vi permettono di selezionare il massimo oppure il minimo tra due elementi, senza dover fare un if-else. max (o min) vuole esattamente due argomenti per essere utilizzato, cioè i due numeri che devono essere confrontati, e restituiscono rispettivamente il massimo (o il minimo) tra i due. 

```C++
int a = 1;
int b = 2;
int massimo, minimo;

massimo = max(a, b);
minimo = min(a, b);
```

In questo caso dunque i valore contenuto nella variabile massimo sarà pari a 2, cioè il valore contenuto nella variabile b; memorizzato all'interno di minimo vi sarà invece 1, cioè il valore di a. 

**N.B.** Notare che l'ordine con cui inserite gli argomenti è totalmente indifferente: *max(a, b)* fornisce lo stesso risultato di *max(b, a)*. 











