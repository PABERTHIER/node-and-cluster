#pragma once
#include "node.h"
#include <list>
#include <vector>
class Cluster :
    public node
{
public:
    vector<int> member;
    int id;
    double X; // X barycenter
    double Y; // Y barycenter;
    int baricenter;
    Cluster();
    void setMember(const vector<node> M);
    void equilibrate(const vector<node> V);
    double distance(Cluster const& C);
};
