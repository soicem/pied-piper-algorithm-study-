#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;

int AGTC[4] = { 0, };
vector<pair<string, int>> cache;

int getCostofString(string s) {
	int cost = 0;
	for (int cnt = 0; cnt < s.size(); cnt++) {
		if (s[cnt] == 'A')
			cost += AGTC[0];
		else if (s[cnt] == 'G')
			cost += AGTC[1];
		else if (s[cnt] == 'T')
			cost += AGTC[2];
		else if (s[cnt] == 'C')
			cost += AGTC[3];
	}
	return cost;
}

pair<string, int> getLongestCommonSequence(string s1, string s2) {
	//cout << s1 << " " << s2 << endl;
	string result = "";
	int maxVal = 0;
	int sizeOfS1 = s1.size();
	int sizeOfS2 = s2.size();
	vector<vector<int> > v(sizeOfS2 + 1, vector<int>(sizeOfS1 + 1, 0));
	for (int i = 0; i < sizeOfS2; i++) {
		for (int j = 0; j < sizeOfS1; j++) {
			if (s2[i] == s1[j]) {
				v[i + 1][j + 1] = v[i][j] + 1;
			}
			else {
				v[i + 1][j + 1] = max(v[i][j + 1], v[i + 1][j]);

			}
		}
	}

	int i = sizeOfS2; // row
	int j = sizeOfS1; // column
	while (v[i][j] > 0) {
		
		if (v[i][j] > v[i][j - 1]) {
			if (v[i][j] > v[i - 1][j]) {
				maxVal += v[i][j];
				result = s2[i - 1] + result;
				i = i - 1;
				j = j - 1;
			}
			else
				i = i - 1;
		} else if (v[i][j] > v[i - 1][j]) {
			if (v[i][j] > v[i][j - 1]) {
				maxVal += v[i][j];
				result = s2[i - 1] + result;
				i = i - 1;
				j = j - 1;
			}
			else
				j = j - 1;
		}
		else {
			i -= 1;
		}
		
		
	}
	pair<string, int> ret;
	ret.first = result;
	ret.second = getCostofString(result);
	return ret;
}

pair<string, int> strongestCommonSequenceWithDp(string s1, string s2, int bitOfCache) {
	int sizeOfS2 = s2.size();
	if (sizeOfS2 == 8) {
		cache[bitOfCache] = getLongestCommonSequence(s1, s2);
		return cache[bitOfCache];
	}
	else if (!cache[bitOfCache].first.empty()) {
		return cache[bitOfCache];
	}
		
	else {
		pair<string, int> maxS;
		
		string tmp;
		string ret;
		string maxStr;
		pair<string, int> buf;
		for (int cnt = 0; cnt < sizeOfS2; cnt++) {
			tmp = s2.substr(0, cnt) + s2.substr(cnt + 1, sizeOfS2 - 1) ;
			buf = strongestCommonSequenceWithDp(s1, tmp, bitOfCache - (1 << (sizeOfS2 - (cnt + 1))));
			if(!maxS.first.empty())
				if (buf.second > maxS.second) {
					maxS = buf;
				}
			buf = getLongestCommonSequence(s1, tmp);
			
			if (buf.second > maxS.second) {
				maxS = buf;
			}
		}
		cache[bitOfCache] = maxS;
		return cache[bitOfCache];
	}
}

int main(void) {
	//vector<int> v;
	ifstream inf;
	ofstream outf("gene.out");
	inf.open("gene.inp");
	string s1;
	string s2;
	string result;
	vector<int>::iterator iter;
	
	getline(inf, s1);
	cout << s1 << endl;
	getline(inf, s2);
	int bitOfCache = (1 << s2.size()) - 1;
	cache.resize(bitOfCache + 1);
	cout << s2 << endl;
	for (int cnt = 0; cnt < 4; cnt++) {
		inf >> AGTC[cnt];
		cout << AGTC[cnt] << endl;
	}
	pair<string, int> v = strongestCommonSequenceWithDp(s1, s2, bitOfCache);
	cout << "max : " <<  v.second << " " << v.first << endl;
	inf.close();
	outf.close();
	system("pause");
	return 0;
}