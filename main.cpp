// main.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <iostream>

using namespace std;

int main() {
  string filename;
  string column;
  vector<double> columnValues;
  vector<pair<double, int>> summary;

  cout << "enter a filename" << endl;
  cin >> filename; 
  cout << "enter a column name" << endl;
  cin >> column;
  cout << "reading column " + column + " from " + filename << endl;

  columnValues = extract_column(filename, column);

  //Summary
  cout << "Summary (value: frequency)" << endl;
  summary = summarize(columnValues);
  for (int i = 0; i < columnValues.size(); i++) {
    cout << summary[i].first << ": " << summary[i].second << endl << endl;
  }
  


  // Stats
  cout << "count = " << count(columnValues) << endl;
  cout << "sum = " << sum(columnValues) << endl;
  cout << "mean = " << mean(columnValues) << endl;
  cout << "stdev = " << stdev(columnValues) << endl;
  cout << "median = " << median(columnValues) << endl;
  cout << "mode = " << mode(columnValues) << endl;
  cout << "min = " << min(columnValues) << endl;
  cout << "max = " << max(columnValues) << endl;
  cout << "  0th percentile = " << percentile(columnValues,0) << endl;
  cout << " 25th percentile = " << percentile(columnValues,25) << endl;
  cout << " 50th percentile = " << percentile(columnValues,50) << endl;
  cout << " 75th percentile = " << percentile(columnValues,75) << endl;
  cout << "100th percentile = " << percentile(columnValues,100) << endl;

}
