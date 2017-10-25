#include <vector>
using namespace std;

class counterinfo{
public:
	int counternumber;
	int customerno;
	float depttimeallcurrcustomer;
	counterinfo(int counternumber,int customerno,float depttimeallcurrcustomer){
		this->counternumber=counternumber;
		this->customerno=customerno;
		this->depttimeallcurrcustomer=depttimeallcurrcustomer;
	}
};

class customernode{
public:
	int counterno;
	float arrivtime;
	float depttime;
	customernode(int counterno,float arrivtime,float depttime){
		this->counterno=counterno;
		this->arrivtime=arrivtime;
		this->depttime=depttime;
	}
};
class heap1 {
	vector<counterinfo*> data;
	public:

	heap1() {
		data.push_back(NULL);

	}

	int size() {
		return data.size() - 1;
	}

	bool isEmpty() {
		return size() == 0;
	}

	void removeMin() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}
		data[1] = data[data.size() - 1];
		data.pop_back();
		int currentIndex = 1;
		int leftIndex = 2*currentIndex;
		int rightIndex = 2*currentIndex + 1;
		while (leftIndex < data.size()) {
			int minIndex = currentIndex;
			if (data[leftIndex]->customerno < data[minIndex]->customerno) {
				minIndex = leftIndex;
			}

			if (rightIndex < data.size() &&
					data[rightIndex]->customerno < data[minIndex]->customerno) {
				minIndex = rightIndex;
			}
			if (minIndex == currentIndex) {
				break;
			} else {
				counterinfo* temp = data[minIndex];
				data[minIndex] = data[currentIndex];
				data[currentIndex] = temp;
				currentIndex = minIndex;
				leftIndex = 2*currentIndex;
				rightIndex = 2*currentIndex + 1;
			}
		}
	}

	counterinfo* displayroot() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}
		return data[1];
	}

	counterinfo* search(int counter){
		for(int i=1;i<data.size();i++){
			if(data[i]->counternumber==counter){
				return data[i];
			}
		}
		return NULL;
	}

	void insert(counterinfo* next) {
		data.push_back(next);
		int childIndex = data.size() - 1;
		int parentIndex = childIndex/2;
		while (childIndex != 1) {
			if (data[childIndex]->customerno >= data[parentIndex]->customerno) {
				break;
			} else {
				counterinfo* child =  data[childIndex];
				data[childIndex] = data[parentIndex];
				data[parentIndex] = child;
				childIndex = parentIndex;
				parentIndex = childIndex/2;
			}
		}
	}
	void heapify(){
		int currentIndex = 1;
		int leftIndex = 2*currentIndex;
		int rightIndex = 2*currentIndex + 1;
		while (leftIndex < data.size()) {
			int minIndex = currentIndex;
			if (data[leftIndex]->customerno < data[minIndex]->customerno) {
				minIndex = leftIndex;
			}

			if (rightIndex < data.size() &&
					data[rightIndex]->customerno < data[minIndex]->customerno) {
				minIndex = rightIndex;
			}
			if (minIndex == currentIndex) {
				break;
			} else {
				counterinfo* temp = data[minIndex];
				data[minIndex] = data[currentIndex];
				data[currentIndex] = temp;
				currentIndex = minIndex;
				leftIndex = 2*currentIndex;
				rightIndex = 2*currentIndex + 1;
			}
		}
	}

	void heapifydel(int counter){
		int childIndex=1;
		int parentIndex=0;
		for(int i=1;i<data.size();i++){
			if(data[i]->counternumber==counter){
				childIndex=i;
				parentIndex=childIndex/2;
			}
		}
		while (childIndex != 1) {
			if (data[childIndex]->customerno >= data[parentIndex]->customerno) {
				break;
			} else {
				counterinfo* child =  data[childIndex];
				data[childIndex] = data[parentIndex];
				data[parentIndex] = child;
				childIndex = parentIndex;
				parentIndex = childIndex/2;
			}
		}
	}
};


class heap2 {
	vector<customernode*> data;
	public:

	heap2() {
		data.push_back(NULL);

	}

	int size() {
		return data.size() - 1;
	}

	bool isEmpty() {
		return size() == 0;
	}

	void removeMin() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}
		data[1] = data[data.size() - 1];
		data.pop_back();
		int currentIndex = 1;
		int leftIndex = 2*currentIndex;
		int rightIndex = 2*currentIndex + 1;
		while (leftIndex < data.size()) {
			int minIndex = currentIndex;
			if (data[leftIndex]->depttime < data[minIndex]->depttime) {
				minIndex = leftIndex;
			}

			if (rightIndex < data.size() &&
					data[rightIndex]->depttime < data[minIndex]->depttime) {
				minIndex = rightIndex;
			}
			if (minIndex == currentIndex) {
				break;
			} else {
				customernode* temp = data[minIndex];
				data[minIndex] = data[currentIndex];
				data[currentIndex] = temp;
				currentIndex = minIndex;
				leftIndex = 2*currentIndex;
				rightIndex = 2*currentIndex + 1;
			}
		}
	}

	customernode* displayroot() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}

		return data[1];
	}

	void insert(customernode* next) {
		data.push_back(next);
		int childIndex = data.size() - 1;
		int parentIndex = childIndex/2;
		while (childIndex != 1) {
			if (data[childIndex]->depttime >= data[parentIndex]->depttime) {
				break;
			} else {
				customernode* child =  data[childIndex];
				data[childIndex] = data[parentIndex];
				data[parentIndex] = child;
				childIndex = parentIndex;
				parentIndex = childIndex/2;
			}
		}
	}

};
