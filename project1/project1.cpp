/*
Class: CPSC 122-02
Team Member 1: Trevor Diuco
Team Member 2: None
Submitted By: Trevor Diuco
GU Username: tdiuco
File Name: project1.cpp
Program takes in user input to create an output file that contains the number of prime numbers ordered in n number of columns based on user input
To Build: g++ project1.cpp -o project1
To Execute: ./project1 project1.out
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

bool isPrime(int, vector<int>&);
void writeResultsToFile(ofstream&, vector<int>, int);
void findPrimes(vector<int>&, int);
void clearBuffer();

/*
Pre: num is a test case that comes from the findPrimes() function
Post: If num modulus i, every number up to the sqrt of num that is already in vectorOfPrimes, is 0 and therefore a factor, isPrime returns false.
If num passes all cases, isPrime() returns true.
*/
bool isPrime(int num, vector<int>& vectorOfPrimes)
{
  for (int i = 1; i < vectorOfPrimes.size(); i++)   
  {
    if (vectorOfPrimes.at(i) > sqrt(num))       // Only checking up to the sqrt() of the number because every possible number will have been checked directly or indirectly by another number
      break;
    if (num % vectorOfPrimes.at(i) == 0)        // If num modulus i returns 0 as a remainder, is a factor
      return false;
  }
  return true;
}

/*
Pre: outputFile is passed by reference do it can be written to. vectorOfPrimes filled with prime numbers 
up to userNumber will be written to outputfile. numCols is passed so the program knows how many columns to create
Post: This function writes to outputFile with no return value.
*/
void writeResultsToFile(ofstream& outputFile, vector<int> vectorOfPrimes, int numCols)
{
  int count = 0;
  int rowCount = 0;

  while (count < vectorOfPrimes.size())
  {
    outputFile << vectorOfPrimes.at(count) << "\t";
    if (count % numCols == numCols - 1)
      outputFile << endl;
    count++;
  }
}

/*
Pre: userNumber is used to know when to stop while loop with the correct number of prime numbers.
vectorOfPrimes is passed in by reference so that prime numbers can be added to based on result of isPrime function
Post: Void type is used because there are no return values. The result of the function is vectorOfPrimes with prime numbers up to userNumber
*/
void findPrimes(vector<int>& vectorOfPrimes, int userNumber)
{
  int testNumbers = 3;
  if (userNumber != 0)
    vectorOfPrimes.push_back(2);        // Automatically add 2 to the vector because of its unique prime number properties
  while (vectorOfPrimes.size() < userNumber)
  {
    if (isPrime(testNumbers, vectorOfPrimes))
      vectorOfPrimes.push_back(testNumbers);
    testNumbers+=2;                     // Itterating by 2 each time will skip all composite even numbers
  }
}

/*
Pre: No input values
Post: If cin() fails because a non integer is entered this function clears the cin buffer so that a new input can be taken in.
*/
void clearBuffer()
{
  cout << "Please enter an integer...\n";
  cin.clear();
  cin.ignore(256, '\n');
}

/*
Pre: argc and argv are used to taken command line arguments used to name and execute the program correctly
Post: int main() will create a new file and return 0 if program was successful.
*/
int main (int argc, char* argv[])
{
  int userNumber = 0;
  int numCols = 0;
  vector<int> vectorOfPrimes;
  ofstream outputFile;

  if (argc != 2)
  {
    cout << "Incorrect number of command line arguments" << endl;
    exit(EXIT_FAILURE);
  }

  outputFile.open(argv[1]);

  if (outputFile.fail())
  {
    cout << "File Failed to Open\n" << "Exiting Program...\n";
  }
  else
  {
    cout << "How many primes do you want to see?: ";
    cin >> userNumber;

    while (cin.fail())
    {
      clearBuffer();
      cout << "How many primes do you want to see?: ";
      cin >> userNumber;
    }

    cout << "Distributed over how many columns?: ";
    cin >> numCols;

    while (cin.fail() || numCols == 0)
    {
      clearBuffer();
      cout << "Distributed over how many columns (>0)?: ";
      cin >> numCols;
    }

    findPrimes(vectorOfPrimes, userNumber);
    writeResultsToFile(outputFile, vectorOfPrimes, numCols);
  }

  outputFile.close();
  
  return 0;
}
