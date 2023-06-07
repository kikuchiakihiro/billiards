#include "Ball.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include <assert.h>

//コンストラクタ
Ball::Ball(GameObject* parent)
    :GameObject(parent, "Ball"), hModel(-1)
{
    
}

//デストラクタ
Ball::~Ball()
{
    if(hModel > 0)
    Model::Release(hModel);
}

//初期化
void Ball::Initialize()
{
}

//更新
void Ball::Update()
{
}

//描画
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

//開放
void Ball::Release()
{
}