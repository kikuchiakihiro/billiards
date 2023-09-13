#include "Botton2.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
//�R���X�g���N�^
Botton2::Botton2(GameObject* parent)
	:GameObject(parent, "Botton2"), hPict2_(-1), hPictD2_(-1)
{
}

//�f�X�g���N�^
Botton2::~Botton2()
{
}

//������
void Botton2::Initialize()
{
	hPict2_ = Image::Load("FoodButtonGive.png");
	assert(hPict2_ >= 0);
	hPictD2_ = Image::Load("FoodButtonGiveDisable.png");
	assert(hPictD2_ >= 0);
	transform_.position_.x = -0.5f;
}

//�X�V
void Botton2::Update()
{
	if (Input::IsMouseButton(0)) {
		Image::SetAlpha(hPict2_, 0);
		Image::SetAlpha(hPictD2_, 255);
	}

	else {
		Image::SetAlpha(hPict2_, 255);
		Image::SetAlpha(hPictD2_, 0);
	}
}

//�`��
void Botton2::Draw()
{
	Image::SetTransform(hPict2_, transform_);
	Image::Draw(hPict2_);
	Image::SetTransform(hPictD2_, transform_);
	Image::Draw(hPictD2_);
}

//�J��
void Botton2::Release()
{
}