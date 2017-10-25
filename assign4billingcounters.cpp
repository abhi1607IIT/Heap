#include <iostream>
#include <vector>
#include <queue>
#include "heap.h"
using namespace std;



void insertion(int arrivaltime,int servicetime,heap1& h1,heap2& h2,vector<queue<int>*>& arr ,int globaltime){
	int currcounter=h1.displayroot()->counternumber;
	int currdeparttime=0,currwaitingtime=0;
	h1.displayroot()->customerno++;	
	if(arr[currcounter-1]->empty()){
		currwaitingtime=0;
		currdeparttime=servicetime+arrivaltime;
		arr[currcounter-1]->push(arrivaltime);
	}
	else{
		currdeparttime =h1.displayroot()->depttimeallcurrcustomer - (arrivaltime-arr[currcounter-1]->front())+servicetime + arrivaltime;
		currwaitingtime=h1.displayroot()->depttimeallcurrcustomer - (arrivaltime-arr[currcounter-1]->front());
		arr[currcounter-1]->push(arrivaltime);
	}
	h1.displayroot()->depttimeallcurrcustomer=h1.displayroot()->depttimeallcurrcustomer+servicetime;
	h1.heapify();
	cout<<"average waiting time is "<<currwaitingtime<<endl;
	customernode* newnode=new customernode(currcounter,arrivaltime,currdeparttime);
	h2.insert(newnode);
}

void deletion(heap1& h1,heap2& h2,vector<queue<int>*>& arr ,int globaltime){
	int currcounter=h2.displayroot()->counterno;
	
	counterinfo* temp=h1.search(currcounter); 
	temp->customerno--;
	int store=arr[currcounter-1]->front();
	temp->depttimeallcurrcustomer=temp->depttimeallcurrcustomer-(globaltime-store);
	arr[currcounter-1]->pop();
	int difference=globaltime-arr[currcounter-1]->front();
	temp->depttimeallcurrcustomer=temp->depttimeallcurrcustomer + difference;
	h1.heapifydel(currcounter);
	//cout<<h2.displayroot()->counterno<<endl;
	h2.removeMin();
	//cout<<h2.displayroot()->counterno<<endl;
}

int main() {
	
	int k=3,n,m,v,r;
	/*
	cout<<"ENTER NO OF CUSTOMERS"<<endl;
	cin>>n;
	cout<<"ENTER NO OF BILLING COUNTERS"<<endl;
	cin>>k;
	cout<<"ENTER THE RATE OF ARRIVING OF CUSTOMERS"<<endl;
	cin>>r;
	cout<<"ENTER THE MEAN"<<endl;
	cin>>m;
	cout<<"ENTER THE VARIANCE"<<endl;
	cin>>v;
	*/
	heap1 h1;
	for (int i = 0; i < k; i++) {
		counterinfo *newnode=new counterinfo(i+1,0,0);
		h1.insert(newnode);
	}	
	heap2 h2;
	vector<queue<int>*>arr;
	for(int i=0;i<k;i++){
		queue<int> * q=new queue<int>;
		arr.push_back(q);
	}

	insertion(0,20,h1,h2,arr,0);
	insertion(5,13,h1,h2,arr,5);
	insertion(13,5,h1,h2,arr,13);
	
	insertion(14,4,h1,h2,arr,14);
	insertion(15,8,h1,h2,arr,15);
	insertion(16,5,h1,h2,arr,16);
	deletion(h1,h2,arr,18);
	deletion(h1,h2,arr,18);
	insertion(19,10,h1,h2,arr,19);
	cout<<h1.displayroot()->counternumber<<endl;
	cout<<h1.displayroot()->customerno<<endl;
	cout<<h1.displayroot()->depttimeallcurrcustomer<<endl;	
	
/*
	int globaltime=0;
	int arrivaltime=0;
	int servicetime=m;
	for(int i=0;i<n;i++){
		insertion(arrivaltime,servicetime,h1,h2,arr,globaltime);
		arrivaltime=arrivaltime+2;
		globaltime=arrivaltime;
		if(h2.displayroot()->depttime<globaltime){
			deletion(h1,h2,arr,globaltime);
		}

	}
	*/


}

