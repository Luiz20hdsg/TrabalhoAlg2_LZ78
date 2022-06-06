

CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp01 # nome do executavel que sera gerado, nao troque
TMPOUT=tp01.testresult


$(EXEC): main.cpp CompressorLZ78.o Trie.o TrieNode.o
	$(CC) $(CFLAGS)  main.cpp CompressorLZ78.o Trie.o TrieNode.o -o $(EXEC)
	
main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o

CompressorLZ78.o: CompressorLZ78.cpp 
	$(CC) $(CFLAGS) -c CompressorLZ78.cpp -o CompressorLZ78.o

Trie.o: Trie.cpp 
	$(CC) $(CFLAGS) -c Trie.cpp -o Trie.o

TrieNode.o: TrieNode.cpp 
	$(CC) $(CFLAGS) -c TrieNode.cpp -o TrieNode.o

test: $(EXEC)
	
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao




