#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Botton1 : public GameObject
{
    int hPict_;
    int hPictD_;
public:
    //�R���X�g���N�^
    Botton1(GameObject* parent);

    //�f�X�g���N�^
    ~Botton1();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};