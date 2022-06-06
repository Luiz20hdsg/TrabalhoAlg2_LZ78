#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>

#include "CompressorLZ78.h"

using namespace std;

void CompressorLZ78::compressao(string entrada, string saida){

    int indice;
    char letra;
    
    Trie* arvore = new Trie();
    TrieNode* no = arvore->getRaiz();
    TrieNode* noFilho;

    ifstream arqEntrada;
    ofstream arqSaida;
   
	arqEntrada.open(entrada, ifstream::binary);
	arqSaida.open(saida, ofstream::out);
    
    if(arqEntrada.is_open()){

        if(arqSaida.is_open()){

            while(arqEntrada.get(letra)){
            
                indice = no->getIndice();
                noFilho = no->getFilho_prefixo(string(1, letra));

                if(noFilho == nullptr){

                    arqSaida.write((char*)(&indice), sizeof(int));
                    arqSaida.write(&letra, sizeof(char));
                    arvore->adicionar(no, string(1, letra));
                    no = arvore->getRaiz();

                }else{

                    no = noFilho;

                }

                indice = no->getIndice();

                if(no != arvore->getRaiz()){

                    char fim_arq = (char)4;
                    arqSaida.write((char*)(&indice), sizeof(int));
                    arqSaida.write((char*)(&fim_arq), sizeof(char));

                }

            }

        }else{

            cout<<"ERRO: O arquivo de saida não pode ser aberto!"<<endl;

        }
    }else{

        cout<<"ERRO: O arquivo de entrada não pode ser aberto!"<<endl;
    }

    delete arvore;
    arqEntrada.close();
	arqSaida.close();

}

void CompressorLZ78::descompressao(string entrada, string saida){

    Trie* arvore = new Trie();
    TrieNode* no = nullptr;
    TrieNode* noAtual = nullptr;
    map<int, TrieNode*> dicionario;

    int *indice = (int*) malloc(sizeof(int));
    char *letra = (char*) malloc(sizeof(char));

    ifstream arqEntrada;
    ofstream arqSaida;
    char fim_arq = (char)4;
   
	arqEntrada.open(entrada, ifstream::binary);
	arqSaida.open(saida, ofstream::out);

    if(arqEntrada.is_open()){
        
        if(arqSaida.is_open()){
           
            while(arqEntrada.read((char *)indice, sizeof(int)) && arqEntrada.read(letra, sizeof(char))){
            
                if(*indice == 0){

                    arqSaida << *letra;
                    no = arvore->adicionar(arvore->getRaiz(),string(1, *letra));
                    dicionario[no->getIndice()] = no;

                }else{
                    
                    dicionario[*indice];

                    if(noAtual != nullptr){

                        if(*letra != fim_arq){

                            arqSaida << noAtual->getprefixo_inteiro() << *letra;

                        }else{

                            arqSaida << noAtual->getprefixo_inteiro();

                        }

                        no = arvore->adicionar(no,string(1, *letra));

                        dicionario[no->getIndice()] = no;

                    }


                }

            }
        }else{

            cout<<"ERRO: O arquivo de saida não pode ser aberto!"<<endl;
            

        }

    }else{

        cout<<"ERRO: O arquivo de entrada não pode ser aberto!"<<endl;
        
    }

    delete arvore;
    free(indice);
    free(letra);

}