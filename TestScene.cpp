#include "TestScene.h"
#include "Ball.h"
#include "Player.h"
#include "Gauge.h"
#include "Ready.h"
#include "Engine/Camera.h"
//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
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
	Gauge* g = Instantiate<Gauge>(this); 
	Instantiate<Ready>(this);
	b->SetPosition(-10, 0, 0);
	b->SetNumber(0);
	p->SetMyBall(b);
	g->SetPosition(0.8, -0.5);
}

//更新
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

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
