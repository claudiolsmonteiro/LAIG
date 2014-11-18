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

Node::Node(char *n,bool displaylist){
	string s(n);
	this->name = s;
	this->displaylist = displaylist;
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

void Node::setAppearance(char *a){
	string s(a);
	this->appearance = s;
}
std::vector<Primitive> Node::getPrimitives(){
	return primitives;
}

std::vector<float> Node::getTransform(){
	return transform;
}

std::vector<vector<float> > Node::getTransforms(){
	return transforms;
}

void Node::calcTransform(){

	float final[16] = {0};
	float inicial[16];
	inicial[0] = 1;
	inicial[4] = 0;
	inicial[8] = 0;
	inicial[12] = 0;
	inicial[1] = 0;
	inicial[5] = 1;
	inicial[9] = 0;
	inicial[13] = 0;
	inicial[2] = 0;
	inicial[6] = 0;
	inicial[10] = 1;
	inicial[14] = 0;
	inicial[3] = 0;
	inicial[7] = 0;
	inicial[11] = 0;
	inicial[15] = 1;

	if(this->transforms.size() == 1){
		this->transform = this->transforms[0];
		return;
	}

	for(unsigned int j = 0; j < this->transforms.size()-1; j++) {

		vector<float> m = multmatrix(this->transforms[j], this->transforms[j+1]);
	}

}

std::vector<string> Node::getDescendants(){
	return descendants;
}

string Node::getAppearance(){
	return appearance;
}

bool Node::isDisplayList(){
	return displaylist;
}

void Node::setDisplayList(bool b){
    this->displaylist= b;
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

void SceneGraph::addNode(Node n){
	nodes.push_back(n);
}

std::vector<Node> SceneGraph::getNodes(){
	return nodes;
}

SceneGraph::~SceneGraph(){		   
}
