//DATE: 12/08/14
//ASSIGNMENT: Project 8
//FILE: edgenode.h
//DESC: Definition and implementation of class EdgeNode, an object of this class represents one edge of a graph object

#ifndef EDGENODE_H
#define EDGENODE_H

class EdgeNode{

public:

    EdgeNode(int vnum) { vertex_num = vnum; }
    void setvnum(int vnum) { vertex_num = vnum; }
    int getvnum() const{ return vertex_num; }
    bool operator==(const EdgeNode &obj) { return vertex_num == obj.vertex_num; }

private:

    int vertex_num; //vertext target
};
#endif
