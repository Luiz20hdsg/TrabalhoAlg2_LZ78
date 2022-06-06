#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode{

    private:
        friend class Trie;
        string prefixo;
        int indice;
        TrieNode* noPai;
        vector<TrieNode*> filhos;

    public:
        TrieNode(int indice, string prefixo);
		~TrieNode();
        string getPrefixo();
        int getIndice();
        string getprefixo_inteiro();
        vector<TrieNode*> getFilhos();
        TrieNode* getFilho_indice(int i);
        TrieNode* getFilho_prefixo(string prefixo);
    
};