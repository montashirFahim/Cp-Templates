#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI acos(-1)

class Trie {
	//N is way big then don't use struct and trie and cnt declare as global array
	//Don't use as Class
	int num;
	vector<int>cnt, ends;
	vector<vector<int> >trie;
public:
	Trie() {}
	void init() {
		num = 0;
		cnt.clear(), trie.clear();
		trie.push_back(vector<int>(26)), ends.push_back(0), cnt.push_back(0);
		for (int i = 0; i < 26; i++) {
			trie.back()[i] = -1;
		}
	}
	void insert(string s) {
		int node = 0;
		cnt[node]++;
		for (int i = 0; i < s.size(); i++) {
			int k = s[i] - 'a';
			if (trie[node][k] == -1) {
				trie.push_back(vector<int>(26)), cnt.push_back(0);
				for (int i = 0; i < 26; i++) {
					trie.back()[i] = -1;
				}
				trie[node][k] = ++num;
			}
			node = trie[node][k];
			cnt[node]++;
		}
		ends[node]++;
	}
	//any prefix s exists
	int query(string s) {
		int node = 0;
		for (int i = 0; i < s.size(); i++) {
			int k = s[i] - 'a';
			if (trie[node][k] == -1)return 0;
			node = trie[node][k];
		}
		return 1;
	}
	//traverse trie
	void dfs(int node, string s) {
		if (ends[node]) {
			cout << s << "\n";
			return;
		}
		for (int i = 0; i < 26; i++) {
			if (trie[node][i] == -1)continue;
			s.push_back((char)('a' + i));
			dfs(trie[node][i], s);
			s.pop_back();
		}
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}