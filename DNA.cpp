#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

//A method to calculate the new string of DNA
string dnaCreation(int D, double aProb, double cProb, double tProb, double gProb){
//Local variable declation
  string sequence = "";
  char nucleotide = '\0';
  double num3 = 0;

//Assigning a nucleotide based upon probability
  for(int j = 0; j < D; ++j){

    num3 = (double)rand()/RAND_MAX;
    if(num3 > 0 && num3 < aProb){
      nucleotide = 'A';
    }else if (num3 > aProb && num3 < (aProb + cProb)){
      nucleotide = 'C';
    }else if(num3 > (cProb + aProb) && num3 < (tProb + cProb + aProb)){
      nucleotide = 'T';
    }else if(num3 < 1){
      nucleotide = 'G';
    }else{
      cout << "Couldn't assign a Nucleotide";
    }
//Compiling sequence with nucleotides
    sequence += nucleotide;
  }

  return sequence;
}

int main(int argc,char **argv){

//Main declations for file-io
  string file = argv[1];
  ifstream myIFile;
  ofstream myOFile ("JacksonGoldberg.out");
//Variable declations
  char answer = '\0';
  float sum = 0;
  double mean = 0.0;
  float counter = 0;
  float letterCounter = 0;
  float doubleLetterCounter = 0;
  double varience = 0.0;
  double standDiviation = 0.0;
  float length = 0;
  string value = "";
  int aCounter = 0;
  int cCounter = 0;
  int gCounter = 0;
  int tCounter = 0;
  int aaCounter = 0;
  int acCounter = 0;
  int atCounter = 0;
  int agCounter = 0;
  int caCounter = 0;
  int ccCounter = 0;
  int ctCounter = 0;
  int cgCounter = 0;
  int taCounter = 0;
  int tcCounter = 0;
  int ttCounter = 0;
  int tgCounter = 0;
  int gaCounter = 0;
  int gcCounter = 0;
  int ggCounter = 0;
  int gtCounter = 0;
  const double PI = 3.141592;
  double aProb = 0;
  double cProb = 0;
  double gProb = 0;
  double tProb = 0;
  double num1 = 0.0;
  double num2 = 0.0;
  double C = 0;
  double D = 0;

//Start of main do-while loop
  do{

//Resetting variables for new files
    answer = '\0';
    sum = 0;
    mean = 0.0;
    counter = 0;
    letterCounter = 0;
    doubleLetterCounter = 0;
    varience = 0.0;
    standDiviation = 0.0;
    length = 0;
    value = "";
    aCounter = 0;
    cCounter = 0;
    gCounter = 0;
    tCounter = 0;
    aaCounter = 0;
    acCounter = 0;
    atCounter = 0;
    agCounter = 0;
    caCounter = 0;
    ccCounter = 0;
    ctCounter = 0;
    cgCounter = 0;
    taCounter = 0;
    tcCounter = 0;
    ttCounter = 0;
    tgCounter = 0;
    gaCounter = 0;
    gcCounter = 0;
    ggCounter = 0;
    gtCounter = 0;
    aProb = 0;
    cProb = 0;
    gProb = 0;
    tProb = 0;
    num1 = 0.0;
    num2 = 0.0;
    C = 0;
    D = 0;

//Open file
  myIFile.open(file);

  if(!myIFile){
    cout << "Couldn't open the file." << endl;
    exit(1);
  }
//Start of file input code
  if(myIFile.is_open()){

    while(myIFile){

      getline(myIFile, value);
//Checks for empty lines
      if(value.length() > 0){
//Initial stats calculation
      counter++;
      length = value.length() - 1;
      sum += length;
      mean = sum / counter;
//Nucleotide read in and counter updating
      for(int i = 0; i < value.length(); i+=2){

        if(toupper(value.at(i)) == 'A'){
          aCounter++;
          letterCounter++;

          if(toupper(value.at(i + 1)) == 'A'){
            aaCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'C'){
            acCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'T'){
            atCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'G'){
            agCounter++;
            doubleLetterCounter++;
          }
        }

        if(toupper(value.at(i)) == 'C'){
          cCounter++;
          letterCounter++;

          if(toupper(value.at(i + 1)) == 'C'){
            ccCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'A'){
            caCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'T'){
            ctCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'G'){
            cgCounter++;
            doubleLetterCounter++;
          }
        }

        if(toupper(value.at(i)) == 'T'){
          tCounter++;
          letterCounter++;

          if(toupper(value.at(i + 1)) == 'T'){
            ttCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'A'){
            taCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'C'){
            tcCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'G'){
            tgCounter++;
            doubleLetterCounter++;
          }

        }

        if(toupper(value.at(i)) == 'G'){
          gCounter++;
          letterCounter++;

          if(toupper(value.at(i + 1)) == 'G'){
            ggCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'A'){
            gaCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'C'){
            gcCounter++;
            doubleLetterCounter++;
          }
          if(toupper(value.at(i + 1)) == 'T'){
            gtCounter++;
            doubleLetterCounter++;
          }
        }
      }
    }
  }
//Closing input file
    myIFile.close();
}
//Second read of input file with the mean
  myIFile.open(file);
  value = "";
//Varience calculation
  while(myIFile){
    getline(myIFile, value);
    if(value.length() > 0){
      length = value.length()-1;
      varience += static_cast<double>(pow(abs(length-mean), 2));
    }
  }
  myIFile.close();

//Nucleotide probability calculation
  aProb = aCounter / letterCounter;
  cProb = cCounter / letterCounter;
  tProb = tCounter / letterCounter;
  gProb = gCounter / letterCounter;
//Standard diviation calculation
  varience = varience / counter;
  standDiviation = sqrt(varience);
//Writing to my out put file
  if(!myOFile){
    cout << "Couldn't Write to JacksonGoldberg.txt"<< endl;
  }
//Header
    myOFile << "Jackson A. Goldberg\n2347419\njacgoldberg@chapman.edu\nCPSC 350\n\n";
    myOFile << "The Sum of the lengths inputted is: " << sum << endl;
    myOFile << "The Mean of the lengths is: " << mean << endl;
    myOFile << "The Variance of the length is: " << varience << endl;
    myOFile << "The Standard Deviation is: " << standDiviation << endl;
//probability output
    myOFile << "This is the relative probability of each nucleotide: " << endl;
    myOFile << endl;
    myOFile << "A: " << (aCounter / letterCounter) << endl;
    myOFile << "C: " << (cCounter / letterCounter) << endl;
    myOFile << "G: " << static_cast<double>(gCounter / letterCounter) << endl;
    myOFile << "T: " << static_cast<double>(tCounter / letterCounter) << endl;
//Nucleotide bigram probability
    myOFile << "\nThe relative probability of each nucleotide bigram: " << endl;
    myOFile << "\nAA: " << aaCounter / doubleLetterCounter << "\nAC: "
      << (acCounter / doubleLetterCounter) << "\nAT: "
      << (atCounter / doubleLetterCounter) << "\nAG: "
      << (agCounter / doubleLetterCounter) << "\nCA: "
      << (caCounter / doubleLetterCounter) << "\nCC: "
      << (ccCounter / doubleLetterCounter) << "\nCT: "
      << (ctCounter / doubleLetterCounter) << "\nCG: "
      << (cgCounter / doubleLetterCounter) << "\nTA: "
      << (taCounter / doubleLetterCounter) << "\nTC: "
      << (tcCounter / doubleLetterCounter) << "\nTT: "
      << (ttCounter / doubleLetterCounter) << "\nTG: "
      << (tgCounter / doubleLetterCounter) << "\nGA: "
      << (gaCounter / doubleLetterCounter) << "\nGC: "
      << (gcCounter / doubleLetterCounter) << "\nGT: "
      << (gtCounter / doubleLetterCounter) << "\nGG: "
      << (ggCounter / doubleLetterCounter) << endl;
//Closing the file
  myOFile.close();
//Appending Code
  myOFile.open("JacksonGoldberg.out", ofstream::out | ofstream::app);
  string dnaC = "";

//Writing 1000 Lines
  for(int k = 0; k < 1000; ++k){
//Creating the length with proper varience
    num1 = (double)rand()/RAND_MAX;
    num2 = (double)rand()/RAND_MAX;
    //cout << num1 << " " << num2 << endl;
    C = sqrt(((-2.0) * (log(num1))) * (cos((2.0) * (PI * num2))));
    //cout << "C: " << C << endl;
    D = (standDiviation * C) + mean;

    D = (int)D;

//printing the new strings to the file
    dnaC = dnaCreation(D, aProb, cProb, tProb, gProb);

    myOFile << dnaC << endl;

  }


//Second file optional inout
cout << "Would you like to enter another file? (Y/N)" << endl;
cin >> answer;
if(answer == 'Y'){
cout << "Name of File: " << endl;
cin >> file;
}else{
  cout << "Done" << endl;
  exit(1);
}
//end of while loop
}while(answer == 'Y');
myOFile.close();
}
