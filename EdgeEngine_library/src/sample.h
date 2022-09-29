/*
  sample.h - Class for model sample.
  Created by Francesco Tornatore, February 24, 2020.
  Released into the public domain.
*/

#ifndef sample_h
#define sample_h
#include <array>
#include <string>
#include <vector>

#include <iostream>
#include <sstream>

using std::array;
using std::string;
using std::stringstream;
using std::vector;



class sample{
  private:
  //variables
  
  public:
  //variables
  
  vector<float> myArray;
  string startDate;
  string endDate;
  string url;
  string thing;
  string feature;
  string device;
  string scriptId;
  // JSON formatted string to be used in the request body
  string sampleString;
  int sizeOfSamples;
 
  //methods 
  // method to format the single sample in JSON, if you need to send multiple samples at a time, use the queue script
  void ArrayToString(vector<float> myArray);
 
  //constructors
  sample(string);
  sample(const sample&);
  
};

#endif 
