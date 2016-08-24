#include "ofApp.h"
ofApp::ofApp() :
	_redState(new ofxState()),
	_greenState(new ofxState()),
	_blueState(new ofxState()),
	_purpleState(new ofxState()){
	_graph.load("graph.png");

<<<<<<< HEAD

=======
>>>>>>> 35bdf20e403a2a0a8bcaee8c7f33d3ea41d226cf
	_stateMachine.setInitialState(_redState)
	->addTransition(_redState, "a", _greenState)
	->addTransition(_redState, "b", _blueState)
	->addTransition(_redState, "c", _purpleState)
	->addTransition(_greenState, "a", _redState)
	->addTransition(_greenState, "b", _blueState)
	->addTransition(_blueState, "a", _redState)
	->addTransition(_blueState, "b", _greenState)
	->addTransition(_purpleState, "c", _blueState);

	_parameters.setName("Parameters");
	_backgroundColorParameter.set("Background color", ofColor::red);
	_parameters.add(_backgroundColorParameter);

	_redState
	->addEnteredListener(this, &ofApp::onRedStateEntered)
	->addExitedListener(this, &ofApp::onRedStateExited);
	_greenState
	->addEnteredListener(this, &ofApp::onGreenStateEntered)
	->addExitedListener(this, &ofApp::onGreenStateExited);
	_blueState
	->addEnteredListener(this, &ofApp::onBlueStateEntered)
	->addExitedListener(this, &ofApp::onBlueStateExited);
	_purpleState
	->addEnteredListener(this, &ofApp::onPurpleStateEntered)
	->addExitedListener(this, &ofApp::onPurpleStateExited);
	/*
	ofAddListener(_redState->_enteredEvent, this, &ofApp::onRedStateEntered);
	ofAddListener(_greenState->_enteredEvent, this, &ofApp::onGreenStateEntered);
	ofAddListener(_blueState->_enteredEvent, this, &ofApp::onBlueStateEntered);

	ofAddListener(_redState->_exitedEvent, this, &ofApp::onRedStateExited);
	ofAddListener(_greenState->_exitedEvent, this, &ofApp::onGreenStateExited);
	ofAddListener(_blueState->_exitedEvent, this, &ofApp::onBlueStateExited);
	*/

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
void ofApp::onRedStateEntered(ofxState * const & value){
	ofLogNotice("ofApp") << "red state entered";
	_backgroundColorParameter = ofColor::red;
}
void ofApp::onGreenStateEntered(ofxState * const & value){
	ofLogNotice("ofApp") << "green state entered";
	_backgroundColorParameter = ofColor::green;
}
void ofApp::onBlueStateEntered(ofxState * const & value){
	ofLogNotice("ofApp") << "blue state entered";
	_backgroundColorParameter = ofColor::blue;
}
void ofApp::onPurpleStateEntered(ofxState * const & value){
	ofLogNotice("ofApp") << "purple state entered";
	_backgroundColorParameter = ofColor(255, 0, 255);
}
void ofApp::onRedStateExited(ofxState * const & value){
	ofLogNotice("ofApp") << "red state exited";
}
void ofApp::onGreenStateExited(ofxState * const & value){
	ofLogNotice("ofApp") << "green state exited";
}
void ofApp::onBlueStateExited(ofxState * const & value){
	ofLogNotice("ofApp") << "blue state exited";
}
void ofApp::onPurpleStateExited(ofxState * const & value){
	ofLogNotice("ofApp") << "purple state exited";
}
