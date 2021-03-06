#pragma once

#include "ofMain.h"
#include"circle.h"
#include"snack.h"
#include"target.h"
#include"character.h"
#include"library.cpp"
#include<vector>
#include<stack>
#include"Depthimage.h"
#include"pixel_image.h"
#include"sender.h"

#include"ofMain.h"
#include"ofApp.h"
#include<winsock.h>

#include <Kinect.h>


#pragma comment(lib,"ws2_32.lib")

#define distance_to_start 1
#define boom_time 5
#define create_time 3
//#define num_circles 150
const ofColor BLACK(0, 0, 0);
const ofColor WHITE(255, 255, 255);
const ofColor RED(255, 1, 52);
const ofColor YELLOW(250, 240, 20);
const ofColor GREEN(2, 233, 3);
const ofColor PURPLE(230, 0, 230);
const ofColor BLUE(57,189,255);

class ofApp : public ofBaseApp{

	public:
		~ofApp();
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		void draw_snack();
		void draw_target();
		void beback();
		void check_snack_and_target();

		void change_status(string new_status,string add_info="NA");
		void send_messages();

		circle mycircles[15][10];
		snack mysnack;
		target mytarget;
		vector<character> mycharacters;
		bool body_info(int& row,int& col); //transfer the body position to the screen 
		//game system

		int score;
		string game_state;
		string next_state;    //only used when Game of Life changes to Create
		int time;
		ofColor my_img[10][15];
		pixel_image mypixels;
		depthimage myKinect;
		string hand;
		bool open;
		sender mysender;
		ofPoint player_center;
		ofColor last;
		ofColor next;
};
