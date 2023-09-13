#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Botton1 : public GameObject
{
    int hPict_;
    int hPictD_;
public:
    //コンストラクタ
    Botton1(GameObject* parent);

    //デストラクタ
    ~Botton1();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};