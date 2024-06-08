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
		assert(this->c == row);
		Matrix res(this->r, col);
		for (int i = 0; i < this->r; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < this->c; k++) {
					res.M[i][j] = (res.M[i][j] + (M[i][k] * A.M[k][j]) % mod) % mod;
				}
			}
		}
		return res;
	}
	Matrix power(ll n) {
		Matrix res = get_identity(this->r);
		Matrix base = *this;
		while (n) {
			if (n & 1) {
				res = res * base;
				n--;
			} else {
				base = base * base;
				n /= 2;
			}
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	if (n == 0 || n == 1) {
		cout << n << "\n";
		return 0;
	}
	Matrix<ll>base({{1, 1}, {1, 0}});
	vector<vector<ll> >v;
	v.push_back({1LL});
	v.push_back({0LL});
	Matrix<ll>fib(v);
	base = base.power(n - 1);
	Matrix<ll>res = base * fib;
	cout << res.M[0][0] << "\n";
	return 0;
}
