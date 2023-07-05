#pragma once
#include "Engine/GameObject.h"
//gaugeクラスは、gaugeの最大を100％（つまり1，0）となるように作る
// 表示の大きさによって、表示サイズを変えれるようにする
// 表示する位置は、外から指定できるようにする。
// 加算する関数と、減算する関数と、現在の値を取得する関数を用意する。
//◆◆◆を管理するクラス
class Gauge : public GameObject
{
    int hPictGauge_;
    int hPictFrame_;
    //int nowHp_, maxHp_;
    // int animHp_;
    float nowHp_;
    const float maxHp_ = 1.0f;
    float animHp_;

    int ImageWidth, ImageHeight;
public:

    static constexpr float MIN = 0.0f;
    static constexpr float MAX = 1.0f;
    //コンストラクタ
    Gauge(GameObject* parent);

    //デストラクタ
    ~Gauge();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetHp(float nowHp,  float maxHp)
    {
      /*  nowHp_ = nowHp;
        maxHp_ = maxHp;
        animHp_ = (animHp_ * 9 + nowHp_) / 10;*/
    }
    void SetPosition(float x, float y);
   

    void AddValue(float v);

    void SetValue(float v);

    float GetValue();

};
