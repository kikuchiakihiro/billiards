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
    nowHp_ += 0.01f;
    if (nowHp_ > maxHp_)
        nowHp_ = 0.0f;
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

//開放
void Gauge::Release()
{
}