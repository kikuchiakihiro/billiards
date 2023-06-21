#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Ball : public GameObject
{
    int hModel;    //���f���ԍ�
    int number;
    XMVECTOR velocity;
   
public:
    //�R���X�g���N�^
    Ball(GameObject* parent);

    //�f�X�g���N�^
    ~Ball();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    void SetNumber(int no);
    //�J��
    void Release() override;

    void AddForce(XMVECTOR f);

    XMVECTOR GetVelocity() { return velocity; }
    XMFLOAT3 GetNextPosition() { return GetPosition() + velocity; }
};
