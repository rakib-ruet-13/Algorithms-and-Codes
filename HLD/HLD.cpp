#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define root 0
#define N 101000
#define Max 101000

#define LN 17


vector <int> adj[Max], costs[Max], indexx[Max];
int baseArray[Max], ptr;
int chainNo, chainInd[Max], chainHead[Max], posInBase[Max];
int depth[Max], pa[LN][Max], otherEnd[Max], subsize[Max];
int T[4*Max+4];



///*****[L,R) format , root starts with 1*****//

void build(int id = 1,int l = 0,int r = N){
	if(r - l < 2){
		T[id] = baseArray[l];
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = max(T[2 * id] , T[2 * id + 1]);
}

void update(int p,int id = 1,int l = 0,int r = ptr,int val=0){
	if(r - l < 2){
		T[id] = val;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid,val);
	else
		update(p, 2 * id + 1, mid, r,val);
	T[id] = max(T[2 * id] , T[2 * id + 1]);
}




int ask(int x,int y,int id = 1,int l = 0,int r = ptr){// [x, y)
	if(x >= r or l >= y)	return -1e9;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return T[id];
	int mid = (l + r)/2;
	return max(ask(x, y, id * 2, l, mid) ,ask(x, y, id*2+1, mid, r)) ;
}


/******* u is chiled and v is parent in the chain ***/
int query_up(int u, int v) {
	if(u == v) return 0;
	int uchain, vchain = chainInd[v], ans = -1;

	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {  /*** u and v on the same chain **/
			if(u==v) break;
			int temp=ask(posInBase[v]+1, posInBase[u]+1,1,0,ptr); /** we need not include the top node as edge value is in child **/
			if(temp > ans) ans = temp;
			break;
		}
		int tmp= ask(posInBase[chainHead[uchain]], posInBase[u]+1,1,0,ptr);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		if(tmp > ans) ans = tmp;
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}

	return ans;
}

/*
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */

void sparse_table_gen(int node)
{
    for(int i=1; i<LN; i++)
			for(int j=0; j<node; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
}


int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void query(int u, int v) {
	/*
	 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	int lca = LCA(u, v);
	int ans = query_up(u, lca);
	int temp = query_up(v, lca);
	if(temp > ans) ans = temp;
	printf("%d\n", ans);
}

/*** chane the value of a node**/
void change(int i, int val) {
	int u = otherEnd[i];
	update(posInBase[u],1,0,ptr,val);
}

/*** all are 0 indexed where last value ptr is the N of segment tree**/
void HLD(int curNode, int cost, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;

	int sc = -1, ncost;
	// Loop to find special child
	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, ncost, curNode);
	}

	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}

void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(int i=0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

void preprocess()
{
    ptr = 0;
    chainNo = 0;
    for(int i=0; i<Max; i++) {
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			for(int j=0; j<LN; j++) pa[j][i] = -1;
    }

}

void make_ready(int node)
{
        dfs(root, -1);
		HLD(root, -1, -1);
		sparse_table_gen(node);
		build(1,0,ptr);

}

int main() {

	int tc;
	scanf("%d ", &tc);

	for(int cs=1; cs<=tc; cs++)
    {

        preprocess();

		int node;
		scanf("%d", &node);

		for(int i=1; i<node; i++)
        {

			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);

			u--; v--;
			adj[u].push_back(v);
			costs[u].push_back(c);
			indexx[u].push_back(i-1);

			adj[v].push_back(u);
			costs[v].push_back(c);
			indexx[v].push_back(i-1);
		}

		make_ready(node);

		while(1)
        {
			char s[100];
			scanf("%s", s);

			if(s[0]=='D')break;

			int a, b;
			scanf("%d %d", &a, &b);

			if(s[0]=='Q')
				query(a-1, b-1);
			else
				change(a-1, b);

		}
	}

	return 0;
}
