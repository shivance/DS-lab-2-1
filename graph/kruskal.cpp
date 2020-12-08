//Kruskal

#include <bits/stdc++.h>

using namespace std;

class Gnode{
public:
    int wt;
    bool flg;
    Gnode(){
        wt = INT_MAX;
        flg = false;
    }
};

class Edge{
public:
    int u,v,wt;
    Edge(int u,int v,int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Minheap
{
    Edge**harr;
    int capacity, heap_size;

public:
    // constructor
    Minheap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new Edge*[cap];
    }

    void swap(Edge**x,  Edge**y)
    {
        Edge* temp = *x;
        *x = *y;
        *y = temp;
    }

    //To heapify a subtree with root ar given index
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l]->wt < harr[i]->wt)
            smallest = l;
        if (r < heap_size && harr[r]->wt < harr[i]->wt)
            smallest = r;

        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            heapify(smallest);
        }
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    Edge* extractMin()
    {
        if (heap_size <= 0)
            return NULL;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        Edge* root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        heapify(0);

        return root;
    }

    Edge* getMin(){
        return harr[0];
    }

    int getsize()
    {
        return heap_size;
    }

    void insertKey(Edge* k)
    {
        if (heap_size == capacity)
        {
            //cout << "Heap overflow\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)]->wt > harr[i]->wt)
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }
};

class setNode{
public:
    int ht,par;
    setNode(){
        par=-1; // self rooted 
        ht = 0; // elements in subtree = 0
    }
};

int Find(vector<setNode*>&vec,int i){
    while(vec[i]->par!=-1){
        i=vec[i]->par;
    }
    return i;
}

void Union(vector<setNode*>&set,int i,int j){
    // merge set of j into i

    int i_id = Find(set,i);
    int j_id = Find(set,j);

    // if same set
    if (i_id == j_id) return;

    // if height(tree of i) > height(tree of j)
    // hang tree of j in
    if (set[i_id]->ht>set[j_id]->ht){
        set[j_id]->par = i_id;  
    }
    

    else {
        set[i_id]->par = j_id;
        if(set[i_id]->ht==set[j_id]->ht)
            set[j_id]->ht++;
    }
}


void printparNht(vector<setNode*> &vec)
{
    cout<<"Parent  : ";
    for (int i=1;i<vec.size();++i){
        cout<<vec[i]->par<<" ";
    }
    cout<<"\nHeights : ";
    for (int i=1;i<vec.size();++i){
        cout<<vec[i]->ht<<" ";
    }
    cout<<"\n";
}



void addEdge(vector<vector<Gnode*> >&G,int u,int v,int wt){
    G[u][v]->wt = wt;
    G[v][u]->wt = wt;
}

void makeGraph(vector<vector<Gnode*> >&mat,Minheap H){
    int u,v,wt;
    while(true){
        cin>>u;
        if(u==-1) return;
        cin>>v;
        addEdge(mat,u,v);
        Edge* edge = new Edge(u,v,wt);
        H.insertKey(edge);
    }
}

void DFS(vector<vector<Gnode*> >G,int src)
{
    cout<<src<<" ";

    for (int i=1;i<G.size();++i){
        if (G[src][i]->flg)
            DFS(G,i);
    }
}

int main(){

    int n;//no of vertex
    cin>>n;
    
    vector<vector<Gnode*> > G(n+1,vector<Gnode*>(n+1,new Gnode()));
    Minheap H(n);
    makeGraph(G,H);

    //DSU
    vector<setNode*> set(n+1,NULL);

    for(int i=1;i<set.size();++i)
        set[i] = new setNode();

    int hook = H.getMin()->u;

    Edge* e = H.extractMin();
    G[e->u][e->v]->flg = true;
    //Union(set,hook,)

    int cnt = 0;
    while(cnt!=n && H.getsize()>0){
        e = H.extractMin();
        if (Find(set,e->v)==Find(set,e->u)!=-1)
            continue;
        else{
            ++cnt;
            G[e->u][e->v]->flg =true;
        }
    }

    DFS(G,hook);
    

    return 0;
}