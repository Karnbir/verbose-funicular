#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int* generateArr(int n){
   int* ret {(int*)malloc(sizeof(int) * n)};
   
   for(int i{0}; i < n; ++i)
        ret[i] = i;
   
   return ret; 
}

int findBallPos(int n, int k){
    
  int* sequence {generateArr(n)}; // sequence of ball numbers has size n 

  /* 
  int debugArr[3];

  for(int i = 0; i < 5; ++i)
    debugArr[i] = sequence[i];

    DEBUG code.
  */

  int index {0}; // index of target k ball
  
  for(int i{0}; i < n; ++i){

      int counter{0};

      for(int j{i}; (j-i) < (n-i)/2; ++j){

          std::swap(sequence[j], sequence[n - 1 - counter]);
          ++counter;
      }

  }

  for(int i{0}; i < n; ++i){ // Search for index where ball k resides, after array sort
    if(sequence[i] == k){
        index = i;
        break;
    }
    else{
        index = -1;
    } // -1 Error if target k is not found in array

  }
  
  return index;  
}


int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);
    
    vector<int> results;
    
    results.push_back(findBallPos(n,k));
    
    for(int i{0}; i < t-1; ++i){
        getline(cin, first_multiple_input_temp);
        first_multiple_input = split(rtrim(first_multiple_input_temp));
        n = stoi(first_multiple_input[0]);
        k = stoi(first_multiple_input[1]);
        results.push_back(findBallPos(n,k));
    }
    
    for(int i = 0; i < t; ++i){
        std::cout << results[i] << std::endl;
    }
    
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}