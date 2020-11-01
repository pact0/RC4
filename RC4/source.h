#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

#define SIZE 256

void tabInit(std::array<unsigned char, SIZE>& S);
void keyInit(std::string& key, std::array<unsigned char, SIZE>& S);
void pseudoRandom(std::array<unsigned char, SIZE>& S, std::string& plaintext, std::vector<unsigned char>& ciphertext);
void RC4(std::string& key, std::string& plaintext, std::vector<unsigned char>& ciphertext);
void printResult(std::vector<unsigned char>& ciphertext);
int saveToFile(std::string& name, std::vector<unsigned char>& result );
int readData(std::string& input, std::string& toFile_Key, std::string& toFile_Plain);