#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Graph {
    public:
        // Graph() {}
        Graph(vector<int> init) {
            size = init.size();
            adjMatrix = vector<vector<int>>(size);
            for(int i = 0; i < size; i++)
                adjMatrix[i] = vector<int>(size);
        }
        void addEdge(int from, int to, int weight = 1) {
            resizeMatrix((int) fmax(from, to));
            adjMatrix[from][to] = weight;
            adjMatrix[to][from] = weight;
        }
        void printAdjMat() {
            cout << "Graph Adjacency Matrix: " << endl << "  ";
            for(int i = 0; i < size; i++)
                cout << i << " ";
            cout << endl;

            for(int i = 0; i < adjMatrix.size(); i++) {
                cout << i << " ";
                for(int j = 0; j < adjMatrix[i].size(); j++)
                    cout << adjMatrix[i][j] << " ";
                cout << endl;
            }
        }
        int getSize () {
            return size;
        }

    private:
        vector<vector<int>> adjMatrix;
        int size;
        void resizeMatrix(int newSize) {
            if(newSize > size) {
                //! no good, resize erases content
                //TODO fix
                adjMatrix.resize(newSize);
                for(int i = 0; i < newSize; i++)
                    adjMatrix[i].resize(newSize);
                size = newSize;
            }
        }
};

int main() {
    vector<int> start = {0, 1, 2, 3};
    Graph g(start);
    // cout << g.getSize() << endl;
    g.printAdjMat();
    g.addEdge(1, 2, 3);
    cout << endl << endl;
    g.printAdjMat();
    return 0;
}
