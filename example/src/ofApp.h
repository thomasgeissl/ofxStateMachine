#pragma once

#include "ofMain.h"
#include "ofxStateMachine.h"

class ofApp : public ofBaseApp {
	public:
		ofApp();
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		void onRedStateEntered(ofxState * const & value);
		void onGreenStateEntered(ofxState * const & value);
		void onBlueStateEntered(ofxState * const & value);
		void onPurpleStateEntered(ofxState * const & value);
		void onRedStateExited(ofxState * const & value);
		void onGreenStateExited(ofxState * const & value);
		void onBlueStateExited(ofxState * const & value);
		void onPurpleStateExited(ofxState * const & value);

	private:
		ofEvent <string> _actionEvent;
		ofxStateMachine _stateMachine;
		ofxState * _redState;
		ofxState * _greenState;
		ofxState * _blueState;
		ofxState * _purpleState;

		ofParameterGroup _parameters;
		ofParameter <ofColor> _backgroundColorParameter;
		ofImage _graph;

};
