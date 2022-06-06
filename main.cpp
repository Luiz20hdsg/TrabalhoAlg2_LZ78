#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

#include "CompressorLZ78.h"

using namespace std;

int main(int argc, char *argv[]){
     
    CompressorLZ78* compressor = new CompressorLZ78();
    
     if(argc < 3){

        cout << "ERRO! Não foram passados comandos suficientes\n";
        exit(1);
    }

    string arqEntrada(argv[2]);
    string arqSaida = "";
    int ponto_arq; 
    stringstream extensao_stream;
    
    if(argc >= 4){

        arqSaida = string(argv[3]);

    }else{

        ponto_arq = arqEntrada.find_last_of('.');

        extensao_stream << arqEntrada.substr(0, ponto_arq);
    }

    if(strncmp(argv[1], "-c", 3) == 0){

        if(argc < 4){

            extensao_stream << ".z78";
            arqSaida = extensao_stream.str();
           
           
        }

        cout << "Executando compressão do arquivo"<<endl;

        compressor->compressao(arqEntrada, arqSaida);

        cout << "Processo finalizado!"<<endl;

    }else if(strncmp(argv[1], "-x", 3) == 0){
   
        if(argc < 4){

            extensao_stream << ".txt";
            arqSaida = extensao_stream.str();
            arqSaida = arqEntrada+".z78";
           
        }

        cout << "Executando descompressão de arquivo"<<endl;

        compressor->descompressao(arqEntrada, arqSaida);

        cout << "Processo finalizado!"<<endl;

    }else{
    
        cout << "ERRO! Comandos invalidos " << argv[1] << "\n";
        exit(1);

    }


    return 0;

}