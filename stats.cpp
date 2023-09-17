// stats.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) {

  assert(!v.empty()); //include this at the beginning for all the functions that require it !!
  sort(v);
  vector<pair<double, int>> summary;


  for (int i = 0; i < v.size(); i++) {
    double freq = 0;
    double value = v[i];
    for (int j = 0; j < v.size(); j++) {
      if (v[i] == v[j]) {
        freq++;
      }
    }
    summary.push_back({value,freq});
  }
  return summary;

}

int count(vector<double> v) {
  int num = 0;
  num = v.size();
  return num;
}

double sum(vector<double> v) {
  assert(!v.empty());
  double total = 0;
  for (int i = 0; i < v.size(); i++){
    total += v[i];
  }
  return total;
 
}

double mean(vector<double> v) {
  assert(!v.empty());
  double average = 0;
  average = sum(v)/v.size();
  return average;

}

double median(vector<double> v) {
  assert(!v.empty());

  sort(v);

  double middle = 0;
  int half = 0;

  if (v.size() == 1) {
    middle = v[0];
  } else if (v.size() % 2 == 0) {
    half = v.size() / 2;
    middle = (v[half - 1] + v[half])/2;
  } else {
    half = v.size() / 2;
    middle = v[half];
  }
  return middle;
}

double mode(vector<double> v) {
  assert(!v.empty());
  sort(v);
  double most = v[0];
  double currentValue = v[0];
  double mostNum = 0;
  double count = 0;

  for (int i = 0 ; i < v.size(); i++) {
    if (currentValue == v[i]) {
      count++;
    }
    else {
      count = 1;
      currentValue = v[i];
    }
    
    if (count > mostNum) {
      mostNum = count;
      most = currentValue;
    }
  }
  return most;

}

double min(vector<double> v) {
  assert(!v.empty());
  sort(v);
  double minimum = 0;
  minimum = v[0];

  return minimum;
}

double max(vector<double> v) {
  assert(!v.empty());
  sort(v);
  double maximum = 0;
  maximum= v[v.size() - 1];

  return maximum;
}

double stdev(vector<double> v) {
  assert(count(v) >=2);
  double stddeviation = 0;
  vector<double> x;

  for (int i = 0; i < v.size(); i++) {
    int value = 0;
    value = v[i] - mean(v);
    x.push_back(value);
  }

  for (int i = 0; i < x.size(); i++) {
    x[i] = x[i]*x[i];
  }

  stddeviation = sqrt((sum(x))/ (x.size() - 1));

  return stddeviation;

}

double percentile(vector<double> v, double p) {
  assert(!v.empty());

  double rank = 0; 

  rank = (p/100)*(v.size() - 1) + 1;

  double percentile_value = 0;
  double whole_part = 0;
  double fract_part = 0;
  fract_part = modf(rank, &whole_part);

  if (p == 100) {
    sort(v);
    percentile_value = v[v.size()-1];
  } else {
    percentile_value = v[whole_part - 1] + fract_part*(v[whole_part] - v[whole_part - 1]);
  }

  return percentile_value;
}
