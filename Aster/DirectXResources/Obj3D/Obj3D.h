//
//3D�I�u�W�F�N�g
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
	std::unique_ptr<DirectX::EffectFactory> m_EffectFactory;//�G�t�F�N�g�t�@�N�g��
	std::unique_ptr<DirectX::Model> m_model;			//3D���f��
	std::unique_ptr<DirectX::CommonStates> m_states;	//�ėp�`��X�e�[�g

	Vector3 m_scale;	//�傫��
	Quaternion m_rotQ;	//��](�N�I�[�^�j�I��)
	Vector3 m_rotO;		//��](�I�C���[�p)
	Vector3 m_translation;//�ړ�����
	Matrix m_world;		//���[���h���W

public:
	Obj3D();
	~Obj3D();

	void Initialize();
	void UpdateO();
	void Render();

	void LoadModel(const wchar_t* fileName);//���f���ǂݍ���

public://getter
	const Matrix& GetWorld() { return m_world; }

public://setter
	void SetScale(Vector3 scale) { m_scale = m_scale; }
	void SetRotQ(Quaternion rotQ) { m_rotQ = rotQ; }
	void SetRotO(Vector3 rotO) { m_rotO = rotO; }
	void SetTranslation(Vector3 translation) { m_translation = translation; }

};