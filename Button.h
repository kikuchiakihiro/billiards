//#pragma once
//#include "Engine/GameObject.h"
//
////◆◆◆を管理するクラス
//class Button1 : public GameObject
//{
//    int hPict_;
//    int hPictD_;
//    
//public:
//
//    XMFLOAT3 center;
//    //コンストラクタ
//    Button1(GameObject* parent);
//
//    //デストラクタ
//    ~Button1();
//
//    //初期化
//    void Initialize() override;
//
//    //更新
//    void Update() override;
//
//    //描画
//    void Draw() override;
//
//    //開放
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
	bool Finished(); // Buttonが終わったらtrue
	void SetImage(std::string normal, std::string pushed);
	void SetPosition(int x, int y);
	void Push(bool pushed);
	bool MouseInArea(XMFLOAT3 mousePos);
	/// <summary>
	/// ボタン移動
	/// </summary>
	/// <param name="toX">移動後の座標X</param>
	/// <param name="toY">移動後の座標Y</param>
	/// <param name="seconds">移動時間(秒)</param>
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