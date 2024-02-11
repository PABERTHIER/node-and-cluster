//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <vector>
//#include <map>
//#include <random>
//#include <iostream>
//#include <fstream>
//#include <string> 
//#include <list>
//#include "node.h"
//#include "Cluster.h"
//#define N 1000;
//#define M 50;
//#define Length 10000;
//#define height 10000;
//using namespace std;
//random_device rdm;   // non-deterministic generator
//mt19937 gen2(rdm());  // to seed mersenne twister.
//uniform_int_distribution<> randpocket(0, 100000); // distribute results between 1 and 6 inclusive.
//
//bool sortbysec(const pair<node, double>& a,
//    const pair<node, double>& b)
//{
//    return (a.second < b.second);
//}
//bool sortbysec2(const pair< pair <int, int>, double>& a,
//    const pair< pair <int, int>, double>& b)
//{
//    return (a.second < b.second);
//}
//
//void draw(int step, vector<node> V, vector<pair <int, int> > g) {
//    int PetitN = M;
//    ofstream myfile;
//    string fname = "statuts_" + std::to_string(step) + ".txt";
//    myfile.open(fname);
//    myfile << "digraph G {{	node[margin = 0 fontcolor = blue  width = 0.5 shape = point style = filled]" << endl;
//    for (int i = 0; i < PetitN; i++)
//        switch (V[i].connected) {
//        case 0:
//            myfile << i << "[fillcolor=white fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
//            break;
//        case 1:
//            myfile << i << "[fillcolor=black fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
//            break;
//        case 2:
//            myfile << i << "[fillcolor=green fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
//            break;
//        case 3:
//            myfile << i << "[fillcolor=blue fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
//            break;
//        case 4:
//            myfile << i << "[fillcolor=orange fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
//            break;
//        case 5:
//            myfile << i << "[fillcolor=red fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
//            break;
//        default:
//            myfile << i << "[fillcolor=red fixedsize=true label=\"" << i << "\" pos = \"" << V[i].X << ", " << V[i].Y << "!\"] " << std::endl;
//            break;
//
//        }
//    for (auto it : g) {
//
//        myfile << it.first << "->" << it.second << endl;
//    }
//    myfile << "}}";
//    myfile.close();
//}
//int main()
//{
//    // Approach 1
//    vector<node> population, population3, population4;
//    set<node> peuple;
//    set<pair<int, int>> MinGraph;
//    vector<pair<int, int>> edge, edge2, edge3, edge4;
//    int PetitN = M;
//    for (int i = 0; i < PetitN; i++) {
//        population.push_back(node(i));
//    }
//    // sort(population.begin(), population.end());
//    for (int i = 0; i < PetitN; i++) {
//        peuple.insert(population[i]);
//    }
//    draw(0, population, edge);
//
//    vector<vector<pair<node, double>>> MatriceDistance;
//    vector<pair<node, double>> VectorDistance;
//
//    //vector<vector<pair<pair<int, int>, double>>> MatriceDistance;
//    //vector<pair<pair<int, int>, double>> VectorDistance;
//
//    MatriceDistance.resize(PetitN);
//    for (int i = 0; i < PetitN; i++) {
//        MatriceDistance[i].resize(PetitN); // matrix of M*M
//    }
//    for (int i = 0; i < PetitN; i++) {
//        for (int j = (i + 1); j < PetitN; j++) {
//            MatriceDistance[i][j].first = population[j];
//            MatriceDistance[i][j].second = population[i].distance(MatriceDistance[i][j].first);
//            if (MatriceDistance[i][j].second > 0) {
//                VectorDistance.push_back(MatriceDistance[i][j]);
//            }
//        }
//    }
//
//    std::cout << "Hello World!\n";
//}
//for (int i = 0; i < 1000; i++) {
//    int a = randpocket(gen2) % PetitN;
//    int b = randpocket(gen2) % PetitN;
//    if (a != b) {
//        if ((population1[a].connected < population1[a].size) && (population1[b].connected < population1[b].size)) {
//            population1[a].connected++;
//            population1[b].connected++;
//            edge1.push_back(pair<int, int>(a, b));
//        }
//    }
//    // if ((i % 10) { draw(i, population, edge); }
//}
//
//
//
//draw(40006, population1, edge1);
