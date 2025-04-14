#include <iostream>
#include <thread>
#include <vector>

using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;

using namespace std;

void input(vvi &m) {
  for (vector<int> &s : m) {
    for (int &i : s) {
      cin >> i;
    }
  }
}

void print(vvi &m) {
  for (vector<int> &s : m) {
    for (int &i : s) {
      cout << i << '\t';
    }
    cout << endl;
  }
}

void multiply(int i, vvi &A, vvi &B, vvi &ans) {
  int n = A.size();
  for (int j = 0; j < n; j++)
    for (int k = 0; k < n; k++)
      ans[i][j] += A[i][k] * B[k][j];
}

int main() {
  cout << "Enter the dimensions: " << endl;
  int n;
  cin >> n;
  vvi A(n, vi(n, 0)), B(n, vi(n, 0)), ans(n, vi(n, 0));
  cout << "Enter A: " << endl;
  input(A);
  cout << "Enter B: " << endl;
  input(B);

  vector<thread> threads;

  for (int i = 0; i < n; i++) {
    threads.emplace_back(multiply, i, std::ref(A), std::ref(B), std::ref(ans));
  }

  for (thread &t : threads) {
    t.join();
  }

  cout << "Result: " << endl;
  print(ans);
}
