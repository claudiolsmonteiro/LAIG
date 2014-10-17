//
//  SceneGraph.cpp
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#include "SceneGraph.h"


Node::Node(char *n): name(n){
}

char *Node::getName(){
	return name;
}

void Node::addTransform(vector<float> t){
    this->transforms.push_back(t);
}

void Node::addPrimitive(Primitive p){
    this->primitives.push_back(p);
}

void Node::addDescendant(char *id){
    this->descendants.push_back(id);
}

void Node::setAppearance(char *a){
	this->appearance = a;
}
std::vector<Primitive> Node::getPrimitives(){
	return primitives;
}

std::vector<vector<float> > Node::getTransforms(){
	return transforms;
}

std::vector<char *> Node::getDescendants(){
	return descendants;
}

Node::~Node(){
    
}
SceneGraph::SceneGraph(){
}
SceneGraph::SceneGraph(char *r):root(r){
   
}

void SceneGraph::setRoot(char *id){
	this->root = id;
}

char *SceneGraph::getRoot(){
	return root;
}

void SceneGraph::addNode(Node n){
	nodes.push_back(n);
}

std::vector<Node> SceneGraph::getNodes(){
	return nodes;
}

SceneGraph::~SceneGraph(){		   
}
