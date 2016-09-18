#include "ofxStateMachine.h"

ofxStateMachine::ofxStateMachine() :
	_runningB(false){
}

ofxStateMachine * ofxStateMachine::setInitialState(ofxState * state){
	_initialState = state;
	return this;
}

ofxStateMachine * ofxStateMachine::addTransition(ofxState * from, string action, ofxState * to){
	pair <ofxState *, string> key(from, action);
	_transitions[key] = to;
	return this;
}

ofxStateMachine * ofxStateMachine::removeTransition(ofxState * from, string action, ofxState * to){
	pair <ofxState *, string> key(from, action);
	auto it = _transitions.find(key);
	if(it != _transitions.end() && _transitions[key] == to){
		_transitions.erase(it);
	}
	return this;
}

void ofxStateMachine::onActionEvent(string & action){
	if(!_runningB){
		return;
	}
	if(_transitions.find(pair <ofxState *, string>(_currentState, action)) != _transitions.end()){
		ofxState * fromState = _currentState;
		ofxState * toState = _transitions[pair < ofxState *, string > (_currentState, action)];
		_currentState->exit(toState);
		_currentState = toState;
		_currentState->enter(fromState);
	}
}

void ofxStateMachine::transit(string action){
	onActionEvent(action);
}

bool ofxStateMachine::isRunning(){
	return _runningB;
}

ofxState * ofxStateMachine::getCurrentState() const {
	return _currentState;
}

bool ofxStateMachine::isCurrentState(ofxState * state){
	return _currentState == state;
}

ofxStateMachine * ofxStateMachine::start(){
	if(_runningB){
		ofLogWarning("ofxStateMachine") << "state machine is already running";
	}else{
		_runningB = true;
		_currentState = _initialState;
		_currentState->enter(_initialState); //nullptr?
	}
	return this;
}

ofxStateMachine * ofxStateMachine::stop(){
	_currentState->exit(_initialState);
	if(_runningB){
		_runningB = false;
	}else{
		ofLogWarning("ofxStateMachine") << "state machine is already stopped";
	}
	return this;
}

ofxStateMachine * ofxStateMachine::clear(){
	_transitions.clear();
	_initialState = nullptr;
}

