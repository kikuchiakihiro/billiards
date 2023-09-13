//#pragma once
//#include "Engine/GameObject.h"
//
////���������Ǘ�����N���X
//class Button1 : public GameObject
//{
//    int hPict_;
//    int hPictD_;
//    
//public:
//
//    XMFLOAT3 center;
//    //�R���X�g���N�^
//    Button1(GameObject* parent);
//
//    //�f�X�g���N�^
//    ~Button1();
//
//    //������
//    void Initialize() override;
//
//    //�X�V
//    void Update() override;
//
//    //�`��
//    void Draw() override;
//
//    //�J��
//    void Release() override;
//
//    void SetPosition(int x, int y);
//};

#pragma once
#include "Engine/GameObject.h"

class Button : public GameObject {
public:
	Button(GameObject* parent);
	~Button();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	bool Finished(); // Button���I�������true
	void SetImage(std::string normal, std::string pushed);
	void SetPosition(int x, int y);
	void Push(bool pushed);
	bool MouseInArea(XMFLOAT3 mousePos);
	/// <summary>
	/// �{�^���ړ�
	/// </summary>
	/// <param name="toX">�ړ���̍��WX</param>
	/// <param name="toY">�ړ���̍��WY</param>
	/// <param name="seconds">�ړ�����(�b)</param>
	void SetMovePosition(int toX, int toY, float seconds);

	bool IsMoving();

	void ForceMoveEnd();
private:
	int hImage;
	int hPush;
	bool pushed;
	XMFLOAT3 center;
	XMFLOAT3 size;

	XMFLOAT3 startPos;
	XMFLOAT3 endPos;
	float totalTime;
	float currentTime;
	bool Moving;
};