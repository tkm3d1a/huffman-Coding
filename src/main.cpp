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
//Huffman code definition from here: https://gist.github.com/pwxcoo/72d7d3c5c3698371c21e486722f9b34b
 
/*includes*/
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>

/*Namespaces*/
using namespace std;

/*Constants*/

/*Struct*/
struct Node{

  char character;
  int freq;
  Node *left, *right;

};

struct compareOR{

  bool operator()(Node* left, Node* right){
    return left->freq > right->freq;
  }

};

/*Classes*/

/*Function Declerations*/

/*
* Description: 
* return: 
* precondition: 
* postcondition: 
*/
Node* makeNode(char c, int freq, Node* left, Node* right);
void encode(Node* root, string input, unordered_map<char, string> &huffmanCode);
void decode(Node* root, int &index, string output); //will need to modify for my use
void buildTree(string textToCode);


/*************
* MAIN START *
*************/
int main(int argc, char *argv[])
{
  // ifstream inFile;
  // ofstream outFile;
  // //string flag = argv[1];
  // string inputFile = argv[1]; //#TODO need to update or remove hardcoding when done testing #TODO
  // //string outputFile = argv[2];
  // cout << endl << "Input file location: " << inputFile << "\n\n";

  // string textIn;
  // int charCount = 0;
  // char testChar = '\xff'; //hex for 1111 or 32 ?? STILL IN PROGRESS TESTING

  // inFile.open(inputFile, ifstream::binary); //path must be relative to .exe file location

  // textIn += inFile.get(); charCount++;

  // while(inFile.good()){
  //   //cout << inChar;
  //   cout << charCount << " ";
  //   textIn += inFile.get(); charCount++; //I get different counts with each "return" used in the .txt file (+2 for each return)
  // }

  // cout << "\n\n" << textIn;

  // string testStringASCII, testStringChar;

  // for(int i = 0;i<128;i++){
  //   char intToChar = i;
  //   char intToProperChar = '1';
  //   testStringASCII += intToChar;
  //   testStringChar += intToProperChar;
  // }

  // outFile.open("./output.txt");
  // outFile << testStringASCII;
  // outFile.close();

  // outFile.open("./output2.txt");
  // outFile << testStringChar;
  // outFile.close();

  cout << endl;
  buildTree("aabbccddeeeeefffff");

  return 0;
}
/*************
* MAIN END   *
*************/

/*Function definitions*/
Node* makeNode(char c, int freq, Node* left, Node* right){

  Node* nodePtr = new Node();

  nodePtr->character = c;
  nodePtr->freq = freq;
  nodePtr->left = left;
  nodePtr->right = right;

  return nodePtr;

}

void encode(Node* root, string input, unordered_map<char, string> &huffmanCode){
  
  if(root == nullptr){
    return;
  }

  if(root->left == nullptr && root->right == nullptr){
    huffmanCode[root->character] = input;
  }

  encode(root->left, input + "0", huffmanCode);
  encode(root->right, input + "1", huffmanCode);

}

void decode(){

}

void buildTree(string textToCode){

  unordered_map<char, int> freqMap;

  for(int i = 0; i < textToCode.length(); i++){
    freqMap[textToCode[i]]++;
  }

  priority_queue<Node*, vector<Node*>, compareOR> pQueue;

  for(auto pair: freqMap){
    pQueue.push(makeNode(pair.first, pair.second, nullptr, nullptr));
    cout << "Char: " << pair.first << " -- Frequency: " << pair.second << endl;
  }

  while(pQueue.size() > 1){
    Node *leftOne = pQueue.top(); pQueue.pop();
    Node *rightZero = pQueue.top(); pQueue.pop();

    int freqSum = leftOne->freq + rightZero->freq;
    pQueue.push(makeNode('\0', freqSum, leftOne, rightZero));
  }

  Node *root = pQueue.top();

  unordered_map<char, string> huffmanCode;
  encode(root, "", huffmanCode);

  cout << " \nHuffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}
}