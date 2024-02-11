#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <random>
#include <iostream>
#include <fstream>
#include <string> 
#include <list>
#include <cfloat>
#include <limits>
#include "node.h"
#include "Cluster.h"
#define N 1000;
#define M 50;
#define Length 10000;
#define height 10000;
using namespace std;
random_device rdm;   // non-deterministic generator
mt19937 gen2(rdm());  // to seed mersenne twister.
uniform_int_distribution<> randpocket(0, 100000); // distribute results between 1 and 6 inclusive.

bool sortbysec(const pair<node, double>& a,
    const pair<node, double>& b)
{
    return (a.second < b.second);
}
bool sortbysec2(const pair< pair <int, int>, double>& a,
    const pair< pair <int, int>, double>& b)
{
    return (a.second < b.second);
}

void draw(int step, vector<node> V, vector<pair <int, int> > g) {
    int PetitN = M;
    ofstream myfile;
    string fname = "statuts_" + std::to_string(step) + ".txt";
    myfile.open(fname);
    myfile << "digraph G {{ node[margin = 0 fontcolor = blue  width = 0.5 shape = point style = filled]" << endl;
    for (int i = 0; i < PetitN; i++)
        switch (V[i].connected) {
        case 0:
            myfile << i << "[fillcolor=white fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
            break;
        case 1:
            myfile << i << "[fillcolor=black fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
            break;
        case 2:
            myfile << i << "[fillcolor=green fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
            break;
        case 3:
            myfile << i << "[fillcolor=blue fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
            break;
        case 4:
            myfile << i << "[fillcolor=orange fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
            break;
        case 5:
            myfile << i << "[fillcolor=red fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
            break;
        default:
            myfile << i << "[fillcolor=red fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
            break;

        }
    for (auto it : g) {

        myfile << it.first << "->" << it.second << endl;
    }
    myfile << "}}";
    myfile.close();
}
int main()
{
    vector<node> population;
    vector<pair <int, int>> edge;
    int PetitN = M;
    for (int i = 0; i < PetitN; i++)
    {
        population.push_back(node(i));
    }
    set<pair<int, int>> SetEdge;

    static std::random_device seed;
    static std::mt19937 random_number_generator(seed());
    std::uniform_int_distribution<size_t> indices(0, population.size() - 1);

    vector<node> centroids;
    srand(time(0));
    for (int i = 0; i < population.size(); ++i) {
        centroids.push_back(population[rand() % population.size()]);
    }

    for (vector<node>::iterator c = begin(centroids);
        c != end(centroids); c++) {

        for (vector<node>::iterator it = population.begin();
            it != population.end(); it++) {

            node n = *it;
            double dist = c->distance(n);
            population[n.id].setMinDist(dist);

            double group = fmod(dist, 2);
            if (group < 1) {
                population[n.id].clusterId = 0;
            }
            else {
                population[n.id].clusterId = 1;
            }
        }
    }

    vector<int> nPoints;
    vector<double> sumX, sumY;

    for (int j = 0; j < population.size(); j++) {
        nPoints.push_back(0);
        sumX.push_back(0.0);
        sumY.push_back(0.0);
    }
    int iterator = 0;
    for (vector<node>::iterator it = population.begin();
        it != population.end(); it++) {
        nPoints[iterator] += 1;
        sumX[iterator] += it->X;
        sumY[iterator] += it->Y;
        iterator++;
    }

    for (vector<node>::iterator c = begin(population);
        c != end(population); c++) {
        int clusterId = c - begin(population);
        c->X = sumX[clusterId] / nPoints[clusterId];
        c->Y = sumY[clusterId] / nPoints[clusterId];

        for (int i = 0; i < population.size(); i++) {
            int a = randpocket(gen2) % population.size();
            int b = randpocket(gen2) % population.size();
            pair<int, int> P;
            if (a < b) {
                P.first = a;
                P.second = b;
            }
            else {
                P.first = b;
                P.second = a;
            }
            if (a != b) {
                if ((population[a].connected < population[a].size) && (population[b].connected < population[b].size) &&
                    (population[b].clusterId == population[a].clusterId) &&
                    ((population[a].connected < 2 && population[b].connected < 2))) {
                    if (SetEdge.find(P) == SetEdge.end()) {
                        population[a].connected++;
                        population[b].connected++;
                        SetEdge.insert(P);
                    }
                }
                else if ((population[a].connected < population[a].size) && (population[b].connected < population[b].size) &&
                    ((population[a].connected < 2 && population[b].connected < 2))) {
                    if (SetEdge.find(P) == SetEdge.end()) {
                        population[a].connected++;
                        population[b].connected++;
                        SetEdge.insert(P);
                    }
                }
            }
        }
    }

    for (auto it : SetEdge) {
        edge.push_back(it);
    }
    draw(40008, population, edge);

    std::cout << "Hello World!\n";
}
