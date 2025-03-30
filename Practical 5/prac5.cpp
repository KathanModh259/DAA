#include <bits/stdc++.h>
using namespace std;

// Structure for Advertisement Slot
struct AdSlot
{
    double duration, price;
    AdSlot(double d, double p) : duration(d), price(p) {}
};

// Fractional Knapsack for Maximum Ad Revenue
bool compareAd(AdSlot a, AdSlot b)
{
    return (a.price / a.duration) > (b.price / b.duration);
}

double maximizeAdRevenue(vector<AdSlot> &ads, double availableTime)
{
    sort(ads.begin(), ads.end(), compareAd);
    double revenue = 0.0;
    for (auto &ad : ads)
    {
        if (availableTime >= ad.duration)
        {
            revenue += ad.price;
            availableTime -= ad.duration;
        }
        else
        {
            revenue += (ad.price / ad.duration) * availableTime;
            break;
        }
    }
    return revenue;
}

// Dijkstra's Algorithm for Shortest Emergency Response Time
const int INF = 1e9;
vector<pair<int, int>> adj[1001];

vector<int> dijkstra(int n, int start)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &[v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Kruskal’s Algorithm for Minimum Spanning Tree (Fiber Optic Network)
struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
};

vector<int> parent, rankSet;

int find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void unionSet(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b)
    {
        if (rankSet[a] < rankSet[b])
            swap(a, b);
        parent[b] = a;
        if (rankSet[a] == rankSet[b])
            rankSet[a]++;
    }
}

int kruskal(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end());
    parent.resize(n + 1);
    rankSet.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    int mstCost = 0, count = 0;
    for (auto &e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            unionSet(e.u, e.v);
            mstCost += e.weight;
            count++;
        }
    }
    return (count == n - 1) ? mstCost : -1;
}

int main()
{
    // Test for Ad Revenue Maximization
    vector<AdSlot> ads = {{10, 200}, {5, 100}, {20, 300}};
    double availableTime = 25;
    cout << "Maximum Ad Revenue: " << maximizeAdRevenue(ads, availableTime) << endl;

    // Test for Shortest Emergency Response Time
    int n = 5; // Number of nodes
    adj[1].push_back({2, 10});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 2});
    adj[4].push_back({5, 8});
    vector<int> distances = dijkstra(n, 1);
    cout << "Shortest Time to Emergency Location: " << distances[5] << endl;

    // Test for Kruskal's Algorithm (Minimum Spanning Tree)
    vector<Edge> edges = {{1, 2, 3}, {2, 3, 1}, {3, 4, 4}, {4, 5, 2}, {1, 5, 6}};
    cout << "Minimum Cost to Connect All Cities: " << kruskal(n, edges) << endl;

    return 0;
}
