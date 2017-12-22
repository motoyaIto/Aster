//
//3Dオブジェクト
//ito motoya
//2017.12.20
#pragma once

#include <d3d11_1.h>
#include <memory>

#include <CommonStates.h>
#include <Effects.h>
#include <Model.h>
#include <SimpleMath.h>

class Obj3D
{
private:
	using Matrix = DirectX::SimpleMath::Matrix;
	using Vector3 = DirectX::SimpleMath::Vector3;
	using Quaternion = DirectX::SimpleMath::Quaternion;

private:
	std::unique_ptr<DirectX::EffectFactory> m_EffectFactory;//エフェクトファクトリ
	std::unique_ptr<DirectX::Model> m_model;			//3Dモデル
	std::unique_ptr<DirectX::CommonStates> m_states;	//汎用描画ステート

	Vector3 m_scale;	//大きさ
	Quaternion m_rotQ;	//回転(クオータニオン)
	Vector3 m_rotO;		//回転(オイラー角)
	Vector3 m_translation;//移動距離
	Matrix m_world;		//ワールド座標

public:
	Obj3D();
	~Obj3D();

	void Initialize();
	void UpdateO();
	void Render();

	void LoadModel(const wchar_t* fileName);//モデル読み込み

public://getter
	const Matrix& GetWorld() { return m_world; }

public://setter
	void SetScale(Vector3 scale) { m_scale = m_scale; }
	void SetRotQ(Quaternion rotQ) { m_rotQ = rotQ; }
	void SetRotO(Vector3 rotO) { m_rotO = rotO; }
	void SetTranslation(Vector3 translation) { m_translation = translation; }

};