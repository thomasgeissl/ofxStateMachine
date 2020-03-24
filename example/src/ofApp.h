#pragma once

#include "ofMain.h"
#include "ofxStateMachine.h"
#include "ofxStateEventArgs.h"

class ofApp : public ofBaseApp
{
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
	void onRedStateEntered(ofxStateEnteredEventArgs &args);
	void onGreenStateEntered(ofxStateEnteredEventArgs &args);
	void onBlueStateEntered(ofxStateEnteredEventArgs &args);
	void onPurpleStateEntered(ofxStateEnteredEventArgs &args);
	void onRedStateExited(ofxStateExitedEventArgs &args);
	void onGreenStateExited(ofxStateExitedEventArgs &args);
	void onBlueStateExited(ofxStateExitedEventArgs &args);
	void onPurpleStateExited(ofxStateExitedEventArgs &args);

private:
	ofEvent<string> _actionEvent;
	ofxStateMachine _stateMachine;
	ofxState::pointer _redState;
	ofxState::pointer _greenState;
	ofxState::pointer _blueState;
	ofxState::pointer _purpleState;

	ofParameterGroup _parameters;
	ofParameter<ofColor> _backgroundColorParameter;
	ofImage _graph;
};
