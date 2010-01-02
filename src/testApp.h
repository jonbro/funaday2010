#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "eventsObject.h"
#include "Hero.h"

class testApp : public ofxiPhoneApp {
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data);
	void touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data);
	void touchUp(float x, float y, int touchId, ofxMultiTouchCustomData *data);
	void touchDoubleTap(float x, float y, int touchId, ofxMultiTouchCustomData *data);
	
	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void pointOnCurve(ofPoint &out, float t, ofPoint p0, ofPoint p1, ofPoint p2, ofPoint p3);
	void drawTentacle(int periodOffset);
	ofImage face;
}; 

