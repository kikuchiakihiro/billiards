#include "Botton1.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
//�R���X�g���N�^
Botton1::Botton1(GameObject* parent)
    :GameObject(parent, "Botton1"), hPict_(-1),hPictD_(-1)
{
}

//�f�X�g���N�^
Botton1::~Botton1()
{
}

//������
void Botton1::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("CommonButtonBack.png");
	assert(hPict_ >= 0);
	hPictD_ = Image::Load("CommonButtonBackDisable.png");
	assert(hPict_ >= 0);
	transform_.position_.x = 0.5f;
}

//�X�V
void Botton1::Update()
{
	if (Input::IsMouseButton(0)) {
		Image::SetAlpha(hPict_, 0);
		Image::SetAlpha(hPictD_, 255);
	}
		
	else{
		Image::SetAlpha(hPict_, 255);
		Image::SetAlpha(hPictD_, 0);
	}
		
}

//�`��
void Botton1::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
	Image::SetTransform(hPictD_, transform_);
	Image::Draw(hPictD_);
}

//�J��
void Botton1::Release()
{
}