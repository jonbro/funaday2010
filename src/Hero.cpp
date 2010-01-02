#include "Hero.h"

void Hero::draw(){
	ofSetColor(255, 255, 255);
	ofSetColor(182, 209, 221);
	float distOne = sin((ofGetElapsedTimeMillis()+offset)/200.0);
	float distTwo = 1.0-distOne;
	float rotOne = (ofGetElapsedTimeMillis()+offset)/50.0;
	for (int i=0; i<8; i++) {
		glPushMatrix();
		glTranslatef(pos.x, pos.y, 0);
		glRotatef(i*(360/8)+rotOne, 0, 0, 1);
		glTranslatef(0, distOne*10, 0);
		ofCircle(0, 0, 2);
		glPopMatrix();
	}	
	ofSetColor(0, 0, 0);
	for (int i=0; i<8; i++) {
		glPushMatrix();
		glTranslatef(pos.x, pos.y, 0);
		glRotatef(i*(360/8)-rotOne, 0, 0, 1);
		glTranslatef(0, distTwo*10, 0);
		ofCircle(0, 0, 2*(distTwo+1));
		glPopMatrix();
	}	
}
void Hero::onMouseMove(int x, int y){
	pos.x += x - lastMouse.x;
	pos.y += y - lastMouse.y;
	lastMouse.set(x, y, 0);
}
void Hero::onPress(int x, int y, int button){
	lastMouse.set(x, y, 0);
}