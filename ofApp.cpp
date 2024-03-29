#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	for (int z = 500; z > -500; z -= 20) {

		auto location = glm::vec3(0, 0, z);

		ofPushMatrix();
		ofTranslate(location);

		auto rotate_deg = ofMap(ofNoise(z * 0.0015 + ofGetFrameNum() * 0.012), 0, 1, -540 , 540);
		ofRotateZ(rotate_deg);

		ofFill();
		ofSetColor(0);
		ofDrawBox(130, 130, 15);

		ofNoFill();
		ofSetColor(255);
		ofDrawBox(130, 130, 15);

		ofFill();

		ofSetColor(239, 39, 39);
		ofDrawSphere(150, 0, 8);

		ofSetColor(239, 239, 39);
		ofDrawSphere(0, 150, 8);

		ofSetColor(39, 39, 239);
		ofDrawSphere(-150, 0, 8);

		ofSetColor(39, 239, 239);
		ofDrawSphere(0, -150, 8);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 75;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}