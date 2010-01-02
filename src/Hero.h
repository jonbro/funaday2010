#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

class Hero : public ofxMSAInteractiveObject {
public:
	void setup() {
		enableMouseEvents();
		offset = ofRandom(0, 1000);
	}
	void draw();
	virtual void onMouseMove(int x, int y);
	virtual void onPress(int x, int y, int button);
	ofPoint pos, lastMouse;
	int offset;
};