#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Gauge : public GameObject
{
    int hPictGauge_;
    int hPictFrame_;
    int nowHp_, maxHp_;
    int animHp_;
public:
    //�R���X�g���N�^
    Gauge(GameObject* parent);

    //�f�X�g���N�^
    ~Gauge();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetHp(int nowHp, int maxHp)
    {
        nowHp_ = nowHp;
        maxHp_ = maxHp;
        animHp_ = (animHp_ * 9 + nowHp_) / 10;
    }
};
