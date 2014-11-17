//
//  SceneGraph.h
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#ifndef _SceneGraph_h_
#define _SceneGraph_h_

#include <stdio.h>
#include "primitives.h"
#include <vector>
#include <map>
#include "myAppearance.h"

class Node{
public:
	Node(){};
    Node(char *n,bool displaylist);
	string getName();
    void addTransform(vector<float> t);
    void addPrimitive(Primitive p);
    void addDescendant(char *d);
	void setAppearance(char *a);
	std::vector<Primitive> getPrimitives();
	std::vector<float> getTransform();
	std::vector<vector<float> > getTransforms();
	void calcTransform();
	std::vector<string> getDescendants();
	string getAppearance();
	bool isDisplayList();
    void setDisplayList(bool b);
    GLuint dlist;
    ~Node();
private:

    string name, appearance;
	bool displaylist;
    std::vector<vector<float> > transforms;
	std::vector<float> transform;
    std::vector<Primitive> primitives;
    std::vector<string> descendants;
};

class SceneGraph{
public:
	SceneGraph();
    SceneGraph(char *r);
	void setRoot(char *id);
	string getRoot();
    void addNode(Node n);
	std::vector<Node> getNodes();
    ~SceneGraph();
private:
    string root;
    std::vector<Node> nodes;
};

#endif /* defined(__CGFExample__SceneGraph__) */
