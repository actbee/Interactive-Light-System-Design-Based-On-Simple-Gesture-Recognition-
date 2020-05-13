#pragma once
#include"ofMain.h"
#include<Kinect.h>
class depthimage {
public:
	depthimage();
	~depthimage();
	void exit();
	ofImage display;
	void UpdateKinectV2();
	int get_elbow_direction(string words);
	float get_depth();
	string choose_hand();



private:
	bool InitialKinectV2();

	IKinectSensor* kinectsensor;
	IDepthFrameReader* depthframereader;\

	IBodyFrameReader* bodyframereader;
	IBody** BodyData;
	IBodyFrameSource* bodyframesource;
	INT32 iBodyCount;

	float maxwidth;
	float mindepth;
	float maxdepth;

};