#include "Gauge.h"
#include "Engine/Image.h"
//�R���X�g���N�^
Gauge::Gauge(GameObject* parent)
    :GameObject(parent, "Gauge"),hPictGauge_(-1),hPictFrame_(-1),nowHp_(-1),maxHp_(-1)
{
}

//�f�X�g���N�^
Gauge::~Gauge()
{
}

//������
void Gauge::Initialize()
{
    hPictGauge_ = Image::Load("ber.png");
    assert(hPictGauge_ >= 0);
    hPictFrame_ = Image::Load("berf.png");
    assert(hPictFrame_ >= 0);

    transform_.position_.x = -0.95;
    transform_.position_.y = 0.85;
}

//�X�V
void Gauge::Update()
{
}

//�`��
void Gauge::Draw()
{
    Transform transGauge = transform_;
    transGauge.scale_.x = (float)nowHp_ / (float)maxHp_;



    Image::SetTransform(hPictGauge_, transGauge);
    Image::Draw(hPictGauge_);
    Image::SetTransform(hPictFrame_, transform_);
    Image::Draw(hPictFrame_);
     
}

//�J��
void Gauge::Release()
{
}