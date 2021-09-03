### setw() and setfill()
```
int main() {
   // Dog age in human years (dogyears.com)   
   cout << setw(10) << left  << "Dog age" << "|";
   cout << setw(12) << right << "Human age" << endl;
   
   // Produce long line   
   cout << setfill('-') << setw(23) << "" << endl;
   
   // Reset fill character back to space
   cout << setfill(' ');

   cout << setw(10) << left  << "2 months" << "|";
   cout << setw(12) << right << "14 months" << endl;
   cout << setw(10) << left  << "6 months" << "|";
   cout << setw(12) << right << "5 years" << endl;   
   cout << setw(10) << left  << "8 months" << "|";
   cout << setw(12) << right << "9 years" << endl;
   cout << setw(10) << left  << "1 year" << "|";
   cout << setw(12) << right << "15 years" << endl;

   // Produce long line
   cout << setfill('-') << setw(23) << "" << endl;
   
   return 0;
}
```
This code will output
```
 Dog age  | Human age
-----------------------
2 months  |  14 months
6 months  |    5 years
8 months  |    9 years
1 year    |   15 years
-----------------------
```
condensed, this looks like  
```
int main() {
   cout << setw(10) << left  << "Dog age" << "|" << setw(12) << right << "Human age" << endl;   // Dog age  | Human age
   cout << setfill('-') << setw(23) << "" << endl;                                              // -----------------------
   cout << setfill(' ');
   cout << setw(10) << left  << "2 months" << "|" << setw(12) << right << "14 months" << endl;  // 2 months  |  14 months
   cout << setw(10) << left  << "6 months" << "|" << setw(12) << right << "5 years" << endl;    // 6 months  |    5 years
   cout << setw(10) << left  << "8 months" << "|" << setw(12) << right << "9 years" << endl;    // 8 months  |    9 years
   cout << setw(10) << left  << "1 year" << "|" << setw(12) << right << "15 years" << endl;     // 1 year    |   15 years
   cout << setfill('-') << setw(23) << "" << endl;                                              // -----------------------
   
   return 0;
}
```
