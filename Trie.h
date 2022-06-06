#include <iostream>
#include <string>

#include "TrieNode.h"

using namespace std;

class Trie{

    private:
        TrieNode* raiz;
        int tam;

    public:
        Trie();
        ~Trie();
        int getTam() const;
        bool vazia() const;
        TrieNode* getRaiz();
        TrieNode* pesquisar(int indice);
        TrieNode* adicionar(TrieNode* node, string prefixo); 
        
};