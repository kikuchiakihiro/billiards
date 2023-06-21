#include "TestScene.h"
#include "Ball.h"
#include "Player.h"
#include "Engine/Camera.h"
//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 50, 0));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));

	for (int i = 0; i < 9; i++) {
		Ball* b = Instantiate<Ball>(this);
		b->SetNumber(i + 1);
		b->SetPosition((i - 4) * 1.4, 0, (i - 4) * 1.4);
	}
	Player* p = Instantiate<Player>(this);
	Ball* b = Instantiate<Ball>(this);
	b->SetPosition(-10, 0, 0);
	b->SetNumber(0);
	p->SetMyBall(b);

}

//�X�V
void TestScene::Update()
{
	std::list<Ball*> balls = FindGameObjects<Ball>();
	for (auto itr1 = balls.begin(); itr1 != balls.end();itr1++) {
		for (auto itr2 = itr1; itr2 != balls.end(); itr2++) {
			if (itr1 == itr2)
				continue;
			XMVECTOR distance = (*itr1)-> GetPosition() - (*itr2)-> GetPosition();
			if (Length(distance) < 1.0 * 2.0f) {
				float depth = 1.0f * 2.0f - Length(distance);
				distance = XMVector3Normalize(distance) * depth / 2.0f;
				(*itr1)->SetPosition((*itr1)->GetPosition() + distance);
				(*itr2)->SetPosition((*itr2)->GetPosition() + distance*(-1.0f));
			}
		}
	}
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}