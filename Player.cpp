#include "Player.h"
#include "Ball.h"
#include "Gauge.h"
#include "Engine/Input.h"
#include "Engine/Model.h"


/*
* キーボードでキューの方向選択、強さのゲージなどを出しスペースキーで決定
* キューを当てて、白球を打つ
* 
* ゲージ出したい、できればplayer球の横あたりに。やじるしなどで方向だしてもいいのかなと考えてます。
* 
* 
* 
*/


//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), maxHp_(120), nowHp_(0)
{
    direction = 0.0f;
    ShootPower = 1;
    power = 0.3f;
    hModel = Model::Load("Ball1.fbx");
    transform_.scale_ = XMFLOAT3(0.2, 0.2, 0.2);
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
}

//更新
void Player::Update()
{
    ShootLv = 0;

    if (Input::IsKey(DIK_A))
        direction -= 0.05f;
    if (Input::IsKey(DIK_D))
        direction += 0.05f;

    /*if(Input::IsKeyDown(DIK_P))
    {

        if (ShootLv <= 10) {
            ShootLv++;
            power += ShootPower;
        }
      

    }
    if (Input::IsKeyDown(DIK_L)) {

        if (ShootLv >= 0) {
            ShootLv--;
            power -= ShootPower;
        }


    }*/
    

    
    
    if (Input::IsKey(DIK_H) && Isincreaseing == true)
    {
        nowHp_ += 1;
        if (nowHp_ > maxHp_) {
            nowHp_ = maxHp_;
           
            Isincreaseing = false;
        }
    }
    else if (Input::IsKey(DIK_H) && Isincreaseing == false)
    {
        nowHp_ -= 1;
        if (nowHp_ < 0) {
            nowHp_ = 0;
            
            Isincreaseing = true;
        }
        
    }
      
    Gauge* pGauge = (Gauge*)FindObject("Gauge");
    pGauge->SetHp(nowHp_, maxHp_);

        if (Input::IsKeyUp(DIK_SPACE)) {

           
            XMVECTOR base = XMVectorSet(0, 0, power, 0);//回転していないときに移動するベクトル
            XMMATRIX yrot = XMMatrixRotationY(direction);//回転行列をつくって
            XMVECTOR v = XMVector3Transform(base, yrot);//その回転でベクトルの向きを変える
            myBall->AddForce(v);//これが回転後の移動ベクトル

        }
       
}

//描画
void Player::Draw()
{
    XMVECTOR base = XMVectorSet(0,0,1.2f,0);
    XMMATRIX yrot = XMMatrixRotationY(direction);
    XMVECTOR v = XMVector3Transform(base, yrot);
    transform_.position_ = myBall->GetPosition() + v;

    Model::SetTransform(hModel, transform_);
    Model::Draw(hModel);
}

//開放
void Player::Release()
{
}