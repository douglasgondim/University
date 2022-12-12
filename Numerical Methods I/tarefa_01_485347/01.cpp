// José Douglas Gondim Soares, 485347

#include <iostream>
#include <math.h> 
using namespace std;

string decimalToBinary(int num){
    string binaryNum = "";
    while(num != 0){
        binaryNum = to_string( num % 2) + binaryNum;
        num /= 2;
    }
    return binaryNum;
}

int binaryToDecimal(string binaryNum){
    int decimalNum = 0, binaryNumLength = binaryNum.length();
    for(int i=0; i < binaryNumLength; ++i){
        decimalNum += (binaryNum[i] - '0') * pow(2, binaryNumLength-1-i);
    }
    return decimalNum;
}

int main(){
    int d = 27;
    string b = decimalToBinary(d);
    cout << d << " in Binary is: " << b << endl;
    cout << b << " in Decimal is: " << binaryToDecimal(b) << endl;
    return 10;
}