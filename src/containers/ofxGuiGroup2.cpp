#include "ofGraphics.h"

#include "ofxGuiGroup2.h"
#include "ofxGuiPanel.h"
#include "ofxGuiSliderGroup.h"
#include "ofxGuiTabs.h"
#include "../DOM/Document.h"
#include "../DOM/Layout.h"
#include "../controls/ofxGuiFpsPlotter.h"
#include "../view/JsonConfigParser.h"

ofxGuiGroup2Header::ofxGuiGroup2Header(const ofJson &config):ofxGuiElement(){
	setTheme();
	_setConfig(config);
	registerMouseEvents();
}

void ofxGuiGroup2Header::generateDraw(){
	ofxGuiElement::generateDraw();

	textMesh.clear();
	ofxGuiGroup2* _parent = dynamic_cast<ofxGuiGroup2*>(parent());
	if(_parent){
		if(_parent->getShowName()){
			textMesh.append(getTextMesh(_parent->getName(), textPadding, getHeight()/ 2 + 4));
		}
		if(_parent->getMinimized()){
			textMesh.append(getTextMesh("+", getWidth() - textPadding - 10, getHeight() / 2 + 4));
		}else{
			textMesh.append(getTextMesh("-", getWidth()- textPadding - 10, getHeight() / 2 + 4));
		}
	}
}

ofxGuiGroup2Header::~ofxGuiGroup2Header(){
}

void ofxGuiGroup2Header::render() {
	ofColor c = ofGetStyle().color;

	ofBlendMode blendMode = ofGetStyle().blendingMode;
	if(blendMode!=OF_BLENDMODE_ALPHA){
		ofEnableAlphaBlending();
	}

	ofxGuiElement::render();

	ofxGuiGroup2* _parent = dynamic_cast<ofxGuiGroup2*>(parent());
	if(_parent){
		if(_parent->getShowName()){

			ofSetColor(textColor);
			bindFontTexture();
			textMesh.draw();
			unbindFontTexture();

		}
	}

	ofSetColor(c);
	if(blendMode!=OF_BLENDMODE_ALPHA){
		ofEnableBlendMode(blendMode);
	}

}

bool ofxGuiGroup2Header::mousePressed(ofMouseEventArgs & args){

	if(!isHidden()){
		ofRectangle minButton(getWidth() - textPadding * 2 - 10, 0, textPadding * 2 + 10, getHeight());
		minButton.setPosition(localToScreen(minButton.getPosition()));
		if(minButton.inside(args.x, args.y)){
			ofxGuiGroup2* _parent = dynamic_cast<ofxGuiGroup2*>(parent());
			if(_parent){
				_parent->toggleMinimize();
				this->setNeedsRedraw();
				return true;
			}
		}
	}

	return ofxGuiElement::mousePressed(args);

}

float ofxGuiGroup2Header::getMinWidth(){
	std::string text = "";

	ofxGuiGroup2* _parent = dynamic_cast<ofxGuiGroup2*>(parent());
	if(_parent){
		if(_parent->getShowName()){
			text += _parent->getName();
		}
		text += "+";
	}

	return getTextWidth(text)+4*textPadding;
}

float ofxGuiGroup2Header::getMinHeight(){
	return ofxGuiElement::getTextHeight("test")+5;
}

std::string ofxGuiGroup2Header::getClassType(){
	return "group-header";
}

vector<std::string> ofxGuiGroup2Header::getClassTypes(){
	vector<std::string> types = ofxGuiElement::getClassTypes();
	types.push_back(getClassType());
	return types;
}


/*
 *
 * ofxGuiGroup2
 *
 */

ofxGuiGroup2::ofxGuiGroup2()
	:ofxGuiContainer(){

	setup();

}

ofxGuiGroup2::ofxGuiGroup2(const std::string& collectionName)
	:ofxGuiContainer(){

	setup();
	setName(collectionName);

}

ofxGuiGroup2::ofxGuiGroup2(const std::string& collectionName, const ofJson & config)
	:ofxGuiGroup2(collectionName){

	_setConfig(config);

}

ofxGuiGroup2::ofxGuiGroup2(const ofParameterGroup & _parameters, const ofJson & config)
	:ofxGuiGroup2(_parameters.getName()){

	addParametersFrom(_parameters);
	_setConfig(config);

}

ofxGuiGroup2::ofxGuiGroup2(const std::string& collectionName, const std::string& _filename, float x, float y)
	:ofxGuiContainer(collectionName, _filename, x, y){

	setup();

}

ofxGuiGroup2::ofxGuiGroup2(const ofParameterGroup & _parameters, const std::string& _filename, float x, float y)
	:ofxGuiContainer(_parameters, _filename, x,y){

	setup();

}


ofxGuiGroup2::~ofxGuiGroup2(){

	showHeader.removeListener(this, &ofxGuiGroup2::onHeaderVisibility);

}

void ofxGuiGroup2::setup(){

	minimized.set("minimized", false);
	showHeader.set("show-header", true);

	header = add<ofxGuiGroup2Header>(ofJson({{"margin", 0}}));

	showHeader.addListener(this, &ofxGuiGroup2::onHeaderVisibility);

	setTheme();

}

void ofxGuiGroup2::_setConfig(const ofJson &config){

	ofxGuiContainer::_setConfig(config);
	JsonConfigParser::parse(config, showHeader);

}

void ofxGuiGroup2::minimize(){
	minimized = true;
//	blockLayout(true);
//	widthMaximized = getWidth();
//	heightMaximized = getHeight();

	for(auto& child : getControls()){
		child->setHidden(true);
	}

	invalidateChildShape();

//	blockLayout(false);

//	setLayoutSize(header->getWidth(), header->getHeight());
}

void ofxGuiGroup2::maximize(){
	minimized = false;
//	blockLayout(true);

	for(auto& child : getControls()){
		child->setHidden(false);
	}
//	setLayoutSize(widthMaximized, heightMaximized);

//	blockLayout(false);
}

void ofxGuiGroup2::minimizeAll(){
	for(auto & e: getControls()){
		ofxGuiGroup2 * group = dynamic_cast <ofxGuiGroup2 *>(e);
		if(group){
			group->minimize();
		}
	}
}

void ofxGuiGroup2::maximizeAll(){
	for(auto & e: getControls()){
		ofxGuiGroup2 * group = dynamic_cast <ofxGuiGroup2 *>(e);
		if(group){
			group->maximize();
		}
	}
}

bool ofxGuiGroup2::getMinimized(){
	return minimized;
}

void ofxGuiGroup2::toggleMinimize(){
	if(minimized){
		maximize();
	}else {
		minimize();
	}
}

void ofxGuiGroup2::setShowHeader(bool show) {
	if(show == false){
		if(minimized)
			maximize();
	}
	showHeader = show;
	invalidateChildShape();
 }

std::vector<ofxGuiElement*> ofxGuiGroup2::getControls(){
	static_assert(std::is_base_of<DOM::Element, ofxGuiElement>(), "ElementType must be an Element or derived from Element.");

	std::vector<ofxGuiElement*> results;

	for (auto& child : _children){
		ofxGuiElement* pChild = dynamic_cast<ofxGuiElement*>(child.get());

		if (pChild && pChild != header){
			results.push_back(pChild);
		}
	}

	return results;
}

ofxGuiElement* ofxGuiGroup2::getHeader(){
	return this->header;
}

void ofxGuiGroup2::onHeaderVisibility(bool &showing){
	if(getHeader()){
		getHeader()->setHidden(!showing);
	}
}

void ofxGuiGroup2::onHeaderHeight(float &height){
	if(getHeader()){
		getHeader()->setHeight(height);
	}
}

std::string ofxGuiGroup2::getClassType(){
	return "group";
}

vector<std::string> ofxGuiGroup2::getClassTypes(){
	vector<std::string> types = ofxGuiContainer::getClassTypes();
	types.push_back(getClassType());
	return types;
}
