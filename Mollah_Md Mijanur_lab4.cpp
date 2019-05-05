#include <iostream>

using namespace std;

struct s
{
  int p, r;  
};

int f(struct s ss[], int x) 
{ 
    if (ss[x].p != x) 
        ss[x].p = f(ss, ss[x].p); 
    return ss[x].p; 
} 

void U(struct s ss[], int a, int b) 
{ 
    int ar = f(ss, a); 
    int br = f(ss, b); 
  
    if (ss[ar].r > ss[br].r) 
         ss[br].p = ar;
    else if (ss[ar].r < ss[br].r) 
         ss[ar].p = br;
    else
    { 
        ss[ar].r++;
        ss[br].p = ar; 
    } 
} 

struct Edge 
{ 
    int weight; 
    int source; 
    int destination;
};

struct Graph 
{ 
    struct Edge* ed;
    int Enum; 
    int Vnum;
}; 

struct Graph* createGraph(int Vnum, int Enum) 
{ 
    struct Graph* graph = new Graph; 
    graph->ed = new Edge[Enum]; 
    graph->Enum = Enum; 
    graph->Vnum = Vnum; 
    return graph; 
} 

int mc(const void* x, const void* y) 
{ 
    struct Edge* y1 = (struct Edge*)y; 
    struct Edge* x1 = (struct Edge*)x;
    return x1->weight > y1->weight; 
} 

void mst(struct Graph* g) 
{ 
    int a = 0;  
    int b = 0;  
    int num = g->Vnum; 
    struct Edge res[num];   
    struct s *ss = (struct s*) malloc(num * sizeof(struct s)); 
  
    int n = 0;
    while (n < num) 
    { 
        ss[n].p = n; 
        ss[n].r = 0; 
        ++n;
    } 
    
    qsort(g->ed, g->Enum, sizeof(g->ed[0]), mc);
    
    while (a < num - 1)
    { 
        struct Edge n_e = g->ed[b++]; 
        int d = f(ss, n_e.destination);
        int c = f(ss, n_e.source); 
         
        if (c != d) 
        { 
            U(ss, c, d);
            res[a++] = n_e; 
        } 
    } 
  
    printf("The edges in the minimum spanning tree are:\n"); 
    int s = 0;
    int sum = 0;
    while (s < a) { 
        printf("%d -- %d == %d\n", res[s].source, res[s].destination, res[s].weight);
        sum += res[s].weight;
        ++s;
    }
    printf("Total weight is %d\n", sum);
    return; 
} 

int main(void){
    int V = 4; 
    int E = 5;
    struct Graph* graph = createGraph(V, E); 
  
    graph->ed[0].source = 0; 
    graph->ed[0].destination = 1; 
    graph->ed[0].weight = 5; 
  
    graph->ed[1].source = 0; 
    graph->ed[1].destination = 2; 
    graph->ed[1].weight = 3; 
  
    graph->ed[2].source = 0; 
    graph->ed[2].destination = 3; 
    graph->ed[2].weight = 2;
    
    graph->ed[3].source = 1; 
    graph->ed[3].destination = 3; 
    graph->ed[3].weight = 7; 
  
    graph->ed[4].source = 2; 
    graph->ed[4].destination = 3; 
    graph->ed[4].weight = 2; 
  
    mst(graph); 
    
    printf("\n");
    
    V = 4;
    E = 4;
    struct Graph* graphs = createGraph(V, E);
       
    graphs->ed[0].source = 0; 
    graphs->ed[0].destination = 2; 
    graphs->ed[0].weight = 2; 
  
    graphs->ed[1].source = 0; 
    graphs->ed[1].destination = 3; 
    graphs->ed[1].weight = 1;
    
    graphs->ed[2].source = 2; 
    graphs->ed[2].destination = 3; 
    graphs->ed[2].weight = 1;
    
    graphs->ed[3].source = 1; 
    graphs->ed[3].destination = 3; 
    graphs->ed[3].weight = 3; 
    
    mst(graphs);
    
    return 0; 
    
}
