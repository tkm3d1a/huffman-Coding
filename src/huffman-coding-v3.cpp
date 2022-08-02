/*
* Author: Tim Klimpel
* Assignment Title: Huffman Coding
* Assignment Description: Implementing Huffman encoding.  Both Encoding and Decoding are to be
  completed and called using the -huff and -unhuff flag at runtime
* Due Date: 2022/08/01
* Date Created: 2022/07/20
* Date Last Modified: 2022/07/24
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
#include "Huffman.hpp"

/*Namespaces*/


/*Constants*/
/*Struct*/
/*Classes*/
/*Function Declerations*/
/*
* Description:
* return:
* precondition:
* postcondition:
*/

/*************
* MAIN START *
*************/

int main(int argc, char *argv[])
{
  if (argc != 4) {
    std::cout << "Not enough arguments.  Please run the executable with the following arguments:\n\n" << 
      "<flag> <source> <destination>\n\n" <<
      "Exiting program...\n";
    return 1;
  }

  std::string flag = argv[1];
  std::string inFile = argv[2];
  std::string outFile = argv[3];
  Huffman fileForWork(flag, inFile, outFile);

  if (flag == "-huff") {
    fileForWork.doEncode();
  }
  else if (flag == "-unhuff") {
    fileForWork.doDecode();
  }
  else {
    std::cout << "**ERROR**\n" << 
      "Invalid flag input -> " << flag << "\n" << 
      "Acceptable flag options: \'-huff\' or \'-unhuff\'\n\n";
  }
  /* Huffman Constructor reminder
    Huffman(std::string f, std::string ifName, std::string ofName) {
      this->inFileName = ifName;
      this->outFileName = ofName;
      this->flag = f;
    }
   */

  //Huffman encodeTest(doflag, inFile, outFile);
  //encodeTest.doEncode();

  //std::string unflag = "-unhuff";
  ////unhuff flag stopped working for some reason...
  //Huffman encodeTest2(unflag, outFile, testRun);
  //encodeTest2.doDecode();

  return 0;


}

/*************
* MAIN END   *
*************/

/*Function definitions*/