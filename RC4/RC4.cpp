#include "source.h"


int main() {
    std::string key;
    std::string plain;
    std::string input = "Data.txt";
    std::string resultFile = "Result.txt";

    if ( !readData(input, key, plain) ) return 1;
    std::vector<unsigned char> ciphertext( plain.length() );
    RC4( key, plain, ciphertext );  
    printResult( ciphertext );
    if ( !saveToFile( resultFile, ciphertext )) return 2;
}