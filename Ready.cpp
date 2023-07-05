#include "Ready.h"
#include "Engine/Image.h"

namespace {
	float startX;
	float endX;
	float totalTime;
	float currentTime;
	int seq_line;
	float seq_time;
	enum ACT {
		A_SLIDEIN = 1,
		A_WAIT,
		A_SLIDEOUT,
		A_END
	};
	struct Sequence {
		float time;
		int action;
		float param;
	};
	Sequence tbl[] = {
		{0.0f,A_SLIDEIN, 5.0f},
		{3.0f,A_WAIT,0.0f},
		{4.0f,A_SLIDEOUT,-5.0f},
		{5.0f,A_END,0.0f}
	};
	ACT currentAction;
	bool canMove;
};
Ready::Ready(GameObject* parent)
{
	seq_line = -1;
	seq_time = 0.0f;
	canMove = false;
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
	
	seq_time += 1.0f / 60.0f;
	if (seq_time >= tbl[seq_line + 1].time) {

		seq_line++;
		switch  (tbl[seq_line].action) {
		case A_END:
			KillMe();
			break;
		case A_SLIDEIN:
			startX = tbl[seq_line].param;
			endX = 0.0f;
			totalTime = tbl[seq_line+1].time-seq_time;
			currentTime = 0.0f;
			break;
		case A_WAIT:
			startX = transform_.position_.x;
			endX = transform_.position_.x;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		case A_SLIDEOUT:
			canMove = true;
			startX = transform_.position_.x;
			endX = tbl[seq_line].param;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		}
	}



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

bool Ready::Finished()
{
	return canMove;
}
