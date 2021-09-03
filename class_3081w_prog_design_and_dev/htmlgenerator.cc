#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeHTMLFile(ostream& outStream, string innerHTML) {
   outStream << "<!DOCTYPE html>" << endl;
   outStream << "<html>" << endl;
   outStream << "  <body>" << endl;
   outStream << "    <p>" << innerHTML << "</p>" << endl;
   outStream << "  </body>" << endl;
   outStream << "</html>" << endl;
}

int main() {
   string htmlParagraph = "Hello <b>HTML</b> world!";
  
   // Open an output file stream
   ofstream outFS;
   outFS.open("simple.html");
  
   if (!outFS.is_open()) {
      cout << "Could not open file simple.html." << endl;
      return 1;
   }
  
   // Write to, and then close, file
   writeHTMLFile(outFS, htmlParagraph);
   outFS.close();
 
   // Use the same function, writeHTMLFile, to write to cout
   writeHTMLFile(cout, htmlParagraph);
   return 0;
}
