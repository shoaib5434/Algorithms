#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

/*
	Quick Sort Starts
*/

int partion(vector<int>& v,int low,int high) {
	if (low == high) return low;
	int i = low,pivot = low;
	for (int j = low + 1; j <= high; ++j) {
		if (v[j] < v[pivot]) {
			if (i == pivot) pivot = j;
			swap(v[j],v[i]);
			++i;
		}
	}
	swap(v[i],v[pivot]);
	return i;
}

void quick_sort(vector<int>& v,int low,int high) {
	if (low > high) return;
	int point = partion(v,low,high);
	quick_sort(v,low,point - 1);
	quick_sort(v,point + 1,high);
}

/*
	Quick Sort Ends
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
	quick_sort(v,0,v.size() - 1);
	saveTestResult("output.txt",v);
}