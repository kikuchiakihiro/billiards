//#include "Button2.h"
//#include "Engine/Image.h"
//#include "Engine/Input.h"
//#include "Engine/Direct3D.h"
////�R���X�g���N�^
//Button2::Button2(GameObject* parent)
//	:GameObject(parent, "Button2"), hPict2_(-1), hPictD2_(-1)
//{
//}
//
////�f�X�g���N�^
//Button2::~Button2()
//{
//}
//
////������
//void Button2::Initialize()
//{
//	hPict2_ = Image::Load("FoodButtonGive.png");
//	assert(hPict2_ >= 0);
//	hPictD2_ = Image::Load("FoodButtonGiveDisable.png");
//	assert(hPictD2_ >= 0);
//	transform_.position_.x = -0.5f;
//}
//
////�X�V
//void Button2::Update()
//{
//	if (Input::IsMouseButton(0)) {
//		Image::SetAlpha(hPict2_, 0);
//		Image::SetAlpha(hPictD2_, 255);
//	}
//
//	else {
//		Image::SetAlpha(hPict2_, 255);
//		Image::SetAlpha(hPictD2_, 0);
//	}
//}
//
////�`��
//void Button2::Draw()
//{
//	Image::SetTransform(hPict2_, transform_);
//	Image::Draw(hPict2_);
//	Image::SetTransform(hPictD2_, transform_);
//	Image::Draw(hPictD2_);
//}
//
////�J��
//void Button2::Release()
//{
//}
//
//void Button2::SetPosition(int x, int y)
//{
//	transform_.position_.x = (x - Direct3D::screenWidth_ / 2) / Direct3D::screenWidth_;
//	transform_.position_.y = (y - Direct3D::screenHeight_ / 2) / (Direct3D::screenHeight_ / 2);
//	center = XMFLOAT3(x, y, 0);
//}
