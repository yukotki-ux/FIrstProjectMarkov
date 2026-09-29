#include <iostream>
#include "markov.h"
#include <string>
#include <cstdlib>
#include <ctime>

// using namespace std;

int main(){
    srand(time(0));
    std::string testWords[] = {"the", "cat", "sat", "down"};
std::cout << joinWords(testWords, 0, 2) << std::endl;  // Should print: the cat
std::cout << joinWords(testWords, 1, 3) << std::endl;  // Should print: cat sat down

std::string words[1000];
int count = readWordsFromFile("test.txt", words, 1000);
std::cout << "Read " << count << " words" << std::endl;
for (int i = 0; i < 10 && i < count; i++) {
    std::cout << words[i] << std::endl;
}

std::string prefixes[1000], suffixes[1000];
int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 1000);
for (int i = 0; i < 20 && i < chainSize; i++) {
    std::cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
}

for (int i = 0; i < 10; i++) {
    std::cout << getRandomSuffix(prefixes, suffixes, chainSize, "the") << std::endl;
}

//     cout << "Please type filename, order, and maximum number or words." <<endl;
//     cout <<"filename: ";
//     cin >> filename >>endl;
//     cout <<"order: ";
//     cin >> order >>endl;
//     if(!(cin>>order)||order<1||order>3||){
//         cout << "It is not valid number. Please enter again.";
//         cin >> order >>endl;
//     }
//     cout <<"maximum number of words: ";
//     cin >> maxWords >>endl;
//     if(!(cin >> maxWords)||maxWords < order){
//         cout << "It is not valid number. Please enter again.";
//         cin >> maxWords >>endl;
//     }
// const int MAX_WORDS = 5000;
// const int MAX_PREFIXES = 5000;
// const int MAX_SUFFIXES = 5000;
//     // Use a named capacity, for example const int MAX_WORDS = 5000; declare words, prefixes, and suffixes with that capacity. Pass the actual capacity to the functions. This project may train on only the first 5000 words of a larger file.
//     // Read the file. Explain a -1 result as a file-open failure. 
// int readWordsFromFile(filename, words[], maxWords);
// if(readWordsFromFile() = -1){
//     cout << "file-open is failed." <<endl;
// }
   
// std::string joinWords(const std::string words[], int startIndex, int count);

// int buildMarkovChain(const std::string words[], int numWords, int order,
//                      std::string prefixes[], std::string suffixes[],
//                      int maxChainSize);

// std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],
//                             int chainSize, std::string currentPrefix);

// std::string getRandomPrefix(const std::string prefixes[], int chainSize);

// std::string generateText(const std::string prefixes[], const std::string suffixes[],
//                          int chainSize, int order, int numWords);



return 0;
}