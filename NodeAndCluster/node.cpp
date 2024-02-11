#include "node.h"
random_device rd;   // non-deterministic generator
mt19937 gen(rd());  // to seed mersenne twister.
uniform_int_distribution<> allocate(2, 5); // distribute results between 1 and 6 inclusive.
uniform_int_distribution<> positionate(0, 100); // distribute results between 1 and 6 inclusive.
node::node()
{
	this->X = positionate(gen);
	this->Y = positionate(gen);
	this->size = allocate(gen);
	this->connected = 0;
	this->clusterId = 0;
	this->minDist = 0;
}

node::node(int id)
{
	this->id = id;
	this->X = positionate(gen);
	this->Y = positionate(gen);
	this->size = allocate(gen);
	this->connected = 0;
	this->clusterId = 0;
	this->minDist = 0;
}

void node::setMinDist(double dist)
{
	this->minDist = dist;
}

double node::distance(node const& N)
{
	double value = sqrt(pow(N.X - this->X, 2) + pow(N.Y - this->Y, 2));
	return value;
}
