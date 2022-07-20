/*
* Author: Tim Klimpel
* Assignment Title: Huffman Coding
* Assignment Description: Implementing Huffman encoding.  Both Encoding and Decoding are to be
  completed and called using the -huff and -unhuff flag at runtime
* Due Date: 2022/08/01
* Date Created: 2022/07/20
* Date Last Modified: 2022/07/20
*/

/*
* Input:
* Process:
* Output:
* Assumptions:
*/

/*Resources*/
 
/*includes*/
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <queue>
#include <unordered_map>

/*Namespaces*/
using namespace std;

/*Constants*/

/*Struct*/
struct Node{
  char character;
  int freq;
  Node *left, *right;
};

/*Classes*/

/*Function Declerations*/

/*
* Description: 
* return: 
* precondition: 
* postcondition: 
*/
Node* getNode();

/*************
* MAIN START *
*************/
int main(int argc, char *argv[])
{
  ifstream inFile;
  ofstream outFile;
  //string flag = argv[1];
  string inputFile = argv[1]; //#TODO need to update or remove hardcoding when done testing #TODO
  //string outputFile = argv[2];
  cout << endl << "Input file location: " << inputFile << "\n\n";

  string textIn;
  int charCount = 0;
  char testChar = '\xff'; //hex for 1111 or 32 ?? STILL IN PROGRESS TESTING

  inFile.open(inputFile, ifstream::binary); //path must be relative to .exe file location

  textIn += inFile.get(); charCount++;

  while(inFile.good()){
    //cout << inChar;
    cout << charCount << " ";
    textIn += inFile.get(); charCount++; //I get different counts with each "return" used in the .txt file (+2 for each return)
  }

  cout << "\n\n" << textIn;

  return 0;
}
/*************
* MAIN END   *
*************/

/*Function definitions*/
Node* getNode(){
  Node* nodePtr;

  nodePtr->character = 'c';
  nodePtr->freq = 10;
  nodePtr->left = nullptr;
  nodePtr->right = nullptr;

  return nodePtr;
}