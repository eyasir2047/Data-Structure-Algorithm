/*
Problem Statement: 
Suppose M mice are out on a field and there's a hungry
owl about to make a move. Further suppose there are H holes
scattered across the ground that the mice can hide in(each having 
a certain capacity).Assume every mouse is capable of running a radius
of r before being caught by the owl. What is the maximum number of mice that
can hide safety?
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <queue>

using namespace std;

const long long INF = numeric_limits<long long>::max() / 2;

struct Point2D {
    double x, y;
    Point2D(double x, double y) : x(x), y(y) {}
    double distance(const Point2D& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct Mouse {
    Point2D point;
    Mouse(int x, int y) : point(x, y) {}
};

struct Hole {
    int capacity;
    Point2D point;
    Hole(int x, int y, int cap) : point(x, y), capacity(cap) {}
};

struct Edge {
    int from, to;
    long long flow, capacity;
    Edge* residual;

    Edge(int from, int to, long long capacity) :
        from(from), to(to), flow(0), capacity(capacity), residual(nullptr) {}

    long long remainingCapacity() const {
        return capacity - flow;
    }

    void augment(long long bottleNeck) {
        flow += bottleNeck;
        residual->flow -= bottleNeck;
    }
};

class NetworkFlowSolverBase {
public:
    int n, s, t;
    vector<vector<Edge*>> graph;
    vector<Edge*> visited;
    long long maxFlow = 0;

    void addEdge(int from, int to, long long capacity) {
        Edge* e1 = new Edge(from, to, capacity);
        Edge* e2 = new Edge(to, from, 0);
        e1->residual = e2;
        e2->residual = e1;
        graph[from].push_back(e1);
        graph[to].push_back(e2);
    }

    virtual void solve() = 0;

public:
    NetworkFlowSolverBase(int n, int s, int t) : n(n), s(s), t(t), graph(n) {}
    virtual ~NetworkFlowSolverBase() {
        for (auto& edges : graph) {
            for (Edge* e : edges) {
                delete e;
            }
        }
    }

    long long getMaxFlow() {
        solve();
        return maxFlow;
    }
};

class FordFulkersonDfsSolver : public NetworkFlowSolverBase {
public:
    vector<int> visitedToken;

    long long dfs(int node, long long flow) {
        if (node == t) return flow;
        visitedToken[node]++;

        for (Edge* edge : graph[node]) {
            if (visitedToken[edge->to] != visitedToken[node] && edge->remainingCapacity() > 0) {
                long long bottleNeck = dfs(edge->to, min(flow, edge->remainingCapacity()));
                if (bottleNeck > 0) {
                    edge->augment(bottleNeck);
                    return bottleNeck;
                }
            }
        }
        return 0;
    }

public:
    void solve() override {
        visitedToken.assign(n, 0);
        for (long long f = dfs(s, INF); f != 0; f = dfs(s, INF)) {
            maxFlow += f;
            visitedToken.assign(n, 0);
        }
    }

public:
    FordFulkersonDfsSolver(int n, int s, int t) : NetworkFlowSolverBase(n, s, t) {}
};

void solve(const vector<Mouse>& mice, const vector<Hole>& holes, int radius) {
    int M = mice.size();
    int H = holes.size();
    int N = M + H + 2;
    int S = N - 1;
    int T = N - 2;

    FordFulkersonDfsSolver solver(N, S, T);

    // Source to mice
    for (int i = 0; i < M; i++) {
        solver.addEdge(S, i, 1);
    }

    // Connect mice with reachable holes
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < H; j++) {
            if (mice[i].point.distance(holes[j].point) <= radius) {
                solver.addEdge(i, M + j, 1);
            }
        }
    }

    // Holes to sink
    for (int i = 0; i < H; i++) {
        solver.addEdge(M + i, T, holes[i].capacity);
    }

    cout << "Number of safe mice: " << solver.getMaxFlow() << endl;
}

int main() {
    vector<Mouse> mice = {
        Mouse(1, 0), Mouse(0, 1), Mouse(8, 1),
        Mouse(12, 0), Mouse(12, 4), Mouse(15, 5)
    };
    vector<Hole> holes = {Hole(1, 1, 1), Hole(10, 2, 2), Hole(14, 5, 1)};
    solve(mice, holes, 3);
    return 0;
}
