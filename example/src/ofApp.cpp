#include "ofApp.h"
ofApp::ofApp() :
	_redState(new ofxState("red")),
	_greenState(new ofxState("green")),
	_blueState(new ofxState("blue")),
	_purpleState(new ofxState("purple")){
	_graph.load("graph.png");

	_stateMachine.setInitialState(_redState);
	_stateMachine.addTransition(_redState, "a", _greenState);
	_stateMachine.addTransition(_redState, "b", _blueState);
	_stateMachine.addTransition(_redState, "c", _purpleState);
	_stateMachine.addTransition(_greenState, "a", _redState);
	_stateMachine.addTransition(_greenState, "b", _blueState);
	_stateMachine.addTransition(_blueState, "a", _redState);
	_stateMachine.addTransition(_blueState, "b", _greenState);
	_stateMachine.addTransition(_purpleState, "c", _blueState);

	_parameters.setName("Parameters");
	_backgroundColorParameter.set("Background color", ofColor::red);
	_parameters.add(_backgroundColorParameter);

	_redState->addEnteredListener(this, &ofApp::onRedStateEntered);
	_redState->addExitedListener(this, &ofApp::onRedStateExited);
	_greenState->addEnteredListener(this, &ofApp::onGreenStateEntered);
	_greenState->addExitedListener(this, &ofApp::onGreenStateExited);
	_blueState->addEnteredListener(this, &ofApp::onBlueStateEntered);
	_blueState->addExitedListener(this, &ofApp::onBlueStateExited);
	_purpleState->addEnteredListener(this, &ofApp::onPurpleStateEntered);
	_purpleState->addExitedListener(this, &ofApp::onPurpleStateExited);

//	ofAddListener(_redState->_enteredEvent, this, &ofApp::onRedStateEntered);
//	ofAddListener(_greenState->_enteredEvent, this, &ofApp::onGreenStateEntered);
//	ofAddListener(_blueState->_enteredEvent, this, &ofApp::onBlueStateEntered);

//	ofAddListener(_redState->_exitedEvent, this, &ofApp::onRedStateExited);
//	ofAddListener(_greenState->_exitedEvent, this, &ofApp::onGreenStateExited);
//	ofAddListener(_blueState->_exitedEvent, this, &ofApp::onBlueStateExited);

	ofAddListener(_actionEvent, &_stateMachine, &ofxStateMachine::onActionEvent);
	_stateMachine.start();
}

void ofApp::setup(){
}

void ofApp::update(){
}

void ofApp::draw(){
	ofBackground(_backgroundColorParameter.get());
	_graph.draw(ofGetWidth() / 3, ofGetHeight() / 3, ofGetWidth() / 3, ofGetHeight() / 3);
}

void ofApp::keyPressed(int key){
	string action;
	switch(key){
	 case 'a':
		 //_stateMachine.transit("a"); break;
		 action = "a";
		 ofNotifyEvent(_actionEvent, action);
		 break;

	 case 'b':
		 //_stateMachine.transit("b"); break;
		 action = "b";
		 ofNotifyEvent(_actionEvent, action);
		 break;

	 case 'c':
		 //_stateMachine.transit("c"); break;
		 action = "c";
		 ofNotifyEvent(_actionEvent, action);
		 break;

	 case ' ':
		 if(_stateMachine.isRunning()){
			 _stateMachine.stop();
		 }else{
			 _stateMachine.start();
		 }
	}
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::dragEvent(ofDragInfo dragInfo){

}
void ofApp::gotMessage(ofMessage msg){

}
void ofApp::onRedStateEntered(ofxStateEnteredEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state entered, previous state: " << args._fromState->getName();
	_backgroundColorParameter = ofColor::red;
}
void ofApp::onGreenStateEntered(ofxStateEnteredEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state entered, previous state: " << args._fromState->getName();
	_backgroundColorParameter = ofColor::green;
}
void ofApp::onBlueStateEntered(ofxStateEnteredEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state entered, previous state: " << args._fromState->getName();
	_backgroundColorParameter = ofColor::blue;
}
void ofApp::onPurpleStateEntered(ofxStateEnteredEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state entered, previous state: " << args._fromState->getName();
	_backgroundColorParameter = ofColor(255, 0, 255);
}
void ofApp::onRedStateExited(ofxStateExitedEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state exited, next state: " << args._toState->getName();
}
void ofApp::onGreenStateExited(ofxStateExitedEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state exited, next state: " << args._toState->getName();
}
void ofApp::onBlueStateExited(ofxStateExitedEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state exited, next state: " << args._toState->getName();
}
void ofApp::onPurpleStateExited(ofxStateExitedEventArgs & args){
	ofLogNotice("ofApp") << args._currentState->getName() << " state exited, next state: " << args._toState->getName();
}
