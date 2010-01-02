
#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	// touch events will be sent to testApp
	ofxMultiTouch.addListener(this);
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
	
	ofBackground(182,209,221);
	hero.setSize(ofGetWidth(), ofGetHeight());
	hero.pos.set(102, 180, 0);
	heroTwo.setSize(ofGetWidth(), ofGetHeight());
	heroTwo.pos.set(214, 185, 0);
	person.loadImage("person.png");
}


//--------------------------------------------------------------
void testApp::update() {
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(182, 209, 221);
	ofRect(0, 0, ofGetWidth(), ofGetWidth());
	ofSetColor(255, 255, 255);
	person.draw(0, 0);
}


void testApp::exit() {
}


//--------------------------------------------------------------
void testApp::touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data){
	static ofMouseEventArgs mouseEventArgs;
	#ifdef OF_USING_POCO
		mouseEventArgs.x = x;
		mouseEventArgs.y = y;
		mouseEventArgs.button = touchId;
		ofNotifyEvent( ofEvents.mousePressed, mouseEventArgs );
	#endif
}

//--------------------------------------------------------------
void testApp::touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data){
	static ofMouseEventArgs mouseEventArgs;
	#ifdef OF_USING_POCO
		mouseEventArgs.x = x;
		mouseEventArgs.y = y;
		mouseEventArgs.button = touchId;
		ofNotifyEvent( ofEvents.mouseMoved, mouseEventArgs );
	#endif
}

//--------------------------------------------------------------
void testApp::touchUp(float x, float y, int touchId, ofxMultiTouchCustomData *data){
	static ofMouseEventArgs mouseEventArgs;
#ifdef OF_USING_POCO
	mouseEventArgs.x = x;
	mouseEventArgs.y = y;
	mouseEventArgs.button = touchId;
	ofNotifyEvent( ofEvents.mouseReleased, mouseEventArgs );
#endif
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(float x, float y, int touchId, ofxMultiTouchCustomData *data){
}

//--------------------------------------------------------------
void testApp::lostFocus() {
}

//--------------------------------------------------------------
void testApp::gotFocus() {
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning() {
}

