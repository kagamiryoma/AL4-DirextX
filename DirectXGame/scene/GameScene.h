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
#include "FollowCamera.h"
#include "Enemy.h"
#include "Title.h"
#include "GameClear.h"
#include "Fade.h"

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
	// 敵
	std::unique_ptr<Enemy> enemy_;
	// タイトル
	std::unique_ptr<Title> title_;
	// ゲームクリア
	std::unique_ptr<GameClear> gameClear_;
	// フェード
	std::unique_ptr<Fade> fade_;

	bool isDebugCameraActive_ = false;
	std::unique_ptr<DebugCamera> debugCamera_;

	// 追従カメラ
	std::unique_ptr<FollowCamera> followCamera_;

	std::unique_ptr<Model> modelFighterBody_;
	std::unique_ptr<Model> modelFighterHead_;
	std::unique_ptr<Model> modelFighterL_arm_;
	std::unique_ptr<Model> modelFighterR_arm_;
	std::unique_ptr<Model> modelEnemy_;

	// タイトル
	uint32_t textureHandleTitle_ = 0u;
	std::unique_ptr<Sprite> spriteTitle_;

	// エンターキー
	uint32_t textureHandleKey_ = 0u;
	std::unique_ptr<Sprite> spriteKey_;

	// ゲームクリア
	uint32_t textureHandleGameClear_ = 0u;
	std::unique_ptr<Sprite> spriteGameClear_;

	// フェード
	uint32_t textureHandleBlack_ = 0u;
	std::unique_ptr<Sprite> spriteBlack_;

	// シーンモード（０ : ゲームプレイ、 １ : タイトル、 ２ : ゲームクリア）
	uint32_t sceneMode_ = 1u;

	uint32_t hitCount_ = 0;

};
