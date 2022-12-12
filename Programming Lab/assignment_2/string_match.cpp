// José Douglas Gondim Soares 485347

#include <iostream>
#include "instancias_Reais_Trabalho_2.hpp"
using std::cout;
using std::endl;
using std::stoi;


int calculatePatternSize(const char *P){
    int i;
    for(i=0; P[i] != '\0'; ++i){}
    return i;

}

bool brute_force(const char *T, const char *P, int *O){
    int i = 0, j, lastMatch = 0, k;
    while(T[i] != '\0'){
        j = 0;
        k = i;
        while(P[j] != '\0' && T[k] == P[j]){
            ++j;
            ++k;
        }
        if(P[j] == '\0'){
            O[lastMatch] = i;
            ++lastMatch;
        } 
        ++i;
        
    }
    O[lastMatch] = -1;
    return true;
}


int* generate_lps(const char *P){
    int patternSize = calculatePatternSize(P);
    int len = 0;
    int i=1;
    int* lps = new int[patternSize];   
    if(lps == NULL) return NULL;
    
    lps[0] = 0;                

    while (i<patternSize){
        if(P[i]==P[len]){   
            len++;
            lps[i] = len;
            i++;
        }
        else if(len==0){        
                lps[i] = 0;
                i++;
        }
        else{              
            len = lps[len-1];
        }
        
    }
    return lps;
}

bool KMP(const char *T, const char *P, int *O){
    int n = calculatePatternSize(T);
    int m = calculatePatternSize(P);
    int* lps = generate_lps(P); 
    if(lps == NULL) return false;
    
    int i=0,j=0, k=0;
    while(i<n){
        if(T[i] == P[j]){i++;j++;} 
        if (j == m) { 
            O[k] = i-m;
            k++; 
            j = lps[j - 1]; 
        } 
        else if (i < n && P[j] != T[i]) {
            j == 0 ? ++i : j = lps[j-1];
        }
    }
    O[k] = -1;
    delete[] lps;
    return true;
}


int main(int, char *argv[]){
    char instanceType = *argv[1];
    char l;
    int m, n, I, x, y, bruteForceMS = 0, kmpMS = 0;
    char* pattern;
    char* text;
    int* bruteForceO;
    int* kmpO;
    srand(time(0)); // resets timer for randomness
    switch (instanceType){
        case 'A':
            l = argv[2][0]; // limiting char
            m = stoi(argv[3]); // pattern size
            n = stoi(argv[4]); // text size
            I = stoi(argv[5]); // number of instances
            pattern = new char[m];
            text = new char[n];
            bruteForceO = new int[n+1];
            kmpO = new int[n+1];

            for(int i=0; i < I; ++i){
                for(int j=0; j < m; ++j){
                    pattern[j] = 'a' + (rand() % (int)(l - 'a' + 1));
                }
                for(int j=0; j < n; ++j){
                    text[j] = 'a' + (rand() % (int)(l - 'a' + 1));
                }

                auto start = std::chrono::high_resolution_clock::now();
                brute_force(text, pattern, bruteForceO);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
                bruteForceMS += duration.count();


                start = std::chrono::high_resolution_clock::now();
                if(!KMP(text, pattern, kmpO)) return -1;
                stop = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
                kmpMS += duration.count();

            }

            // check if the results are the same for kmpO and bruteForceO
            for(int i=0; i < n+1; ++i){
                if(bruteForceO[i] != kmpO[i]) {
                    cout << "Different results!" << endl;
                    return -1;
                }
            }

            delete[] pattern;
            delete[] text;
            delete[] bruteForceO;
            delete[] kmpO;
            break;
        case 'R':
            x = stoi(argv[2]);
            y = stoi(argv[3]);
            n = calculatePatternSize(Texto_Livros);
            bruteForceO = new int[n+1];
            kmpO = new int[n+1];
            for(int i=x; i <= y; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                brute_force(Texto_Livros, Padroes_Palavras[i], bruteForceO);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
                bruteForceMS += duration.count();


                start = std::chrono::high_resolution_clock::now();
                if(!KMP(Texto_Livros, Padroes_Palavras[i], kmpO)) return -1;
                stop = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
                kmpMS += duration.count();

                for(int i=0; i < n+1; ++i){
                    if(bruteForceO[i] != kmpO[i]) {
                        cout << "Different results!" << endl;
                        return -1;
                    }
                }
            }
            delete[] bruteForceO;
            delete[] kmpO;

            break;
        default:
            cout << "Invalid Mode." << endl;
            return -1;
            break;
    }
            cout << "Brute Force: " << bruteForceMS/1000.0  << " seconds." << endl;
            cout << "KMP: " << kmpMS/1000.0 << " seconds." << endl;

    return 0;
}
