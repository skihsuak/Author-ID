#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

string normalize(string s);
void removeCharsFromString(string &str, char* charsToRemove);
void replaceAll(string &str, string& from, string& to);

//int main(int argc, const char * argv[])
//{
//   map<string, double> austenHash;
//   map<string, double> dickensHash;
//   vector<string> austenWords;
//   vector<double> austenProbs;
//   vector<string> dickensWords;
//   vector<double> dickensProbs;
//
//   fstream austen("austenTable.txt");
//   fstream dickens("dickensTable.txt");
//
//   int counter = 0;
//   int numWordsAusten = 0;
//   string value;
//   while(austen.good())
//   {
//      getline(austen, value, ',');
//      if(counter % 2 == 0)
//      {
//         austenWords.push_back(value);
//      }
//      else
//      {
//         int result;
//         stringstream convert(value);
//         convert >> result;
//         austenProbs.push_back(result);
//         numWordsAusten+=result;
//      }
//      counter++;
//   }
//   for(int i = 0; i < austenProbs.size(); i++)
//   {
//      string word = austenWords[i];
//      austenHash[word]= log(austenProbs[i]/numWordsAusten);
//   }
//
//   counter = 0;
//   int numWordsDickens = 0;
//   while(dickens.good())
//   {
//      getline(dickens, value, ',');
//      if(counter % 2 == 0)
//      {
//         dickensWords.push_back(value);
//      }
//      else
//      {
//         int result;
//         stringstream convert(value);
//         convert >> result;
//         dickensProbs.push_back(result);
//         numWordsDickens+=result;
//      }
//      counter++;
//   }
//   for(int i = 0; i < dickensProbs.size(); i++)
//   {
//      string word = dickensWords[i];
//      dickensHash[word]= log(dickensProbs[i]/numWordsDickens);
//   }
//
//   cout << "Welcome to tester" << endl;
//   while(true)
//   {
//      cout << "Enter a sentence: " << endl;
//      string input;
//      getline(cin, input);
//      //input = normalize(input);
//      istringstream iss(input);
//      string word;
//      double austenProb = 0;
//      double dickensProb = 0;
//      while(iss >> word)
//      {
//         if(austenHash.find(word) == austenHash.end())
//         {
//            austenProb += austenHash["<unk>"];
//         }
//         else
//         {
//            austenProb += austenHash[word];
//         }
//         if(dickensHash.find(word) == dickensHash.end())
//         {
//            dickensProb += dickensHash["<unk>"];
//         }
//         else
//         {
//            dickensProb += dickensHash[word];
//         }
//      }
//      if(austenProb > dickensProb)
//      {
//         cout << "Your writing = Austen" << endl;
//      }
//      else
//      {
//         cout << "Your writing = Dickens" << endl;
//      }
//   }
//   return 0;
//}

//----------------------- generating normalized tables -----------------------
//int main()
//{
////   //generate counts
////   //normalize
////   cout << "\'\"\\Aasdk;v123 fbe;ub ai;SJ D:FB U:WEOUFB?" << endl;
////   cout << normalize("\'Aasdk;v123 fbe;ub ai;SJ D:FB U:WEOUFB?") << endl;
//
//   ofstream outputFile("CharlesDickens-TaleofTwoCitiesN.txt");
//   ifstream ifs("CharlesDickens-TaleofTwoCities.txt");
//   string content( (istreambuf_iterator<char>(ifs) ),
//                   (istreambuf_iterator<char>()    ));
//
//   //cout << content << endl
//   outputFile << normalize(content);
//   outputFile.close();
//   return 0;
//}

int main()
{
   map<string, double> austenHash;
   map<string, double> dickensHash;
   map<string, double> finalHash;
   ifstream dickens("DickensCorpus.txt");
   ifstream austen("JaneAustenCorpus.txt");

   ofstream dickensOut("DickensTable.txt");
   ofstream austenOut("AustenTable.txt");


   string word;
   int numDickensWords = 0; //576947
   int numAustenWords = 0; //545533

   while(dickens >> word)
   {
      finalHash[word]++;
      numDickensWords++;
   }
   while(austen >> word)
   {
      finalHash[word]++;
      numAustenWords++;
   }

   cout << "WORDS: " << endl;
   cout <<  "Dickens: " << numDickensWords << endl;
   cout <<  "Austen: " << numAustenWords << endl;

   while(dickens >> word)
   {
      finalHash[word] = 1;
   }
   while(austen >> word)
   {
      finalHash[word] = 1;
   }
   austenHash = finalHash;
   dickensHash = finalHash;

   while(dickens >> word)
   {
      dickensHash[word]++;
   }

   while(austen >> word)
   {
      austenHash[word]++;
   }

   int numUnkDickens = 0;
   int numUnkAusten = 0;


   map<string, double>::iterator iter;

   for(iter = dickensHash.begin(); iter != dickensHash.end(); ++iter)
   {
      if(iter->second == 2)
      {
         numUnkDickens++;
         dickensHash.erase(iter);
      }
   }
   dickensHash["<unk>"] = numUnkDickens;


   for(iter = austenHash.begin(); iter != austenHash.end(); ++iter)
   {
      if(iter->second == 2)
      {
         numUnkAusten++;
         austenHash.erase(iter);
      }
   }
   austenHash["<unk>"] = numUnkAusten;

   cout << "UNK" << endl;
   cout << "Dickens: " << numUnkDickens << endl;
   cout << "Austen: " << numUnkAusten << endl;

   for(iter = dickensHash.begin(); iter != dickensHash.end(); ++iter)
   {
      iter->second = log(iter->second/numDickensWords);
   }
   for(iter = austenHash.begin(); iter != austenHash.end(); ++iter)
   {
      iter->second = log(iter->second/numAustenWords);
   }

   for(iter = dickensHash.begin(); iter != dickensHash.end(); ++iter)
   {
      dickensOut << iter->first << "," << iter->second << ",";
   }
   for(iter = austenHash.begin(); iter != austenHash.end(); ++iter)
   {
      austenOut << iter->first << "," << iter->second << ",";
   }
   return 0;
}


string normalize(string sInput)
{
   string s = sInput;
   for(int i = 0; i < sInput.size(); i++)
   {
      s[i] = tolower(sInput[i]);
   }
   char chars[] = "*[,_()]”“-\'\"0123456789";
   removeCharsFromString(s, chars);
   string s1 = "\n";
   string s2 = " </s>\n<s> ";
   string s3 = " <abvr>";
   string s4 = " ";
   //replaceAll(s, s1, s4);
   s1 = "?";
   replaceAll(s, s1, s2);
   s1 = "!";
   replaceAll(s, s1, s2);
   s1 = ";";
   replaceAll(s, s1, s2);
   s1 = ":";
   replaceAll(s, s1, s2);
   s1 = " mrs.";
   replaceAll(s, s1, s3);
   s1 = " mr.";
   replaceAll(s, s1, s3);
   s1 = " dr.";
   replaceAll(s, s1, s3);
   s1 = " ms.";
   replaceAll(s, s1, s3);
   s1 = ".";
   replaceAll(s, s1, s2);
   s1 = " chapter ";
   replaceAll(s, s1, s2);
   removeCharsFromString(s, "\231");
   s.insert(0, "<s> ");
   return s;
}

void removeCharsFromString(string &str, char* charsToRemove)
{
   for ( int i = 0; i < strlen(charsToRemove); i++ )
   {
      str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
   }
}

void replaceAll(string &str, string& from, string& to)
{
   size_t start_pos = 0;
   while((start_pos = str.find(from, start_pos)) != std::string::npos)
   {
      str.replace(start_pos, from.length(), to);
      start_pos += to.length();
   }
}





