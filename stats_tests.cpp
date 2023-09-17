#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_summarize();
void test_count();
void test_mean();
void test_median();
void test_mode();
void test_max();
void test_min();
void test_stdev();
void test_percentile();
// Add prototypes for you test functions here.

int main() {
  test_summarize();
  test_sum_small_data_set();
  test_count();
  test_mean();
  test_median();
  test_mode();
  test_max();
  test_min();
  test_stdev();
  test_percentile();

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data1;
  data1.push_back(1);
  data1.push_back(2);
  data1.push_back(3);

  assert(sum(data1) == 6);

  vector<double> data2;
  data2.push_back(0);
  data2.push_back(0);
  data2.push_back(0);

  assert(sum(data2) == 0);

  cout << "PASS!" << endl;
}

void test_summarize() {
  cout << "test_summarize" << endl;
  vector<double> data1;
  data1.push_back(0);
  data1.push_back(0);
  data1.push_back(0);

  vector<pair<double, int>> summary1;


  summary1 = summarize(data1);

  for (int i = 0; i < 3; i++) {
    assert(summary1[i].first == 0);
    assert(summary1[i].second == 3);
  }
  
  cout << "PASS!" << endl;


}

void test_count() {
  cout << "test_count" << endl;
  vector<double> data1;
  data1.push_back(3);
  data1.push_back(3);
  data1.push_back(-1);
  data1.push_back(3);

  assert(count(data1) == 4);

  vector<double> data2;

  data2.push_back(0);

  assert(count(data2) == 1);

  cout << "PASS!" << endl;
}

void test_mean() {
  cout << "test_mean" << endl;
  vector<double> data1;
  data1.push_back(3);
  data1.push_back(-1);
  data1.push_back(3);
  data1.push_back(3);

  assert(mean(data1) == 2);

  vector<double> data2;

  data2.push_back(0);

  assert(mean(data2) == 0);

  cout << "PASS!" << endl;

}


void test_median() {
  cout << "test_median" << endl;
  vector<double> data1;
  data1.push_back(4);
  data1.push_back(2);
  data1.push_back(7);
  data1.push_back(6);

  assert(median(data1) == 5);

  vector<double> data2;
  data2.push_back(1);
  data2.push_back(4);
  data2.push_back(9);
  data2.push_back(7);
  data2.push_back(3);

  assert(median(data2) == 4);

  vector<double> data3;

  data3.push_back(0);

  assert(median(data3) == 0);

  cout << "PASS!" << endl;

}

void test_mode() {
  cout << "test_mode" << endl;

  vector<double> data1;
  data1.push_back(1);
  data1.push_back(2);
  data1.push_back(1);
  data1.push_back(2);

  assert(mode(data1) == 1);

  vector<double> data2;
  data2.push_back(3);
  data2.push_back(3);
  data2.push_back(2);
  data2.push_back(2);
  data2.push_back(3);

  assert(mode(data2) == 3);

  vector<double> data3;

  data3.push_back(0);

  assert(mode(data3) == 0);

  cout << "PASS!" << endl;


}

void test_min() {
  cout << "test_min" << endl;
  vector<double> data1;
  data1.push_back(4);
  data1.push_back(2);
  data1.push_back(7);
  data1.push_back(6);

  assert(min(data1) == 2);

  vector<double> data2;
  data2.push_back(1);
  data2.push_back(4);
  data2.push_back(-9);
  data2.push_back(7);
  data2.push_back(3);

  assert(min(data2) == -9);

  vector<double> data3;

  data3.push_back(0);

  assert(min(data3) == 0);

  cout << "PASS!" << endl;

}

void test_max() {
  cout << "test_max" << endl;
  vector<double> data1;
  data1.push_back(4);
  data1.push_back(2);
  data1.push_back(7);
  data1.push_back(6);

  assert(max(data1) == 7);

  vector<double> data2;
  data2.push_back(-1);
  data2.push_back(-4);
  data2.push_back(-9);
  data2.push_back(-7);
  data2.push_back(-3);

  assert(max(data2) == -1);

  vector<double> data3;

  data3.push_back(0);

  assert(max(data3) == 0);

  cout << "PASS!" << endl;

}

void test_stdev() {

  cout << "test_stdev" << endl;

  vector<double> data1;
  data1.push_back(-2);
  data1.push_back(-4);
  data1.push_back(-9);
  data1.push_back(-7);
  data1.push_back(-3);

  assert(stdev(data1) == sqrt(8.5));

  vector<double> data2;
  data2.push_back(1);
  data2.push_back(2);
  data2.push_back(3);

  assert(stdev(data2) == 1);

  vector<double> data3;
  
  data3.push_back(0);
  data3.push_back(0);

  assert(stdev(data3) == 0);


  cout << "PASS!" << endl;

}

void test_percentile() {
  cout << "test_percentile" << endl;

  vector<double> data1;
  
  data1.push_back(0);
  data1.push_back(0);

  assert(percentile(data1, 0.2) == 0);

  vector<double> data3;
  data3.push_back(-1);
  data3.push_back(-4);
  data3.push_back(-9);
  data3.push_back(-7);
  data3.push_back(-3);

  assert(percentile(data3, 0) == -9);

  cout << "PASS!" << endl;

}

// Add the test function implementations here.
