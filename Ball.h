#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Ball : public GameObject
{
    int hModel;    //モデル番号
    int number;
    XMVECTOR velocity;
   
public:
    //コンストラクタ
    Ball(GameObject* parent);

    //デストラクタ
    ~Ball();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    void SetNumber(int no);
    //開放
    void Release() override;

    void AddForce(XMVECTOR f);

    XMVECTOR GetVelocity() { return velocity; }
    XMFLOAT3 GetNextPosition() { return GetPosition() + velocity; }
};
