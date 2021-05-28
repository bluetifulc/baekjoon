#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Vertex{
public:
    Vertex *prev, *next;
    int num;
    Vertex(int n){
        num = n;
        prev = nullptr;
        next = nullptr;
    }
    Vertex(){
        Vertex(-1);
    }
};
class Edge{
public:
    Vertex *start, *end;
    Edge *prev, *next;
    Edge(){
     start = end = nullptr;
     prev = next = nullptr;
    }
    Edge(Vertex* start, Vertex* end){
        this->start = start;
        this->end = end;
        prev = next = nullptr;
    }
};

class VertexList{
public:
    Vertex *header, *trailer;
    VertexList() {
        header = new Vertex();
        trailer = new Vertex();
        header->next = trailer;
        trailer->prev = header;
    }
    void insert(Vertex* newv){
        trailer->prev->next = newv;
        trailer->prev = newv;
        newv->prev = trailer->prev;
        newv->next = trailer;
    }
    void remove(Vertex* newv){
        newv->prev->next = newv->next;
        newv->next->prev = newv->prev;
        delete newv;
    }
};
class EdgeList{
public:
    Edge *header, *trailer;
    EdgeList() {
        header = new Edge();
        trailer = new Edge();
        header->next = trailer;
        trailer->prev = header;
    }
    void insert(Edge* newv){
        trailer->prev->next = newv;
        trailer->prev = newv;
        newv->prev = trailer->prev;
        newv->next = trailer;
    }
    void remove(Edge* newv){
        newv->prev->next = newv->next;
        newv->next->prev = newv->prev;
        delete newv;
    }
};
class Graph{
public:
    Edge*** matrix;
    VertexList *V;
    EdgeList *E;
    int capa;
    Graph(){
        matrix = nullptr;
        V = new VertexList();
        E = new EdgeList();
        capa = 0;
    }
    void insertV(int vid){
        Vertex* newv = new Vertex(vid);
        Edge*** newm = new Edge**[++capa];
        for(int i = 0; i < capa; ++i){
            newm[i] = new Edge*[capa];
            newm[i][capa-1] = newm[capa-1][i] = nullptr;
        }
        for(int i = 0; i < capa-1; ++i){
            for(int j = 0; j < capa-1; ++j){
                newm[i][j] = matrix[i][j];
            }
        }
        for(int i = 0; i < capa-1; ++i){
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = newm;
        V->insert(newv);
    }
};
int main(){

}