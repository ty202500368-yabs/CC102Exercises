#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ofstream outFile("original.txt");

    if (!outFile) {
        cout << "Error: Unable to create original.txt" << endl;
        return 1;
    }

    outFile << "One" << endl;
    outFile << "Two" << endl;
    outFile << "Three" << endl;
    outFile << "Four" << endl;
    outFile << "Five" << endl;
    outFile << "Six" << endl;

    outFile.close();

    ifstream inFile("original.txt");

    if (!inFile) {
        cout << "Error: Unable to open original.txt" << endl;
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inFile, line)) {
        words.push_back(line);
    }

    inFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");

    if (!sortedFile) {
        cout << "Error: Unable to create sorted.txt" << endl;
        return 1;
    }

    for (string word : words) {
        sortedFile << word << endl;
    }

    sortedFile.close();

    cout << "Text sorted successfully and saved to sorted.txt" << endl;

    return 0;
}