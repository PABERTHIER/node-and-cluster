#pragma once
#include <random>
#include <iostream>
#include <math.h>
using namespace std;

class node
{
public:
	int id;
	int X;
	int Y;
	int size;
	int connected = 1;
	int clusterId = 0;
	double minDist = 0;
	node();
	node(int id);
	void setMinDist(double dist);
	double distance(node const& N);


	// overload < operator to use a Pair object as a key in a std::set
	bool operator<(node const& p) const
	{
		return (X < p.X) || (X == p.X && Y < p.Y);
	}
};
