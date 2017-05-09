#include"DisjointSets.h"

#include<iostream>

using namespace std;

int main() {


	DisjointSets h(5);


	h.unionSets(1, 2);

	cout<<h.find(2)<<endl;

	h.unionSets(2, 3);

	cout << h.find(3)<<endl;


	cout << h.findCompress(3) << endl;


	cout << h.find(3) << endl;









	system("pause");
	return 0;
}