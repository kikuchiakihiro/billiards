#include "Player.h"
#include "Ball.h"
#include "Engine/Input.h"
//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
}

//�X�V
void Player::Update()
{
    if (Input::IsKeyDown(DIK_SPACE)) {
        myBall->AddForce(XMVectorSet(0.1f, 0, 0.1f, 0));
    }
}

//�`��
void Player::Draw()
{
}

//�J��
void Player::Release()
{
}