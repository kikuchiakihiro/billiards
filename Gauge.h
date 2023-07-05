#pragma once
#include "Engine/GameObject.h"
//gauge�N���X�́Agauge�̍ő��100���i�܂�1�C0�j�ƂȂ�悤�ɍ��
// �\���̑傫���ɂ���āA�\���T�C�Y��ς����悤�ɂ���
// �\������ʒu�́A�O����w��ł���悤�ɂ���B
// ���Z����֐��ƁA���Z����֐��ƁA���݂̒l���擾����֐���p�ӂ���B
//���������Ǘ�����N���X
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
