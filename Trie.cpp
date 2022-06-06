#include<iostream>
#include<string>
#include<iostream>
#include<sstream>
#include<queue>

#include "Trie.h"

using namespace std;

Trie::Trie(){
   
   this->raiz = new TrieNode(0,"");
   this->tam = 1;

}

Trie::~Trie(){

	delete this->raiz;

}

int Trie::getTam()const{

    return this->tam;
}

bool Trie::vazia() const {

	return this->tam == 0;

}

TrieNode* Trie::getRaiz(){

    return this->raiz;

}

TrieNode* Trie::pesquisar(int indice){

    queue<TrieNode*> noVisitado;
    vector<TrieNode*>::iterator iterator = this->raiz->filhos.begin();

    if(indice == 0){

        return this->raiz;

    }

    for(iterator; iterator != this->raiz->filhos.end(); ++iterator){

        noVisitado.push(*iterator);

    }

    while(!noVisitado.empty()){

        TrieNode* pointer = noVisitado.front();
        noVisitado.pop();
        
        if(pointer->indice == indice){

            return pointer;

        }else{
                
            for(iterator = pointer->filhos.begin(); iterator != pointer->filhos.end(); ++iterator){

                noVisitado.push(*iterator);

            }

        }
    }

    return nullptr;
}

TrieNode* Trie::adicionar(TrieNode* noAtual, string prefixo){

        TrieNode* no = new TrieNode(this->tam, prefixo);

        noAtual->filhos.push_back(no);

        no->noPai = noAtual;

        this->tam++;

        return no;

}
