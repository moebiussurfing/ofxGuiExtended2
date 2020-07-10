#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	renderer1.setup("renderer1");
	renderer2.setup("renderer2");

	parameters1.setName("parameters1");
	parameters1.add(vSync.set("b",true));
    parameters1.add(renderer1.parameters);

	parameters2.setName("parameters2");
    parameters2.add(renderer1.parameters);
    parameters2.add(renderer2.parameters);
    parameters2.add(parameters1);

	panel = gui.addPanel();
	panel->addGroup(parameters2);

	//auto g = panel->getGroup(renderer1.parameters.getName());
	//auto g2 = panel->getGroup(renderer2.parameters.getName());
	//g2->setBackgroundColor(ofColor::green);
	//g->setBackgroundColor(ofColor::red);
}

void ofApp::vSyncChanged(bool & vSync) {
	ofSetVerticalSync(vSync);
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor::white, ofColor::gray);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

