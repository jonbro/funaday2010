
#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	// touch events will be sent to testApp
	ofxMultiTouch.addListener(this);
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
	face.loadImage("face.png");
	ofEnableAlphaBlending();
	ofBackground(182,209,221);
}


//--------------------------------------------------------------
void testApp::update() {
}

//--------------------------------------------------------------
void testApp::draw() {
	for (int i=0; i<5; i++) {
		float colorOffset = 200.0*(1.0-(i/5.0));

		ofSetColor(0, colorOffset, 0);
		glPushMatrix();
		glTranslatef(ofGetWidth()/2.0, ofGetHeight()/2.0+40, 0);
		glRotatef(180, 0, 0, 1);
		
		float rotVal = 180*(i/5.0);
//		
		glRotatef(-rotVal*0.5, 0, 0, 1);

		glPushMatrix();
		glTranslatef(0, -40, 0);
		drawTentacle(i*80);
		glPopMatrix();
		
		glRotatef(rotVal, 0, 0, 1);
		glPushMatrix();
		glTranslatef(0, -40, 0);
		drawTentacle(i*80);
		glPopMatrix();

		glPopMatrix();
	}
	ofSetColor(255, 255, 255);
	face.draw(0, 0);

}

void testApp::drawTentacle(int periodOffset)
{
	// i is the number of curves in the tentacle
	for (int i=0; i<4; i++) {
		// j is the number of segments in each curve
		for (int j=0; j<10; j++) {
			// k is the number of vertexes in each circle
			glPushMatrix();
			static ofPoint currentPoint;
			static ofPoint curvePoint[4];
			
			// calculate the curve points
			float pointOffset;
			for (int l=0; l<4; l++) {
				pointOffset = ((i+l)*10+j)/(4*10);
				float degrees = (i+l)*120+(ofGetElapsedTimeMillis()/20.0)+periodOffset;
				curvePoint[l].set(sin(degrees*DEG_TO_RAD)*(30.0*pointOffset), (i+l)*60-50.0/(i+l), 0);
			}
			
			pointOnCurve(currentPoint, j/10.0, curvePoint[0], curvePoint[1], curvePoint[2], curvePoint[3]);
			glTranslatef(currentPoint.x, currentPoint.y, 0);
			pointOffset = (i*10.0+j)/(4.0*10.0);
			ofCircle(0, 0, 20.0*(1.0-pointOffset));
			glPopMatrix();
		}
	}	
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

void testApp::pointOnCurve(ofPoint &out, float t, ofPoint p0, ofPoint p1, ofPoint p2, ofPoint p3)
{
	float t2 = t * t;
	float t3 = t2 * t;
	out.x = 0.5f * ( ( 2.0f * p1.x ) +
					( -p0.x + p2.x ) * t +
					( 2.0f * p0.x - 5.0f * p1.x + 4 * p2.x - p3.x ) * t2 +
					( -p0.x + 3.0f * p1.x - 3.0f * p2.x + p3.x ) * t3 );
	out.y = 0.5f * ( ( 2.0f * p1.y ) +
					( -p0.y + p2.y ) * t +
					( 2.0f * p0.y - 5.0f * p1.y + 4 * p2.y - p3.y ) * t2 +
					( -p0.y + 3.0f * p1.y - 3.0f * p2.y + p3.y ) * t3 );
}
