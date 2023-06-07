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
    len -= 0.01f;
    if (len < 0) len = 0.0f;
    velocity = XMVector3Normalize(velocity) * len;

    std::list<Ball*>all = FindGameObjects<Ball>();
    for (std::list<Ball*>::iterator itr = all.begin(); itr != all.end(); itr++) {
        if (*itr == this)continue;
        XMFLOAT3 next = transform_.position_ + velocity;
        XMFLOAT3 other = (*itr)->GetPosition();
        if (/*�d�Ȃ�[*/1 < 0);
    }






    XMFLOAT3 next = transform_.position_ + velocity;
    if (next.x >= 20.0f) {
        XMVECTOR n = XMVectorSet(-1, 0, 0, 0);
        n = n * -1;
        XMVECTOR ipvec = XMVector3Dot(velocity, n);
        float ip = XMVectorGetX(ipvec);
        XMVECTOR push = n * ip;
        XMVECTOR th = velocity - push;
        push *= -1;
        velocity = push + th;

        //XMFLOAT3 f;
        //XMStoreFloat3(&f, velocity);
        //f.x = -f.x;
        ////f.z = 0;
        //velocity=XMLoadFloat3(&f);

    }
    if (next.x <= -20.0f) {
        XMFLOAT3 f;
        XMStoreFloat3(&f, velocity);
        f.x = -f.x;
        //f.z = 0;
        velocity = XMLoadFloat3(&f);
    }
    if (next.z >= 20.0f) {
        XMFLOAT3 f;
        XMStoreFloat3(&f, velocity);
        //f.x = 0;
        f.z = -f.z;
        velocity = XMLoadFloat3(&f);
    }
    if (next.z <= -20.0f) {
        XMFLOAT3 f;
        XMStoreFloat3(&f, velocity);
        //f.x = 0;
        f.z = -f.z;
        velocity = XMLoadFloat3(&f);
    }
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
