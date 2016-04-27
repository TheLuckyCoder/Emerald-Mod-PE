#pragma once

#include <string>

class App {
public:
    virtual ~App();
	
	App(int, char**);
	virtual void init();
	virtual void quit();
	virtual void wantToQuit();
	virtual void update();
	virtual void draw();
	virtual void destroy();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual void loadState(void*, int);
	virtual void saveState(void**, int*);
	virtual bool useTouchscreen();
	virtual void setTextboxText(std::string const&);
	virtual void setSize(int, int, float);
};
