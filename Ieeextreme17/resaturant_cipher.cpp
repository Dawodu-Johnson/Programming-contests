//
// Created by JOHNSON on 2/20/2024.
// 100% score
#include <bits/stdc++.h>

using namespace std;

/*map<char, int>store;
  vector<char>ra = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};



std::deque<char> splitStringToVector(const std::string& input) {
    std::deque<char> charVector;
    std::istringstream iss(input);
    char c;

    while (iss >> c) {
        charVector.push_back(c);
    }

    return charVector;
}



int main() {

 for(int i  = 0; i < ra.size(); i++) {
     store[ra[i]]++;
  }

  int t;
  cin >> t;
  cin.ignore();
  char x;
  for(int j =0; j < t; j++) {


      deque<char>first, second;
      string p;

    getline(cin, p);
    first = splitStringToVector(p);
    getline(cin, p);
    second = splitStringToVector(p);

    int left1 = 0, left2 = 0;
    while(!first.empty() and !second.empty()) {
        char f = f
    }
  }
}*/

void dod(const string &s, vector<int> &freq) {
    std::istringstream iss(s);
    char c;

    while (iss >> c) {
        if (isalpha(c)) {
            freq[c - 'a'] += 1;
        }
    }
}


int main() {
    int n;
    cin >> n;
    cin.ignore();
    string ss;

    for (int i = 0; i < n; i++) {
        getline(cin, ss);
        vector<int> fre(26, 0);
        dod(ss, fre);
        int answer = 0, index = 0;

        for (int j = 0; j < 7; j++) {
            if (fre[j] > answer) {
                index = j;
                answer = fre[j];
            }
        }
        char p = (char) (index + 'A');


        cout << p << endl;

    }

    return 0;
}
