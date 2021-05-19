#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

// trie node
struct TrieNode{
    vector<TrieNode*> children;
    int number = -1;
    int competence = INT_MIN;
};

// Returns new trie node (initialized to NULLs)
TrieNode* getNode(){
	TrieNode *pNode = new TrieNode;
	return pNode;
}

void swap(TrieNode* a, TrieNode* b){
    TrieNode* tmp = getNode();
    tmp->number = a->number;
    tmp->competence = a->competence;
    a->number = b->number;
    a->competence = b->competence;
    b->number = tmp->number;
    b->competence = tmp->competence;
}

int maxHeapRestore(TrieNode* node){
    TrieNode* max = node;
    TrieNode* child;
    //cout << "restore di " << node->number << endl;
    for(int i = 0; i < node->children.size(); i++){
        child = node->children[i];
        //cout << "nodo " << child->number << endl;
        if(max->competence < child->competence){
            //cout << child->number << " ha competenza " << child->competence <<  " > " << max->competence << " di " << max->number << endl;
            max = child;
        }
    }
    if(max != node){
        //cout << "scambio " << node->number << " con " << max->number << endl;
        swap(node, max);
        return 1 + maxHeapRestore(max);
    }
    return 0;
}

int postOrderVisit(TrieNode* node){
    int toRtn = 0;
    for(int i = 0; i < node->children.size(); i++){
        toRtn += postOrderVisit(node->children[i]);
    }
    //cout << "da restituire: " << toRtn << endl;
    return toRtn + maxHeapRestore(node);
}

int main(){
    ifstream in("gerarchie_input_1.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for(int i = 1; i <= T; i++){
        int N;
        in >> N;
        vector<TrieNode*> tree(N);
        for(int y = 0; y < N; y++){
            tree[y] = getNode();
        }
        TrieNode* root;
        int R, C;
        for(int y = 0; y < N; y++){
            in >> R >> C;
            tree[y]->number = y;
            tree[y]->competence = C;
            if(R != -1){
                tree[R]->children.push_back(tree[y]);
            } else {
                root = tree[y];
            }
        }
        
        /*
        swap(tree, 0, 1);
        //cout << endl;
        for(int node = 0; node < N; node++){
            //cout << "nodo " << node << " con competenza " <<  tree[node].competence << " e figli ";
            for(int child = 0; child < tree[node].children.size(); child++){
                //cout << tree[node].children[child] << " ";
            }
            //cout << endl;
        }
        //cout << endl << endl;
        */

        out << "Case #" << i << ": " << postOrderVisit(root) << endl;

        for(int y = 0; y < N; y++){
            //cout << "nodo " << tree[y]->number << " con competenza " <<  tree[y]->competence << " e figli ";
            for(int k = 0; k < tree[y]->children.size(); k++){
                //cout << tree[y]->children[k]->number << " ";
            }
            //cout << endl;
        }
    }
    
}

