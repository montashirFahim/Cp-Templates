#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll mod = 1e9 + 7;

template<class T>
class Matrix {
public:
	int r, c;
	vector<vector<T>> M;

	Matrix() {}

	Matrix(int n) {
		this->r = this->c = n;
		M.resize(n, vector<T>(n, 0));
	}

	Matrix(int n, int m) {
		this->r = n, this->c = m;
		M.resize(n, vector<T>(m, 0));
	}

	Matrix(vector<vector<T>> v) {
		this->r = v.size();
		this->c = v[0].size();
		M = v;
	}

	Matrix get_identity(int n) {
		Matrix res(n);
		for (int i = 0; i < n; i++) res.M[i][i] = 1;
		return res;
	}

	Matrix operator+(const Matrix &A) {
		int row = A.r, col = A.c;
		assert(row == r && col == c);
		Matrix res(r, c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				res.M[i][j] = (M[i][j] + A.M[i][j]) % mod;
			}
		}
		return res;
	}

	Matrix operator-(const Matrix &A) {
		int row = A.r, col = A.c;
		assert(row == r && col == c);
		Matrix res(r, c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				res.M[i][j] = (M[i][j] - A.M[i][j] + mod) % mod;
			}
		}
		return res;
	}

	Matrix operator*(const Matrix &A) {
		int row = A.r, col = A.c;
		assert(c == row);
		Matrix res(r, col);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < c; k++) {
					res.M[i][j] = (res.M[i][j] + (M[i][k] * A.M[k][j]) % mod) % mod;
				}
			}
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// Example usage:
	Matrix<ll> A(2, 2);
	A.M = {{1, 2}, {3, 4}};

	Matrix<ll> B(2, 2);
	B.M = {{5, 6}, {7, 8}};

	Matrix<ll> C = A + B;
	Matrix<ll> D = A - B;
	Matrix<ll> E = A * B;

	// Output results
	for (auto row : C.M) {
		for (auto val : row) {
			cout << val << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (auto row : D.M) {
		for (auto val : row) {
			cout << val << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (auto row : E.M) {
		for (auto val : row) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}
