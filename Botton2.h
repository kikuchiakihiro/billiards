#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Botton2 : public GameObject
{
    int hPict2_;
    int hPictD2_;
public:
    //コンストラクタ
    Botton2(GameObject* parent);

    //デストラクタ
    ~Botton2();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};