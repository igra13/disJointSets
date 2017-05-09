#include"DisjointSets.h"
#include<iostream>

DisjointSets::DisjointSets(int size)
{
	this->size = size;
	this->set = new int[this->size];
	this->count_steps = 0;

	for (int i = 0; i < this->size; i++)
	{
		this->set[i] = -1;
	}

	
}
DisjointSets::DisjointSets(const DisjointSets & orig)
{
	this->size = orig.size;
	this->set = new int[this->size];
	this->count_steps = orig.count_steps;

	for (int i = 0; i < this->size; i++) {
		this->set[i] = orig.set[i];
	}



}
DisjointSets:: ~DisjointSets()
{
	delete[] this->set;
}
DisjointSets & DisjointSets::operator=(const DisjointSets &orig) {

	if (this != &orig)
	{
		delete [] this->set;
		this->size = orig.size;
		this->set = new int[this->size];
		this->count_steps = orig.count_steps;

		for (int i = 0; i < this->size; i++) {
			this->set[i] = orig.set[i];
		}
	}

	return *this;
}
int DisjointSets::find(int x) const
{
	if (x < this->size) {

		if (this->set[x] < 0)
		{
			
			return x;
		}
		else
		{
			return find(this->set[x]);
		}
	}
	
}


int DisjointSets::findCompress(int x) {
	if (x < this->size) {

		if (set[x] < 0)
			return x;
		else
			return set[x] = findCompress(set[x]);
	}

}

void DisjointSets::unionSets(int root1, int root2)
{
	if (find(root1) != find(root2) && root1<this->size && root2<this->size)
	{
		this->set[root2] = root1;
	}
}

void DisjointSets::unionSetsRank(int root1, int root2)
{
	if (find(root1) != find(root2) && root1<this->size && root2<this->size) {

		if (this->set[root2] < this->set[root1]) // root2 is deeper
			this->set[root1] = root2; // Make root2 new root
		else
		{
			if (this->set[root1] == this->set[root2])
				--this->set[root1]; // Update height if same


			this->set[root2] = root1; // Make root1 new root
		}
	}

}

int DisjointSets::totalNumberStepsForFinds() const
{
	return this->count_steps;
}

