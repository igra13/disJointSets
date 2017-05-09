#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

using namespace std;

class DisjointSets
{
private:
	int * set; // array for representing the sets
	int size; // size of the array
	int count_steps; // counter for total number of steps taken by all
                         // find() alternatively all findCompress()

        // hjälpfunktioner efter behov

public:
	DisjointSets(int size); // size is the number of elements
	DisjointSets(const DisjointSets &orig);
	virtual ~DisjointSets();
	DisjointSets& operator=(const DisjointSets &orig);
	int find(int x) const;
	int findCompress(int x);
	void unionSets(int root1, int root2);
	void unionSetsRank(int root1, int root2);
	int totalNumberStepsForFinds() const; // returns the value of count_steps
};

#endif