#include <bits/stdc++.h> 
using namespace std; 
  
// Prints frequencies of individual words in str 
void printFrequenciesOfWords(const string &str) 
{ 
    // declaring map of <string, int> type, each word 
    // is mapped to its frequency 
    unordered_map<string, int> wordFreq; 
  
    // breaking input into word using string stream 
    stringstream ss(str);  // Used for breaking words 
    string word; // To store individual words 
    while (ss >> word) 
        wordFreq[word]++; 
  
    // now iterating over word, freq pair and printing 
    // them in <, > format 
    unordered_map<string, int>:: iterator p; 
    for (p = wordFreq.begin(); p != wordFreq.end(); p++) 
        cout << "(" << p->first << ", " << p->second << ")\n"; 
} 

void printFrequenciesOfChars(const string &str) 
{ 
    // declaring map of <string, int> type, each word 
    // is mapped to its frequency 
    unordered_map<char, int> chars; 
  
    // breaking input into word using string stream 
    for(int x=0;x<str.size();x ++ ){
		char s=str[x];
        chars[s]+=1; // chars[s] adds entry to map
	}
  
    // now iterating over word, freq pair and printing 
    // them in <, > format 
     
    for (auto p = chars.begin(); p != chars.end(); p++) 
        cout << "(" << p->first << ", " << p->second << ")\n"; 
} 
// Driver code 
int main() 
{ 
    string str = "geeks for geeks geeks quiz "
                 "practice qa for"; 
    printFrequenciesOfWords(str); 
    printFrequenciesOfChars(str); 
    return 0; 
} 