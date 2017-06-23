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

int main()
{
//   //generate counts
//   //normalize
//   cout << "\'\"\\Aasdk;v123 fbe;ub ai;SJ D:FB U:WEOUFB?" << endl;
//   cout << normalize("\'Aasdk;v123 fbe;ub ai;SJ D:FB U:WEOUFB?") << endl;

   ifstream ifs("JaneAusten-PrideandPrejudice.txt");
   string content( (istreambuf_iterator<char>(ifs) ),
                   (istreambuf_iterator<char>()    ));
   cout << normalize(content) << endl;
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
   replaceAll(s, s1, s4);
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




