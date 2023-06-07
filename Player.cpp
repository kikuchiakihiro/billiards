#include "Player.h"
#include "Ball.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
    direction = 0.0f;
    power = 0.3f;
    hModel = Model::Load("Ball1.fbx");
    transform_.scale_ = XMFLOAT3(0.2, 0.2, 0.2);
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
    if (Input::IsKey(DIK_A))
        direction -= 0.01f;
    if (Input::IsKey(DIK_D))
        direction += 0.01f;
    if (Input::IsKey(DIK_SPACE)) {
        XMVECTOR base = XMVectorSet(0, 0, power, 0);//��]���Ă��Ȃ��Ƃ��Ɉړ�����x�N�g��
        XMMATRIX yrot = XMMatrixRotationY(direction);//��]�s���������
        XMVECTOR v = XMVector3Transform(base, yrot);//���̉�]�Ńx�N�g���̌�����ς���
        myBall->AddForce(v);//���ꂪ��]��̈ړ��x�N�g��
    }
}

//�`��
void Player::Draw()
{
    XMVECTOR base = XMVectorSet(0,0,1.2f,0);
    XMMATRIX yrot = XMMatrixRotationY(direction);
    XMVECTOR v = XMVector3Transform(base, yrot);
    transform_.position_ = myBall->GetPosition() + v;

    Model::SetTransform(hModel, transform_);
    Model::Draw(hModel);
}

//�J��
void Player::Release()
{
}