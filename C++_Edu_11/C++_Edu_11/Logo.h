#pragma once
#include "Scene.h"

//=======================================
// Logo Slider
//=======================================
struct SliderTransform
{
	Transform Info;
	string Texture;
};


class Logo : public Scene
{
private:
	Transform Info;
	int Color;
	ULONGLONG Time;
	ULONGLONG DelayTime;
	int Switching;
	

	//=======================================
	// Logo Slider
	//=======================================
	SliderTransform Sliders[8];
	
public:
	virtual void Start(void)override;
	virtual void Update(void)override;
	virtual void Render(void)override;
	virtual void Release(void)override;
public:
	Logo();
	virtual ~Logo();
};

