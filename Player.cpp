#include "Player.h"
#include "Ball.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
    direction = 0.0f;
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
    if (Input::IsKey(DIK_A))
        direction -= 0.01f;
    if (Input::IsKey(DIK_D))
        direction += 0.01f;
    if (Input::IsKey(DIK_SPACE)) {
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