#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

/*
	Shell Sort Starts
*/

void shell_sort(vector<int>& v) {
	int gap = (v.size() - 1)/2;
	while (gap > 0) {
		int i = gap;
		while (i < v.size()) {
			int j = i - gap;
			while (j >= 0 && v[j] > v[j + gap]) {
				swap(v[j],v[j+gap]);
				j -= gap;
			}
			++i;
		}
		gap /= 2;
	}
}

/*
	Shell Sort Ends
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
	shell_sort(v);
	saveTestResult("output.txt",v);
}