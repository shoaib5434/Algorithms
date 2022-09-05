#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

/*
	Heap Sort Starts
*/

void heapify(vector<int>& v,int low,int high) {
	int i = low;
	bool flag = true;
	while (i <= high && flag) {
		int left = 2 * i + 1,right = 2 * i + 2,max = i;
		flag = false;
		if (left <= high && v[max] < v[left]) max = left;
		if (right <= high && v[max] < v[right]) max = right;

		if (max != i) {
			flag = true;
			swap(v[i],v[max]);
			i = max;
		}
	}
}

void build_heap(vector<int>& v,int low,int high) {
	int cur = high,parent = (high - 1)/2;
	while (parent >= 0) {
		if (v[parent] < v[cur]) swap(v[parent],v[cur]);
		else break;
		heapify(v,cur,high);
		cur = parent;
		parent = (cur - 1)/2;
	}
}

void heap_sort(vector<int>& v) {
	for (int i = 1; i < v.size(); ++i) {
		build_heap(v,0,i);
	}

	for (int i = v.size() - 1; i >= 1 ; --i) {
		swap(v[0],v[i]);
		heapify(v,0,i - 1);
	}
}

/*
	Heap Sort Ends
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
	heap_sort(v);
	saveTestResult("output.txt",v);
}