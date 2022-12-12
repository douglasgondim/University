#ifndef iostream
#include <iostream>
#endif

#ifndef std
using namespace std;
#endif

template<typename T>
class Matrix{
    private:
        T** matrix;
        int numOfLines, numOfCols;


    public:
        friend istream &operator>>( istream  &input, Matrix &M ) { 
            for(int i=0; i < M.numOfLines; ++i){
                for(int j = 0; j < M.numOfCols; ++j){
                    input >> M.matrix[i][j];
                }
            }
             return input;            
        }
        friend ostream &operator<<( ostream &output, const Matrix &M ) { 
            for(int i=0; i < M.numOfLines; ++i){
                for(int j = 0; j < M.numOfCols; ++j){
                    cout << M.matrix[i][j] << " ";
                 }
                output << endl;
                
            }
            return output;            
        }

        Matrix operator+(Matrix B){
            if(numOfLines != B.numOfLines || numOfCols != B.numOfCols){
                cout << "Error. Soma de matrizes precisa ter matrizes de dimensões iguais." << endl;
                return Matrix(0,0);
            }
            Matrix aux = Matrix(numOfLines, numOfCols);
                for(int i=0; i < numOfLines; ++i){
                    for(int j = 0; j < numOfCols; ++j){
                        aux[i][j] = matrix[i][j] + B[i][j];
                    }
                }
            return aux;
        }


        Matrix operator-(Matrix B){
            if(numOfLines != B.numOfLines || numOfCols != B.numOfCols){
                cout << "Error. Soma de matrizes precisa ter matrizes de dimensões iguais." << endl;
                return Matrix(0,0);
            }
            Matrix aux = Matrix(numOfLines, numOfCols);
                for(int i=0; i < numOfLines; ++i){
                    for(int j = 0; j < numOfCols; ++j){
                        aux[i][j] = matrix[i][j] - B[i][j];
                    }
                }
            return aux;
        }

     

        Matrix operator*(T _const){
            Matrix aux = Matrix(numOfLines, numOfCols);
            for(int i=0; i < numOfLines; ++i){
                for(int j = 0; j < numOfCols; ++j){
                    aux[i][j] = matrix[i][j] * _const;
                }
            }
            return aux;
        }

        Matrix operator*(Matrix B){
            if(numOfCols != B.numOfLines){
                // cout << B << endl;
                cout << "Error. O número de colunas da matriz A=" << numOfCols << " é diferente do numero de linhas da matriz B=" << B.numOfLines << endl;
                return Matrix(0,0);
            }

            Matrix aux = Matrix(numOfLines, B.numOfCols);
            for(int i = 0; i < numOfLines; ++i){
                for (int j=0; j < B.numOfCols; ++j){
                    for(int k=0; k < numOfCols; ++k){
                        aux[i][j] += matrix[i][k] * B[k][j];
                    }
                }
            }

            return aux;
        }

         Matrix operator/(T _const){
            Matrix aux = Matrix(numOfLines, numOfCols);
            for(int i=0; i < numOfLines; ++i){
                for(int j = 0; j < numOfCols; ++j){
                    aux[i][j] = matrix[i][j] / _const;
                }
            }
            return aux;
        }

        Matrix operator/(Matrix B){
            if(numOfCols != B.numOfLines){
                cout << "Error. O número de colunas da matriz A é diferente do numero de linhas da matriz B" << endl;
                return Matrix(0,0);
            }

            Matrix aux = Matrix(B.numOfCols, numOfLines);
             
            for(int i=0; i < numOfLines; ++i){
                for(int j = 0; j < numOfCols; ++j){
                    aux[i][j] = matrix[i][j] / B[i][j];
                }
            }

            return aux;
        }

        Matrix sqrtmat(){
            Matrix aux = Matrix(numOfLines, numOfCols);
            for(int i=0; i < numOfLines; ++i){
                for(int j = 0; j < numOfCols; ++j){
                    aux[i][j] = sqrt(matrix[i][j]);
                }
            }
            return aux;
        }

        Matrix copy(){
            Matrix aux = Matrix(numOfLines, numOfCols);
            for(int i =0; i < numOfLines; ++i){
                for(int j = 0; j < numOfCols; ++j){
                    aux[i][j] = matrix[i][j];
                }
            }
            return aux;
        }
        Matrix operator=(T value){ cout << "Att\n";matrix = value;}

        T* operator[](int pos){
            return matrix[pos];
        } 
            
        Matrix transpose(){
            Matrix aux = Matrix(numOfCols, numOfLines);
            for(int i=0; i < numOfLines; ++i){
                for(int j = 0; j < numOfCols; ++j){
                    aux[j][i] = matrix[i][j];
                }
            }
            return aux;
        }
            

        Matrix(int numOfLines, int numOfCols){
            this->numOfLines = numOfLines;
            this->numOfCols = numOfCols;
            matrix = new T*[numOfLines];
            for(int i=0; i < numOfLines; ++i) matrix[i] = new T[numOfCols];
        }
        Matrix(){};
    
    
    
};
