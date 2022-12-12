#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#include "heapsort.h"


typedef struct Node Node;
struct Node{
    unsigned char character;
    int weight;
    Node* left;
    Node* right;

    Node(unsigned char character, int weight, Node* left, Node* right){
        this->character = character;
        this->weight = weight;
        this->left = left;
        this->right = right;
    }

};

void transverseInOrder(Node* node, string *huffmanTreeTable, string code){
    if (node == NULL) return;
    transverseInOrder(node->left, huffmanTreeTable, code + "0");
    if(node->right == nullptr && node->left == nullptr){
        huffmanTreeTable[(unsigned char) node->character] = code;        
    } 
    transverseInOrder(node->right, huffmanTreeTable, code + "1");
}


Node* buildHuffmanTree(string textFile, ofstream &output_file){
    int characters[256];
    Node* huffmanTree[256];
    Node* huffmanTreeRoot = nullptr;

    for(int i=0; i < 256; ++i){
        characters[i] = 0;
        huffmanTree[i] = nullptr;

    } 
    ifstream file(textFile);
    if(!file.is_open()) return nullptr;
    unsigned char c; 
    while(true){
        c = file.get();
        if(file.eof()) break;
        ++characters[c];
    }
    int k=0;
    for(int i=0; i<256; ++i){
        if(characters[i] > 0){
            Node* newNode = new Node((unsigned char) i, characters[i], nullptr, nullptr);
            huffmanTree[k] = newNode;
            ++k;
        } 
    }
    buildHeap(huffmanTree, 0, k-1);
    Node *aux_1, *aux_2;
    while(k > 1){
        aux_1 = removeFromHeap(huffmanTree, k);
        aux_2 = removeFromHeap(huffmanTree, k);
        Node* z = new Node('0', aux_1->weight + aux_2->weight, aux_1, aux_2);
        addToHeap(huffmanTree, 256, k, z);
    }
    huffmanTreeRoot = removeFromHeap(huffmanTree, k);

    if(!output_file.is_open()) return nullptr;
    output_file << huffmanTreeRoot->weight << " " ; 
    for(int i=0; i< 256; ++i){
        if(characters[i] > 0){
            output_file << "*" << (unsigned char) i << characters[i];
        }

    }
    output_file << " ";

    return huffmanTreeRoot;

}

Node* buildHuffmanTreeDecompression(int *characters){
    Node* huffmanTree[256];
    Node* huffmanTreeRoot = nullptr;

    int k=0;
    for(int i=0; i<256; ++i){
        if(characters[i] > 0){
            Node* newNode = new Node((unsigned char) i, characters[i], nullptr, nullptr);
            huffmanTree[k] = newNode;
            ++k;
        } 
    }
    buildHeap(huffmanTree, 0, k-1);
    Node *aux_1, *aux_2;
    while(k > 1){
        aux_1 = removeFromHeap(huffmanTree, k);
        aux_2 = removeFromHeap(huffmanTree, k);
        Node* z = new Node('0', aux_1->weight + aux_2->weight, aux_1, aux_2);
        addToHeap(huffmanTree, 256, k, z);
    }
    huffmanTreeRoot = removeFromHeap(huffmanTree, k);
    return huffmanTreeRoot;

}
bool compress(string inputFile, string outputFile){
    cout << "Compressing..." << endl;
    ifstream input_file(inputFile);
    ofstream output_file (outputFile);
    if(!input_file.is_open() || !output_file.is_open()) return true;

    if(input_file.peek() == std::ifstream::traits_type::eof()){
        cout << "Done!" << endl;
        return true;
    }

    Node* huffmanTreeRoot = buildHuffmanTree(inputFile, output_file);
    if(huffmanTreeRoot->left == nullptr and huffmanTreeRoot->right == nullptr){
        huffmanTreeRoot = new Node('0', huffmanTreeRoot->weight, huffmanTreeRoot, nullptr);
    }
    string huffmanTreeTable[256];
    for(int i=0; i < 256; ++i){
        huffmanTreeTable[i] = "*";
    } 


    transverseInOrder(huffmanTreeRoot, huffmanTreeTable, "");

    unsigned char aux = 0;
    unsigned char currentByte;
    int currentByteFilled = 0;
    unsigned char c = 0;
    string code;

    while(true){
        c = input_file.get();
        if(input_file.eof()){
            if(currentByteFilled != 0){
                while(currentByteFilled < 8){
                    currentByte <<= 1;
                    ++currentByteFilled;
                }
                output_file << currentByte;
            }
            break;
        } 
        code = huffmanTreeTable[c];
        for(unsigned int i=0; i < code.length(); ++i){
            aux = code[i] - 48;
            currentByte = currentByte ^ aux;
            ++currentByteFilled;
            if(currentByteFilled == 8){
                output_file << currentByte;
                currentByte = 0;
                currentByteFilled = 0;
            }else{
                currentByte <<= 1;
            }
        }
    }
    cout << "Done!" << endl;

    return false;
}

bool decompress(string inputFile, string outpuFile){
    ifstream input_file(inputFile);
    ofstream output_file(outpuFile);
    string aux;
    int totalCharacters;
    int characters[256];
    unsigned char c = 0, temp_char, prev_c;
    Node *huffmanTree, *tNode;

    cout << "Decompressing..." << endl;

    for(int i=0; i < 256; ++i){
        characters[i] = 0;        
    }
    if(!input_file.is_open())return true;
    if(input_file.peek() == std::ifstream::traits_type::eof()){
        cout << "Done!" << endl;
        return true;
    }

    while(c != ' '){
        c = input_file.get();
        if(input_file.eof()){
            break;
        }
        aux += c;

    }
    totalCharacters = stoi(aux);
    aux = "";

    prev_c = '*';
    c =input_file.get();
    while(true){
        if(c == ' ' && prev_c != '*') break;
        temp_char = input_file.get();
        prev_c = c;
        c = temp_char;
        while(true){
            prev_c = c;
            c = input_file.get();
            if(c == '*' || c == ' ') break;
            aux += c;
        }
        characters[(unsigned int)temp_char] = stoi(aux);
        aux = "";

    }
    huffmanTree = buildHuffmanTreeDecompression(characters);
    if(huffmanTree->left == nullptr and huffmanTree->right == nullptr){
        huffmanTree = new Node('0', huffmanTree->weight, huffmanTree, nullptr);
    }

    if(!output_file.is_open()) return true;
    tNode = huffmanTree;
    int k=0;
    int m =0;
    while(k < totalCharacters){
        c = input_file.get();
        m = 0;
        while(m < 8){
            c >= 128 ? tNode = tNode->right : tNode = tNode->left;
            c <<= 1;
            m++;
            if(tNode->left == nullptr and tNode->right == nullptr){
                output_file << tNode->character;
                tNode = huffmanTree;
                ++k;
                if(k >= totalCharacters) break;
            }
            
        }
    }    
    cout << "Done!" << endl;
    return false;
}

int main(int, char *argv[]){
    string operation, inputFile, outputFile;

    operation = argv[1];
    inputFile = argv[2];
    outputFile = argv[3]; 
   if(operation == "--compress"){
       compress(inputFile, outputFile);
   }else if(operation == "--decompress"){
       decompress(inputFile, outputFile);
   }
    return 0;
}