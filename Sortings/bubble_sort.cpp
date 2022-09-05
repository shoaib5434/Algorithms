#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

/*
	Bubble Sort Starts
*/

void bubble_sort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; ++i) {
		bool isSorted = true;
		for (int j = 0; j < v.size() - 1 - i; ++j) {
			if (v[j] > v[j+1]) {
				swap(v[j],v[j+1]);
				isSorted = false;
			}
		}
		if (isSorted) {
			break;
		}
	}
}

/*
	Bubble Sort Ends
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
	bubble_sort(v);
	saveTestResult("output.txt",v);
}