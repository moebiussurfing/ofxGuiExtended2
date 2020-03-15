#pragma once

#include "ofMain.h"
#include "ofxGuiExtended.h"
#include "CirclesRenderer.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void vSyncChanged(bool & vSync);

		ofxGui gui;
		ofxGuiPanel* panel;
    ofxGuiGroup* group;
    ofxGuiGroup* group1;
    ofxGuiGroup* group2;
    ofxGuiGroup* group3;


    ofParameter<bool> vSync;

    ofParameterGroup parameters;
    ofParameterGroup parameters2;
ofParameterGroup parameters3;

    ofXml settings;

    CirclesRenderer renderer1,renderer2;
		ofTrueTypeFont font;
};
