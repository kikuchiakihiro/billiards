#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Botton2 : public GameObject
{
    int hPict2_;
    int hPictD2_;
public:
    //�R���X�g���N�^
    Botton2(GameObject* parent);

    //�f�X�g���N�^
    ~Botton2();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};