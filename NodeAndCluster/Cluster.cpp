#include "Cluster.h"

Cluster::Cluster()
{
	this->id = 0;
	this->member = {};
	this->X = 50;
	this->Y = 50;
	this->baricenter = 50;
}

void Cluster::setMember(const vector<node> M)
{	
	for (int i = 0; i < M.size(); i++) {
		this->member.push_back(M[i].id);
	}
	
}

void Cluster::equilibrate(const vector<node> V)
{
	this->setMember(V);
	double X = 0, Y = 0;
	for (int i = 0; i < member.size(); i++) {
		X += V[this->member[i]].X;
		Y += V[this->member[i]].Y;
	}
	X /= member.size();
	Y /= member.size();
	this->X = X;
	this->Y = Y;


}

double Cluster::distance(Cluster const& C)
{
	double value = sqrt(pow(C.X - this->X, 2) + pow(C.Y - this->Y, 2));
	return value;
}
