//
//  SceneGraph.h
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#ifndef _SceneGraph_h_
#define _SceneGraph_h_

#include "primitives.h"
#include <stdio.h>

#include <vector>
#include <map>
#include "myAppearance.h"
#include "Animation.h"

class Node{
public:
	Node(){};
    Node(char *n);
	string getName();
    void addTransform(vector<float> t);
    void addPrimitive(Primitive p);
    void addDescendant(char *d);
	void setAppearance(char *a);
	void addAnimation(Animation *a);
	std::vector<Primitive> getPrimitives();
	float* getTransform();
	std::vector<vector<float> > getTransforms();
	std::vector<Animation *> getAnimations();
	void calcTransform();
	std::vector<string> getDescendants();
	string getAppearance();
	bool isDisplayList();
    void setDisplayList(bool b);
    ~Node();
private:
    string name, appearance;
    std::vector<vector<float> > transforms;
	float transform[16];
    std::vector<Primitive> primitives;
    std::vector<string> descendants;
	std::vector<Animation *> animations;
};

class SceneGraph{
public:
	SceneGraph();
    SceneGraph(char *r);
	void setRoot(char *id);
	string getRoot();
    void addNode(Node* n);
	std::map<std::string, Node*> nodes;
    ~SceneGraph();
private:
    string root;
    
};

#endif /* defined(__CGFExample__SceneGraph__) */
