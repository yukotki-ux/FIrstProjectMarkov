#include <iostream>
#include "markov.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));

    const int MAX_WORDS = 5000;
    const int MAX_PREFIXES = 5000;
    const int MAX_SUFFIXES = 5000;

    string words[MAX_WORDS];
    string prefixes[MAX_PREFIXES];
    string suffixes[MAX_SUFFIXES];

    string filename;
    int order;
    int maxWords;

    cout << "Please type filename, order, and maximum number or words." <<endl;
    cout <<"filename: ";
    cin >> filename;
    cout <<"order: ";
    while(!(cin >> order)||order < 1||order > 3){
        cout << "Order must be 1 to 3. Please enter again." <<endl;
        cin.clear(); //clear error
        cin.ignore(1000, '\n'); //delete error history
    }
    cout <<"maximum number of words: ";
    while(!(cin >> maxWords)||maxWords < order){
        cout << "It is not valid number. Please enter again.";
        cin.clear(); //clear error
        cin.ignore(1000, '\n'); //delete error history
    }
    // Use a named capacity, for example const int MAX_WORDS = 5000; declare words, prefixes, and suffixes with that capacity. Pass the actual capacity to the functions. This project may train on only the first 5000 words of a larger file.
    // Read the file. Explain a -1 result as a file-open failure. 

int count = readWordsFromFile(filename, words, MAX_WORDS);
if(count == -1){
    cout << "A file cannot be opened." << endl;

// If the count is <= order, explain that at least order + 1 training words are needed.
} else if (count <= order){
    cout << "At least " << order + 1 << " training words are needed." << endl;
} else {
// Build the chain and confirm chainSize > 0 before random selection.
int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, MAX_PREFIXES);
if(chainSize <= 0){
    cout << "It can not work." << endl;
} else {
// If the input array filled to capacity, tell the user that at most MAX_WORDS input words were used and additional words, if any, were ignored.
    if(count == MAX_WORDS){
        cout << "At most " << MAX_WORDS << " input words were used and additional words, if any, were ignored." << endl;
    }
    string output = generateText(prefixes, suffixes, chainSize, order, maxWords);
    cout << output << endl;

    int outputCount = 0;
    if (output != "") {
        outputCount = 1;

    for (int i = 0; i < static_cast<int>(output.length()); i++) {
        if (output[i] == ' ') {
            outputCount++;
        }
    }
}
cout << outputCount << " words" << endl;
// If it is shorter than requested, explain that generation stopped at a dead end.
if (outputCount < maxWords) {
    cout << "Generation stopped at a dead end." << endl;
}}}
return 0;
}