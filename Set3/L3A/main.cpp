#include <fstream>
#include <iostream>
using namespace std;

int main() {
  // declare ifstream object and open the file
  ifstream encryptedFileStream("secretMessage.txt");
  ofstream decryptedFileStream("decipheredMessage.txt");

  // check for an error
  if (encryptedFileStream.fail()) {
    cerr << "Error opening input file";
    return -1;
  }
  // check for an error
  if (decryptedFileStream.fail()) {
    cerr << "Error opening output file";
    return -1;
  }

  string line;
  while (!encryptedFileStream.eof()) {
    encryptedFileStream >> line; // get the line
    for (char c : line) {        // for each character c in the line:
      switch (c) {
      case '~':                     // if c is a tilde
        decryptedFileStream << ' '; // write a space
        break;
      default:                                // else
        decryptedFileStream << (char)(c + 1); // write the char incremented by 1
        // so glad this worked on my japanese locale system
        break;
      }
    }
    decryptedFileStream << endl; // write the end of the line
  }

  // close the files
  encryptedFileStream.close();
  decryptedFileStream.close();
  return 0;
}