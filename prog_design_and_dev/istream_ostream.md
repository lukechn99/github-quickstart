```
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
   istringstream inSS;      // Input string stream
   string lineString;       // Holds input string
   string data;
    
   cout << "Enter a list of names separated by spaces: ";
 
   // Entire line into lineString
   getline(cin, lineString);
   inSS.str(lineString);
 
   while (inSS >> data) {    
      cout << data << endl;
   }
 
   return 0;
}
```

We create a 
Open the file helloWorld.txt for writing ```ofstream outFS;```
```outFS.open("helloWorld.txt");```
Check to see if the file opened successfully	
```if (!outFS.is_open()) {
   // Do not proceed to code that writes to the file
}
```
Write the string "Hello World!" to the file	
```outFS << "Hello World!" << endl;```
Close the file after writing all desired data	
```outFS.close();```
