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
    const string quote = "\"";
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
         if ((reversed) && (occurances)){
            cout << endl << "Occurrences of lines NOT containing  " << quote + searchVariable + quote << ": " << count << endl;
        }
        if ((occurances == true) && (reversed == false)){
            cout << endl << "Number of occurences of " << quote + searchVariable + quote << ": " << count << endl;
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
    bool occurances{},reversed{},casing{},lines{},options{};
    string commands;
    unsigned short iCount= 0, oCount=0, lCount = 0, rCount = 0, olCount = 0;
   
   if (argc == 2){
       cout << "You've entered too little arguments" << endl;
       return 0;
   }

    if(argc >1){  
      for(int i = 0; i < argc; i++){     
            commands = argv[1];
             if (argc == 3){
                grepFunction( argv[1], argv[2], bool (occurances), bool (reversed), bool (lines), bool (casing));
                break;
            }
            if ((commands[6]) && (argc == 4)){
                cout << endl << "You have entered too many arguments! There are only 4 options in total i,o,r,l " << endl;
                break;
            }
           if ((commands[0] == '-') && (argc == 4)){
              olCount++;
              options = true;
           } 
           if ((commands[0] != '-') && (argc == 4)) {
               cout << endl << "Set options with -o" << endl;
               options = false;
               break;
           }
           if ((commands[1] != 'o') && (argc == 4)){
                options = false;
                cout << "Set options with -o" << endl;
                break;
            }
           if (commands[2] == 'o' || commands[3] == 'o' || commands[4] == 'o' || commands[5] == 'o'){  
               oCount++; 
               occurances=true; 
           }
 
           if (commands[2] == 'i' || commands[3] == 'i' || commands[4] == 'i'|| commands[5] == 'i'){   
               iCount++;
               casing=true; 
           }

           if(commands[2] == 'r' || commands[3] == 'r' || commands[4] == 'r' || commands[5] == 'r'){ 
               rCount++;
               reversed=true;
           }
 
           if(commands[2] == 'l' || commands[3] == 'l'|| commands[4] == 'l' || commands[5] == 'l'){
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
    return 0;
}   