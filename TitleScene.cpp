#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Botton1.h"
#include "Botton2.h"
#include "Engine/SceneManager.h"
//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), pText(nullptr)
{
}

//������
void TitleScene::Initialize()
{
	Instantiate<Botton1>(this);
	Instantiate<Botton2>(this);
	pText = new Text;
	pText->Initialize();
}

//�X�V
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

//�`��
void TitleScene::Draw()
{
	
	
	pText->Draw(600, 600, "PUSH Enter");

}

//�J��
void TitleScene::Release()
{
}
