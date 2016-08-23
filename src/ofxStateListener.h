#pragma once

class ofxState;
class ofxStateListener {
	public:
		virtual void onEnteredEvent(ofxState * const & state) = 0;
		virtual void onExitedEvent(ofxState * const & state) = 0;
	protected:
	private:
};
