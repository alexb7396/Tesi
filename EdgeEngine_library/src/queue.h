#ifndef queue_h
#define queue_h
#include <string>
#include "operation.h"
#include <array>
#include <iostream>
#include <vector>
#include <sstream>

using std::array;
using std::string;
using std::stringstream;
using std::vector;

class queue : public operation{
  private:
  //variable
  int numOfSamples;
  int counter;
  string myString;
  // ssample* newSample;
  
    public:
  //constructors
  queue(string);
  //destructor
   ~queue();
  
  //methods
  sample* execute();
  void parseNumOfSamples(string);
};
#endif 