#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> Node;

int group[10000];
int groupCnt[10000];

struct comp {
	bool operator()(Node x, Node y)
	{
		if (x.second != y.second) return x.second > y.second;
		if (x.first.first != y.first.first) return x.first.first > y.first.first;
		return x.first.second > y.first.second;
	}
};

int findBoss(int x)
{
	if (group[x] == x) return x;
	return findBoss(group[x]);
}

int setUnion(int x, int y)
{
	int xBoss = findBoss(x);
	int yBoss = findBoss(y);
	if (xBoss == yBoss) return 0;
	group[yBoss] = xBoss;
	group[xBoss] = xBoss;
	groupCnt[xBoss]++;
	groupCnt[yBoss]--;

	return 1;
}

int main() {
	priority_queue<Node, vector<Node>, comp> q;
	int V, E, ret = 0;
	cin >> V >> E;
	for (int i = 0, A, B, C; i < E; i++)
	{
		cin >> A >> B >> C;
		q.push({ {A, B}, C });
		group[A] = A;
		group[B] = B;
		groupCnt[A] = 1;
		groupCnt[B] = 1;
	}
	
	while (!q.empty())
	{
		Node now = q.top();
		q.pop();

		int s = now.first.first;
		int e = now.first.second;
		int w = now.second;

		if (!setUnion(s, e)) continue; // 사이클 존재시 버림
		ret += w;
		if (groupCnt[s] == V) break;
	}

	cout << ret;

	return 0;
}