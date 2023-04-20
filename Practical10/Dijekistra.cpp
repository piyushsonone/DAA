#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<pair<int, int> > *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int, int> >[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void dijkstra(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<int> dist(V, INT_MAX);

        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "Vertex Distance from Source\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 4);

    g.dijkstra(0);

    return 0;
}
