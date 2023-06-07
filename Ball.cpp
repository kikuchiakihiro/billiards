#include "Ball.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include <assert.h>

//�R���X�g���N�^
Ball::Ball(GameObject* parent)
    :GameObject(parent, "Ball"), hModel(-1)
{
    velocity = XMVectorSet(0, 0, 0, 0);
}

//�f�X�g���N�^
Ball::~Ball()
{
    if(hModel > 0)
    Model::Release(hModel);
}

//������
void Ball::Initialize()
{
}

//�X�V
void Ball::Update()
{

   
    float len = Length(velocity);
    len -= 0.001f;
    velocity = XMVector3Normalize(velocity) * len;

    transform_.position_ += velocity;

}

//�`��
void Ball::Draw()
{
    if (hModel < 0)
        return;
    Model::SetTransform(hModel, transform_);
    Model::Draw(hModel);
}

void Ball::SetNumber(int no)
{
    number = no;
    hModel = Model::Load("Ball1.fbx");
    assert(hModel >= 0);
}

//�J��
void Ball::Release()
{
}

void Ball::AddForce(XMVECTOR f)
{
    velocity += f;
}
