#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void grepFunction(string searchVariable, string fileName, bool (occurances), bool (reversed), bool (lines), bool (casing)){
   if (casing){
        transform(searchVariable.begin(), searchVariable.end(), searchVariable.begin(), ::tolower);
    }    
    fstream readME;
    unsigned int lineCounter = 0;
    unsigned int count = 0;
    string line;
    readME.open(fileName);
    if(!readME){
        cout << "An exception occurred. Exception Nr. -1" << endl;
        cout << "Could not find out the size of file: " << fileName << endl;
        exit;
    }
    else{
         while (getline(readME, line)) {
            lineCounter++;
            if (reversed == true) {
                if (line.find(searchVariable) == string::npos && lines == true ) {
                    cout << lineCounter << ": " << line << endl;
                    count++;
                }
                else if(line.find(searchVariable) == string::npos){
                    cout << line << endl;
                    count++;
                }
            }

            if (reversed == false) {
                if (line.find(searchVariable) != string::npos) {

                    if (lines == true) {
                        cout << lineCounter << ": " << line << endl;
                        count++;
                    }
                    else {
                        cout << line << endl;
                        count++;
                    }
                }
            }
        }
        if (occurances == true) {
            cout << "Number of occurences of " << searchVariable << ": " << count << endl;
        }
    } 
};
void basicFunction(string searchVariable){
    transform(searchVariable.begin(), searchVariable.end(), searchVariable.begin(), ::tolower);
    fstream readME;
    readME.open("man_grep_plain_ASCII.txt");
    unsigned int lineCounter = 0;
    string line;
    if (!readME){
        cout << "File could not be opened " << endl;
        exit;
    }
        else{
            while (getline(readME, line)){
                if (line.find(searchVariable, 0) != string::npos){
                cout << line  << endl;
                }
            }
        }
};
void stringCatcher(string input, string search){
    size_t found = input.find(search);
    if(found != string::npos){
    cout << search << " FOUND in " << input << endl;
    }
    else{
    cout << search << " NOT found in " << input << endl;
    }
};
int main(int argc, const char** argv){
    string searchVariable;
    string fileName;
    bool occurances{},reversed{},casing{},lines{};
    string commands;
    if(argc > 1){  
      unsigned short iCount= 0, oCount=0, lCount = 0, rCount = 0, olCount = 0;
      for(unsigned short i = 0; i < argc; i++){

            commands = argv[1];
           if (commands[0] == '-' && commands[1] == 'o'){
               olCount++;
           } 
           if (olCount == 0){
                   cout << "set options with -o" << endl;
                   break;
            }
           if (commands[2] == 'o' || commands[3] == 'o' || commands[4] == 'o'){
               oCount++;
               occurances=true;  
           }
           if (commands[2] == 'i' || commands[3] == 'i' || commands[4] == 'i'){
               iCount++;
               casing=true; 
           }
           if(commands[2] == 'r' || commands[3] == 'r' || commands[4] == 'r'){
               rCount++;
               reversed=true;
           }
           if(commands[2] == 'l' || commands[3] == 'l'|| commands[4] == 'l'){
               lCount++;
               lines=true;
           }
            grepFunction(argv[2], argv[3], bool (occurances), bool (reversed), bool (lines), bool (casing));
           break;
      }
       return 0;
    }
    string input, search;
    cout << "Give me a string from which to search for: ";
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    cout << "Give search string: ";
    getline(cin, search);
    transform(search.begin(), search.end(), search.begin(), ::tolower);
    stringCatcher(input, search);
    cout << "Give line for search variable:";
    transform(searchVariable.begin(),searchVariable.end(),searchVariable.begin(), ::tolower);
    getline(cin, searchVariable);
    basicFunction(searchVariable);
    return 0;
}   