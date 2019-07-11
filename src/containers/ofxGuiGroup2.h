#pragma once
#include "ofxGuiContainer.h"


class ofxGuiGroup2Header : public ofxGuiElement {
	public:
		ofxGuiGroup2Header(const ofJson &config = ofJson());

		~ofxGuiGroup2Header();

		virtual bool mousePressed(ofMouseEventArgs & args) override;

		virtual float getMinWidth() override;
		virtual float getMinHeight() override;

		static std::string getClassType();

	protected:

		virtual std::vector<std::string> getClassTypes() override;

		virtual void generateDraw() override;
		virtual void render() override;
		ofVboMesh textMesh;

};


class ofxGuiGroup2 : public ofxGuiContainer {
	public:

		ofxGuiGroup2();
		ofxGuiGroup2(const std::string& collectionName);
		ofxGuiGroup2(const std::string& collectionName, const ofJson & config);
		ofxGuiGroup2(const ofParameterGroup & parameters, const ofJson &config = ofJson());
		ofxGuiGroup2(const ofParameterGroup & parameters, const std::string& _filename, float x = 10, float y = 10);
		ofxGuiGroup2(const std::string& collectionName, const std::string& _filename, float x = 10, float y = 10);

		virtual ~ofxGuiGroup2();

		void setup();

		virtual void minimize();
		virtual void maximize();
		virtual void minimizeAll();
		virtual void maximizeAll();
		bool getMinimized();
		void toggleMinimize();

		void setShowHeader(bool show);
		ofxGuiElement* getHeader();

		virtual std::vector<ofxGuiElement*> getControls() override;

		static std::string getClassType();

	protected:

		virtual std::vector<std::string> getClassTypes() override;

		virtual void _setConfig(const ofJson & config) override;

		ofParameter<bool> minimized;
		ofParameter<bool> showHeader;
		ofxGuiElement* header;

		virtual void onHeaderVisibility(bool& showing);
		virtual void onHeaderHeight(float& height);

	private:
		float widthMaximized, heightMaximized;

};
