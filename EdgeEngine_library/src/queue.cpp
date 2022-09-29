#include "queue.h"
#include <stdlib.h>
#include <sstream>
#include "sample.h"
#include <array>
#include <vector>
#include "APIRest.h"

using std::array;
using std::string;
using std::stringstream;
using std::vector;

//constructor
queue::queue(string opName) : operation(opName){
  valid=true;
  // get the numeber of samples 
  parseNumOfSamples( opName.substr( opName.find("(")+1, opName.find(")") - (opName.find("(")+1)));
  counter=0;
  sstream << "[";
}
queue:: ~queue(){
}

sample* queue::execute()
 {
    if( input!=NULL && counter < numOfSamples)
    { 
      // check if the sample it is  monodimensional
      if( input -> myArray.size() == 1){
       sstream << "{ \"values\" : " ;
       sstream <<  input->myArray[0];
       sstream << " }";}
       // else if the sample is multidimensional 
      else
      {
          sstream << "{ \"values\" : [ ";
          // scroll through all the elements of the sample
          for(int i=0; i < input -> myArray.size(); i++ )
          {   
            sstream << (input -> myArray[i]);
              //if is not the last element of the sample add a comma
            if(i < (input-> myArray.size()-1)) { sstream << ", "; }
          }
          sstream << " ] }";
          Serial.println(counter);
        }
        // if is not the last sample add a comma
    if(counter < numOfSamples - 1) { sstream << ", "; }
    counter++;
    }
    // when the samples are finished, create a new sample and return this
    if(input != NULL && counter >= numOfSamples)
    { 
        sstream << " ]"; 
         Serial.print("Total heap:");
   Serial.println( ESP.getHeapSize());
    
   Serial.print("Free heap:");
   Serial.println(ESP.getFreeHeap());
    
   Serial.print("Total PSRAM:");
   Serial.println(ESP.getPsramSize());
    
   Serial.print("Free PSRAM:");
   Serial.println(ESP.getFreePsram());
        Serial.println("errore qui");
        Serial.println(sstream.str().c_str());
        sample* newSample = new sample(*input);
        newSample -> sampleString = sstream.str();
        counter = 0;
        sstream.str("");
        sstream << "[";
        return newSample;
    }
    return NULL;
 }
 
void queue::parseNumOfSamples( string numString ){
  int numberValue=1;
  // if there is no number we assign 1 because we post one measurement at a time 
  if(!numString.empty())
  {
    if(!isaNumber(numString))
      {
        valid=false;
        return;
      }
      numberValue = atoi(numString.c_str());
      //if(numberValue > batchMaxSize){
      //  valid=false;
      //  return;
      // }
    }	 
  numOfSamples= numberValue;
}