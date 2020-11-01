#include "source.h"

void printResult(std::vector<unsigned char>& ciphertext) {
    for( auto& i : ciphertext )
        printf("%x", i);
    printf("\n");
}

void tabInit(std::array<unsigned char, SIZE>& S) {
    for( int i = 0; i < SIZE; ++i )
        S[i] = i;
}

void keyInit(std::string& key, std::array<unsigned char, SIZE>& S) {
    int len = key.length();
    int j = 0;

    for( int i = 0; i < SIZE; ++i ) {
        j = ( j + S[i] + key[i % len] ) % SIZE;
        std::swap(S[i], S[j]);
    }
}

void pseudoRandom(std::array<unsigned char, SIZE>& S, std::string& plaintext, std::vector<unsigned char>& ciphertext) {
    int i = 0;
    int j = 0;
    int len = plaintext.length();
    for( int n = 0; n < len; ++n ) {
        i = ( i + 1 ) % SIZE;
        j = ( j + S[i] ) % SIZE;
        std::swap(S[i], S[j]);
        unsigned char rand = S[( S[i] + S[j] ) % SIZE];
        ciphertext[n] = rand ^ plaintext[n]; //XOR
    }
}

void RC4(std::string& key, std::string& plaintext, std::vector<unsigned char>& ciphertext) {
    std::array<unsigned char, SIZE> S;
    tabInit(S);
    keyInit(key, S);
    pseudoRandom(S, plaintext, ciphertext);
}

int readData(std::string& input, std::string& toFile_Key, std::string& toFile_Plain) {
    std::ifstream myFile(input);
    if( !myFile.is_open() ) {
        std::cerr << "The file is not open!" << '\n';
        return 0;
    }

    std::getline(myFile, toFile_Key);
    std::getline(myFile, toFile_Plain);
    return toFile_Key.length() + toFile_Plain.length(); // returning number of all characters reaf to files
}

int saveToFile(std::string& name, std::vector<unsigned char>& result) {
    std::ofstream myFile(name);
    if( !myFile.is_open() ) {
        std::cerr << "The file is open!" << '\n';
        return 0;
    }
    for(int i = 0; i < result.size(); ++i )
        myFile << std::hex<<(int)result[i];
    return result.size();// returning number of all characters saved to file
}