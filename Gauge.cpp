#include "Gauge.h"
#include "Engine/Image.h"

//コンストラクタ
Gauge::Gauge(GameObject* parent)
    :GameObject(parent, "Gauge"),hPictGauge_(-1),hPictFrame_(-1),nowHp_(-1),maxHp_(-1)
{
}

//デストラクタ
Gauge::~Gauge()
{
}

//初期化
void Gauge::Initialize()
{
    hPictGauge_ = Image::Load("ber.png");
    assert(hPictGauge_ >= 0);

    ImageWidth = 512;
    ImageHeight = 64;


    hPictFrame_ = Image::Load("berf.png");
    assert(hPictFrame_ >= 0);

   
}

//更新
void Gauge::Update()
{
}

//描画
void Gauge::Draw()
{
    /*Transform transGauge = transform_;
    transGauge.scale_.x = (float)nowHp_ / (float)maxHp_;*/
    Image::SetTransform(hPictFrame_, transform_);
    Image::Draw(hPictFrame_);

    int left = ImageWidth / 2 - ImageWidth / 2 * nowHp_;
    int width = ImageWidth * nowHp_;
    Image::SetRect(hPictGauge_, left, 0, width, ImageHeight);
    Image::SetTransform(hPictGauge_, transform_);
    Image::Draw(hPictGauge_);
    
    
}

void Gauge::SetPosition(float x, float y)
{
    /*  nowHp_ = nowHp;
      maxHp_ = maxHp;
      animHp_ = (animHp_ * 9 + nowHp_) / 10;*/
    transform_.position_.x = x;
    transform_.position_.y = y;
}



void Gauge::AddValue(float v)
{
    nowHp_ += v;
    if (nowHp_ > 0.0f)
        nowHp_ = 0.0f;
    else if (nowHp_ > maxHp_)
        nowHp_ = maxHp_;
}

void Gauge::SetValue(float v)
{
}

float Gauge::GetValue()
{
    return 0.0f;
}

//開放
void Gauge::Release()
{

}