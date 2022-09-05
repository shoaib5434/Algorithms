#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

/*
	Selection Sort Starts
*/

void selection_sort(vector<int>& v) {
	int min;
	for (int i = 0; i < v.size() - 1; ++i) {
		min = i;
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[min]) min = j;
		}
		swap(v[min],v[i]);
	}
}

/*
	Selection Sort Ends
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
	selection_sort(v);
	saveTestResult("output.txt",v);
}