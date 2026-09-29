#include "markov.h"
#include <fstream>
#include <cstdlib> 
#include <string>

std::string joinWords(const std::string words[], int startIndex, int count){

    std::string result = "";

    for (int i = 0; i < count; i++){
        result += words[startIndex + i];
        if(i < count - 1){
            result += " ";
        }
    }
    return result;
}

int readWordsFromFile(std::string filename, std::string words[], int maxWords){
    std::ifstream inputFile(filename);
    if(!inputFile.is_open()){
        return -1;
    }
    int counter = 0;
    while (counter < maxWords && inputFile >> words[counter]){
        counter += 1;
    }
    inputFile.close();
    return counter;

}

int buildMarkovChain(const std::string words[], int numWords, int order,
                     std::string prefixes[], std::string suffixes[],
                     int maxChainSize){
                        //Return 0 immediately if order is outside 1–3, numWords <= order, or maxChainSize <= 0. Otherwise set count to 0.
                    if(order < 1|| order > 3 || numWords <= order || maxChainSize <= 0){
                        return 0;
                    }
                    int count = 0;
                    int i = 0;
                    while (i < numWords - order && count < maxChainSize){
                        std::string prefix = joinWords(words, i, order);
                        std::string suffix = words[i + order];
                        prefixes[count] = prefix;
                        suffixes[count] = suffix;
                        count += 1;
                        i++;
                        }
                    return count;
                    }

std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],
                            int chainSize, std::string currentPrefix){
                            int matchCount = 0;
                            for(int i = 0; i < chainSize; i++){
                                if (prefixes[i] == currentPrefix){//check if this prefix is the one I'm looking for
                                    matchCount += 1;
                                }}
                            if (matchCount == 0 || chainSize <= 0){
                                    return "";
                            }
                            int pick = rand() % matchCount;
                            int currentMatch = 0;
                            for(int i = 0; i < chainSize; i++){
                                if (prefixes[i] == currentPrefix){
                                    if(currentMatch == pick){
                                        return suffixes[i];
                                    }
                                currentMatch += 1;
                                }}
                            return "";
                            }
                        
std::string getRandomPrefix(const std::string prefixes[], int chainSize){
    if(chainSize <= 0){//Check for an empty chain before taking a remainder or indexing the array.
        return "";
    }
    int index = rand() % chainSize;
    return prefixes[index];
}

std::string generateText(const std::string prefixes[], const std::string suffixes[],
                         int chainSize, int order, int numWords){
                        if(order < 1|| order > 3 || numWords < order || chainSize <= 0){
                            return "";
                         }
                         std::string currentPrefix = getRandomPrefix(prefixes, chainSize);

                         std::string result = currentPrefix;
                         std::string currentWords[3]; // supports the validated orders 1, 2, and 3
                            int wordIndex = 0;                                                                                                                                                                 
                            std::string temp = "";
                            for(int i = 0; i < chainSize; i++) {                                                                                                                                 
                                if (currentPrefix[i] == ' ') {                                                                                                                                                 
                                    currentWords[wordIndex] = temp;                                                                                                                                            
                                    wordIndex++;                                                                                                                                                               
                                    temp = "";                 
                                } else {                                                                                                                                                                       
                                    temp += currentPrefix[i];  
                                }
                            }
                            currentWords[wordIndex] = temp; // don't forget the last word
                            for(int i = 0; i < numWords - order; i++){
                                std::string newWord = getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix);
                                if(newWord == ""){
                                    break;
                                }
                                result += " " + newWord;
                            
                            for(int j = 0; j < order - 1; j++){
                                currentWords[j] = currentWords[j + 1];                                                                                              
                            }
                            currentWords[order - 1] = newWord;
                            currentPrefix = joinWords(currentWords, 0, order);
                            }
                            return result;
                         }
