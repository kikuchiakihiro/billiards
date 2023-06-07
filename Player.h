#pragma once
#include "Engine/GameObject.h"

class Ball;

//◆◆◆を管理するクラス
class Player : public GameObject
{
    int hModel;
    Ball* myBall;
    float direction;
    float power;
public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
    void SetMyBall(Ball* ball) { myBall = ball; }
};

