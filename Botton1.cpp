#include "Botton1.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
//コンストラクタ
Botton1::Botton1(GameObject* parent)
    :GameObject(parent, "Botton1"), hPict_(-1),hPictD_(-1)
{
}

//デストラクタ
Botton1::~Botton1()
{
}

//初期化
void Botton1::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("CommonButtonBack.png");
	assert(hPict_ >= 0);
	hPictD_ = Image::Load("CommonButtonBackDisable.png");
	assert(hPict_ >= 0);
	transform_.position_.x = 0.5f;
}

//更新
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

//描画
void Botton1::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
	Image::SetTransform(hPictD_, transform_);
	Image::Draw(hPictD_);
}

//開放
void Botton1::Release()
{
}