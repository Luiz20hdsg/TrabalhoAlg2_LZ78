#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

#include "TrieNode.h"

using namespace std;

TrieNode::TrieNode(int indice, string prefixo){

    this->indice = indice;
    this->prefixo = prefixo;
    this->noPai = nullptr;

}

TrieNode::~TrieNode(){

    vector<TrieNode*>::iterator iterador =  this->filhos.begin();

    for(;iterador != this->filhos.end();++iterador){

        TrieNode* filho = *iterador;
        delete filho;

    }

}

string TrieNode::getPrefixo(){

    return this->prefixo;

}

int TrieNode::getIndice(){

    return this->indice;

}

string TrieNode::getprefixo_inteiro(){

    TrieNode* pointer = this->noPai;
    stringstream stream;
    stream << this->prefixo;

    for(; pointer != nullptr; pointer = pointer->noPai){

        stream << pointer->prefixo;

    }

    string invPrefixo = stream.str();

    return string(invPrefixo.rbegin(), invPrefixo.rend());

}

vector<TrieNode*> TrieNode::getFilhos(){

    return this->filhos;

}

TrieNode* TrieNode::getFilho_indice(int i){

    return this->filhos.at(i);

}

TrieNode* TrieNode::getFilho_prefixo(string prefixo){

    vector<TrieNode*>::iterator iterator = this->filhos.begin();

    for(; iterator != this->filhos.end(); ++iterator){

        if((*iterator)->prefixo.compare(prefixo) == 0){

            return *iterator;

        }

    }
    
    return nullptr;

}

