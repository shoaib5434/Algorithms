#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

/*
	Insertion Sort Starts
*/

void insertion_sort(vector<int>& v) {
	for (int i = 1; i < v.size(); ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (v[j] > v[j+1]) swap(v[j],v[j+1]);
			else break;
		}
	}
}

/*
	Insertion Sort Ends
*/
vector<int> getTestData(string s) {
	ifstream getData(s);
	vector <int> data;
	int temp;
	while (!getData.eof()) {
		getData >> temp;
		data.push_back(temp);
		getData.ignore();
	}
	getData.close();
	return data;
}
void saveTestResult(string s,vector<int>& a) {
	ofstream saveData(s);
	for (int i = 0; i < a.size(); ++i) {
		saveData << a[i] << ' ';
	}
	saveData.close();
}
int main() {
	vector<int> v = getTestData("inputs.txt");
	insertion_sort(v);
	saveTestResult("output.txt",v);
}