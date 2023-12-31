#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h"
#include <memory>
#include "Skydome.h"
#include "Ground.h"
#include "DebugCamera.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	/// // テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// ビュープロジェクション
	ViewProjection viewProjection_;
	// モデル
	std::unique_ptr<Model> model_;
	// 自キャラ
	std::unique_ptr<Player> player_;
	// 天球
	std::unique_ptr<Skydome> skydome_;
	// 天球モデル
	std::unique_ptr<Model> modelSkydome_;
	// 地面
	std::unique_ptr<Ground> ground_;
	// 地面モデル
	std::unique_ptr<Model> modelGround_;

	bool isDebugCameraActive_ = false;
	DebugCamera* debugCamera_ = nullptr;
};
