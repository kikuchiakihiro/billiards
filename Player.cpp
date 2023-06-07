#include "Player.h"
#include "Ball.h"
#include "Engine/Input.h"
//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
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
    if (Input::IsKeyDown(DIK_SPACE)) {
        myBall->AddForce(XMVectorSet(0.1f, 0, 0.1f, 0));
    }
}

//描画
void Player::Draw()
{
}

//開放
void Player::Release()
{
}