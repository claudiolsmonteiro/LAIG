//
//  SceneGraph.cpp
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#include "SceneGraph.h"


vector<float> multmatrix(vector<float> a, vector<float> b){

	float ma[4][4] = {{a[0],a[1],a[2],a[3]},
						{a[4],a[5],a[6],a[7]},
						{a[8],a[9],a[10],a[11]},
						{a[12],a[13],a[14],a[15]}};

	float mb[4][4] = {{b[0],b[1],b[2],b[3]},
						{b[4],b[5],b[6],b[7]},
						{b[8],b[9],b[10],b[11]},
						{b[12],b[13],b[14],b[15]}};

	float mf[4][4] = {0};

	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			for (int k=0;k<4;k++){
				mf[i][j]+=ma[i][k]*mb[k][j];
			}
		}
	}
	vector<float> ret;
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			ret.push_back(mf[i][j]);
		}
	}
	return ret;
}

Node::Node(char *n){
	string s(n);
	this->name = s;
}

string Node::getName(){
	return name;
}

void Node::addTransform(vector<float> t){
    this->transforms.push_back(t);
}

void Node::addPrimitive(Primitive p){
    this->primitives.push_back(p);
}

void Node::addDescendant(char *id){
	string s(id);
    this->descendants.push_back(s);
}

void Node::addAnimation(Animation *a){
	this->animations.push_back(a);
}

void Node::setAppearance(char *a){
	string s(a);
	this->appearance = s;
}
std::vector<Primitive> Node::getPrimitives(){
	return primitives;
}

float* Node::getTransform(){
	return transform;
}

std::vector<vector<float> > Node::getTransforms(){
	return transforms;
}

std::vector<Animation *> Node::getAnimations(){
	return animations;
}

void Node::calcTransform(){
	if(this->transforms.size() == 0){
		this->transform[0] = 1;
		this->transform[1] = 0;
		this->transform[2] = 0;
		this->transform[3] = 0;
		this->transform[4] = 0;
		this->transform[5] = 1;
		this->transform[6] = 0;
		this->transform[7] = 0;
		this->transform[8] = 0;
		this->transform[9] = 0;
		this->transform[10] = 1;
		this->transform[11] = 0;
		this->transform[12] = 0;
		this->transform[13] = 0;
		this->transform[14] = 0;
		this->transform[15] = 1;
		return;
	}

	if(this->transforms.size() == 1){
		this->transform[0] = this->transforms[0][0];
		this->transform[1] = this->transforms[0][4];
		this->transform[2] = this->transforms[0][8];
		this->transform[3] = this->transforms[0][12];
		this->transform[4] = this->transforms[0][1];
		this->transform[5] = this->transforms[0][5];
		this->transform[6] = this->transforms[0][9];
		this->transform[7] = this->transforms[0][13];
		this->transform[8] = this->transforms[0][2];
		this->transform[9] = this->transforms[0][6];
		this->transform[10] = this->transforms[0][10];
		this->transform[11] = this->transforms[0][14];
		this->transform[12] = this->transforms[0][3];
		this->transform[13] = this->transforms[0][7];
		this->transform[14] = this->transforms[0][11];
		this->transform[15] = this->transforms[0][15];
		return;
	}
	vector<float> m = this->transforms[0];
	for(unsigned int j = 1; j < this->transforms.size(); j++) {

		m = multmatrix(m, this->transforms[j]);
	}
	this->transform[0] = m[0];
	this->transform[1] = m[4];
	this->transform[2] = m[8];
	this->transform[3] = m[12];
	this->transform[4] = m[1];
	this->transform[5] = m[5];
	this->transform[6] = m[9];
	this->transform[7] = m[13];
	this->transform[8] = m[2];
	this->transform[9] = m[6];
	this->transform[10] = m[10];
	this->transform[11] = m[14];
	this->transform[12] = m[3];
	this->transform[13] = m[7];
	this->transform[14] = m[11];
	this->transform[15] = m[15];
}

std::vector<string> Node::getDescendants(){
	return descendants;
}

string Node::getAppearance(){
	return appearance;
}

Node::~Node(){
    
}


SceneGraph::SceneGraph(){
}
SceneGraph::SceneGraph(char *r){
   string s(r);
   this->root = s;
}

void SceneGraph::setRoot(char *id){
	string s(id);
	this->root = s;
}

string SceneGraph::getRoot(){
	return root;
}

void SceneGraph::addNode(Node* n){
	nodes[n->getName()] = n;
}

SceneGraph::~SceneGraph(){		   
}
