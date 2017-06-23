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

using namespace std;

string get_file(){
    string fileName = "";
    cout << "Please enter a filename followed by .txt: ";
    cin >> fileName;
    
    return fileName;
}

bool validChar(char a){
    
    return;
}


int main(int argc, const char * argv[]) {
    
    string line, readfile = "";
    readfile = get_file();
    
    ifstream myfile(readfile);
    ofstream outfile ("output.txt");
    string punctuation = "!,;:?-*";
    
    while(!myfile.eof()){
        myfile >> line;
        size_t n = 0;
        for (size_t j=0; j< line.length(); ++j)
        {
            line[j] = tolower(line[j]);
        }
        
        while((n = line.find_first_of(punctuation, n)) != string::npos)
            line.erase(n, 1);
        
        outfile  <<line << " ";
        
    }

    myfile.close();
    outfile.close();
    return 0;
}




