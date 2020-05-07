#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(25);

	//renderer1.setup("r1");
	//renderer2.setup("r2");

	parameters.setName("g1");
	parameters.add(vSync.set("b",true));
	   
    //parameters2.setName("g2");
    //parameters2.add(vSync.set("b",true));

////    parameters2.add(renderer1.parameters);
//    parameters2.add(renderer2.parameters);
////    parameters.add(parameters2);

    panel = gui.addPanel(parameters);
//    panel->getVisible().set(false);
//	
//    group = gui.addGroup(parameters);
//    //group1 = group->addGroup(renderer1.parameters);
//    group2 = group->addGroup(parameters2);
////    auto group3 = group2->addGroup(parameters);
	   

	//----
//
//
//
//	//TODO:
//    parameters3.setName("g3");
//    parameters3.add(parameters);
//    //parameters3.add(parameters2);
//    //parameters3.add(renderer1.parameters);
//    //parameters3.add(renderer2.parameters);
//
////    auto gnames = parameters3.getGroupHierarchyNames();
//    auto gnames = parameters3.getGroup("g3").getGroupHierarchyNames();
//    cout <<"gnames:"<< ofToString(gnames) << endl;



	//myGroup = gui.addGroup("myGroup");







	//----


    //group->setPosition(0, 0);
	//panel->loadFromFile("settings.xml");
	//font.load(OF_TTF_SANS, 9, true, true);
	//font.load("assets/fonts/DINPro-Bold.otf", 9, true, true);

	ofEnableAlphaBlending();


//    group = gui.addPanel("AUDIO FACTORY");
    //group->loadTheme("assets/themes/theme_bleurgh.json");
    //group->setPosition(0,0);
}

void ofApp::vSyncChanged(bool & vSync){
	ofSetVerticalSync(vSync);
}


//--------------------------------------------------------------
void ofApp::update(){
	// frameNum is a readonly parameter so this will fail to compile
	// unless we are inside the CirclesRenderer class
	// renderer.frameNum = 5;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	//renderer1.draw();
	//renderer2.draw();
	//ofSetColor(255);
	//font.drawString("frame: " + ofToString(renderer1.frameNum),ofGetWidth()-150,20);
	//font.drawString("fps: " + ofToString((int)ofGetFrameRate()),ofGetWidth()-150,40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//	if(key=='s'){
//		ofSerialize(settings, parameters);
//		settings.save("settings.xml");
//	}
//	if(key=='l'){
//		settings.load("settings.xml");
//		ofDeserialize(settings, parameters);
//	}
//	if(key=='o'){
//		cout << renderer1.parameters;
//		cout << renderer2.parameters;
//	}
//	if(key=='r'){
//		renderer1.color = ofColor(127);
//		renderer2.color = ofColor(127);
//	}
//    if(key=='1'){
//
//        group2->minimize();
//    }
//    if(key=='2'){
//
//        group2->maximize();
//    }
//    if(key=='3'){
//         auto r1 = group->getGroup("r1");
//         r1->getGroup("position")->setEnabled(false);
//    }
//    if(key=='4'){
//        auto r1 = group->getGroup("r1");
//        r1->getGroup("position")->setEnabled(true);
//    }
//    if(key=='5'){
////        auto r1 = group->getGroup("r1");
////        r1->
//    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}


//
////--------------------------------------------------------------
//template<typename ParameterType>
//bool ofApp::AddParameter(ofParameter<ParameterType>& parameter)
//{
//	//auto tmpRef = parameter.get();
//	//const auto& info = typeid(ParameterType);
//
//	////convert string to char pointer
//	//string _str = parameter.getName();
//	//const char * _name(_str.c_str());
//
//
//	////_name -> GetUniqueName(parameter)
//	//if (info == typeid(float))
//	//{
//	//	if (ImGui::SliderFloat(GetUniqueName(parameter), (float *)&tmpRef, parameter.getMin(), parameter.getMax()))
//	//	{
//	//		parameter.set(tmpRef);
//	//		return true;
//	//	}
//	//	return false;
//	//}
//	//if (info == typeid(int))
//	//{
//	//	if (ImGui::SliderInt(GetUniqueName(parameter), (int *)&tmpRef, parameter.getMin(), parameter.getMax()))
//	//	{
//	//		parameter.set(tmpRef);
//	//		return true;
//	//	}
//	//	return false;
//	//}
//	//if (info == typeid(bool))
//	//{
//	//	if (ImGui::Checkbox(GetUniqueName(parameter), (bool *)&tmpRef))
//	//	{
//	//		parameter.set(tmpRef);
//	//		return true;
//	//	}
//	//	return false;
//	//}
//
//	ofLogWarning(__FUNCTION__) << "Could not create GUI element for type " << info.name();
//	return false;
//}
//
////--------------------------------------------------------------
//void ofApp::AddGroup(ofParameterGroup& group)
//{
//	for (auto parameter : group)
//	{
//		// Group.
//		auto parameterGroup = std::dynamic_pointer_cast<ofParameterGroup>(parameter);
//		if (parameterGroup)
//		{
//			// Recurse through contents.
//			AddGroup(*parameterGroup);
//			continue;
//		}
//
////		// Parameter, try everything we know how to handle.
////#if OF_VERSION_MINOR >= 10
////		auto parameterVec2f = std::dynamic_pointer_cast<ofParameter<glm::vec2>>(parameter);
////		if (parameterVec2f)
////		{
////			ofxImGui::AddParameter(*parameterVec2f);
////			continue;
////		}
////		auto parameterVec3f = std::dynamic_pointer_cast<ofParameter<glm::vec3>>(parameter);
////		if (parameterVec3f)
////		{
////			ofxImGui::AddParameter(*parameterVec3f);
////			continue;
////		}
////		auto parameterVec4f = std::dynamic_pointer_cast<ofParameter<glm::vec4>>(parameter);
////		if (parameterVec4f)
////		{
////			ofxImGui::AddParameter(*parameterVec4f);
////			continue;
////		}
////#endif
////		auto parameterOfVec2f = std::dynamic_pointer_cast<ofParameter<ofVec2f>>(parameter);
////		if (parameterOfVec2f)
////		{
////			ofxImGui::AddParameter(*parameterOfVec2f);
////			continue;
////		}
////		auto parameterOfVec3f = std::dynamic_pointer_cast<ofParameter<ofVec3f>>(parameter);
////		if (parameterOfVec3f)
////		{
////			ofxImGui::AddParameter(*parameterOfVec3f);
////			continue;
////		}
////		auto parameterOfVec4f = std::dynamic_pointer_cast<ofParameter<ofVec4f>>(parameter);
////		if (parameterOfVec4f)
////		{
////			ofxImGui::AddParameter(*parameterOfVec4f);
////			continue;
////		}
////		auto parameterFloatColor = std::dynamic_pointer_cast<ofParameter<ofFloatColor>>(parameter);
////		if (parameterFloatColor)
////		{
////			ofxImGui::AddParameter(*parameterFloatColor);
////			continue;
////		}
////		auto parameterFloat = std::dynamic_pointer_cast<ofParameter<float>>(parameter);
////		if (parameterFloat)
////		{
////			ofxImGui::AddParameter(*parameterFloat);
////			continue;
////		}
////		auto parameterInt = std::dynamic_pointer_cast<ofParameter<int>>(parameter);
////		if (parameterInt)
////		{
////			ofxImGui::AddParameter(*parameterInt);
////			continue;
////		}
////		auto parameterBool = std::dynamic_pointer_cast<ofParameter<bool>>(parameter);
////		if (parameterBool)
////		{
////			ofxImGui::AddParameter(*parameterBool);
////			continue;
////		}
//
//		ofLogWarning(__FUNCTION__) << "Could not create GUI element for parameter " << parameter->getName();
//	}
//}
