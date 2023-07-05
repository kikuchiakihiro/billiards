#include "Ready.h"
#include "Engine/Image.h"

namespace{
	float startX;
	float endX;
	float totalTime;
	float currentTime;
}
Ready::Ready(GameObject* parent)
{
}

Ready::~Ready()
{
}

void Ready::Initialize()
{
	hImage = Image::Load("Ready.png");
	startX = 5.0f;
	endX = 0.0f;
	totalTime = 3.0f;
	currentTime = 0.0f;
}

float easeInCubic(float x) {
	return x * x * x;
}

void Ready::Update()
{
	currentTime += 1.0f / 60.0f;
	if (currentTime > totalTime) {
		currentTime = totalTime;
	}
	float t = currentTime / totalTime;
	float val = easeInCubic(t);
	transform_.position_.x = val * (endX - startX) + startX;
	transform_.position_.y = val * (endX - startX) + startX;
}

void Ready::Draw()
{
	Image::SetTransform(hImage, transform_);
	Image::Draw(hImage);
}
