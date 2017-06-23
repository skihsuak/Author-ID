//
//  main.cpp
//  author_ID
//
//  Created by Leon Pham on 6/17/17.
//  Copyright © 2017 Leon Pham. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

string get_file(){
    string fileName = "";
    cout << "Please enter a filename followed by .txt: ";
    cin >> fileName;
    
    return fileName;
}

bool validChar(char &a){
    
    if ('z' >= a && a >= 'a')
        return true;
    if ( '9' >= a && a >= '0')
        return true;
    if (a == '\'' )
        return true;
    return false;
}

bool hasAnyDigits(const string& s)
{
    return any_of(s.begin(), s.end(), ::isdigit);
}

int main(int argc, const char * argv[]) {
    
    vector<string> vectString;
    vector<char> charVect;
    vector<string>::iterator iter = vectString.begin();
    
    string word, readfile, catWord;
    readfile = get_file();
    
    ifstream myfile(readfile);
    ofstream outfile ("cat.txt");
    
    while(!myfile.eof()){
        
        myfile >> word;
        
        for (int j=0; j< word.length(); ++j)
        {
            word[j] = tolower(word[j]);
            if(validChar(word[j])){
                charVect.push_back(word[j]);
                catWord += charVect[j];
            }
        }
        charVect.clear();
        
        vectString.push_back(catWord);
        
        
        catWord = "";
        word = "";
    }
    
    for ( int i = 0; i < vectString.size(); i++){
        if (vectString[i] != "chapter"){
            if(hasAnyDigits(vectString[i])){
                outfile << "<number>" << vectString[i] << "</number> ";
            }
            outfile << vectString[i] << " ";
        }
    }
    
    myfile.close();
    outfile.close();
    
    return 0;
}




