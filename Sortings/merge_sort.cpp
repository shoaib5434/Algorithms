#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

/*
	Merge Sort Starts
*/

void merge(vector<int>& a,int left,int mid,int right) {
	for (int i = mid + 1; i <= right; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (a[j] > a[j+1]) swap(a[j],a[j+1]);
			else break;
		}
	}
}

void mergeSort(vector<int>& a,int left,int right) {
	if (left >= right) return;
	int mid = (left + right)/2;
	mergeSort(a,left,mid);
	mergeSort(a,mid+1,right);
	merge(a,left,mid,right);
}

/*
	Merge Sort Ends
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
	mergeSort(v,0,v.size() - 1);
	saveTestResult("output.txt",v);
}