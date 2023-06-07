#pragma once
#include "Engine/GameObject.h"

class Ball;

//���������Ǘ�����N���X
class Player : public GameObject
{
    int hModel;
    Ball* myBall;
    float direction;
    float power;
public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
    void SetMyBall(Ball* ball) { myBall = ball; }
};

