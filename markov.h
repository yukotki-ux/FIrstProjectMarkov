#ifndef MARKOV_H
#define MARKOV_H
#include <string>

#endif

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
