//
//3D�I�u�W�F�N�g
//ito motoya
//2017.12.20
#include "Obj3D.h"

#include "..//DirectXResources.h"

Obj3D::Obj3D()
	: m_world(Matrix::Identity)
	, m_scale(Vector3::Zero)
	, m_rotQ(Quaternion::Identity)
	, m_rotO(Vector3::Zero)
	, m_translation(Vector3::Zero)
{
	//�G�t�F�N�g�t�@�N�g���̍쐬
	m_EffectFactory = std::make_unique<DirectX::EffectFactory>(DirectXResources::m_d3dDevice.Get());
	
	//�e�N�X�`���p�X
	m_EffectFactory->SetDirectory(L"Resources");

	//�ėp�`��X�e�[�g
	m_states = std::make_unique<DirectX::CommonStates>(DirectXResources::m_d3dDevice.Get());
}

Obj3D::~Obj3D()
{
}

void Obj3D::Initialize()
{
	
}

void Obj3D::UpdateO()
{
	//�T�C�Y�s��
	Matrix scale = Matrix::CreateScale(m_scale);

	//��]�s��
	Matrix rot;

	Matrix rotX = Matrix::CreateRotationX(m_rotO.x);
	Matrix rotY = Matrix::CreateRotationY(m_rotO.y);
	Matrix rotZ = Matrix::CreateRotationZ(m_rotO.z);

	rot = rotX * rotY * rotZ;

	//�ړ��s��
	Matrix translation = Matrix::CreateTranslation(m_translation);

	//���[���h�s��̌v�Z
	m_world = scale * rot * translation;
}

void Obj3D::UpdateQ()
{
	//�T�C�Y�s��
	Matrix scale = Matrix::CreateScale(m_scale);

	//��]�s��
	Matrix rot = Matrix::CreateFromQuaternion(m_rotQ);

	//�ړ��s��
	Matrix translation = Matrix::CreateTranslation(m_translation);

	//���[���h�s��̌v�Z
	m_world = scale * rot * translation;


}

void Obj3D::Render()
{
	if (m_model)
	{
		m_model->Draw(DirectXResources::m_d3dContext.Get(), *m_states, m_world, Matrix::Identity/*m_view*/, Matrix::Identity/*m_proj*/);
	}
}

/// <summary>
/// ���f���ǂݍ���
/// </summary>
/// <param name="fileName">���f����</param>
void Obj3D::LoadModel(const wchar_t * fileName)
{
	m_model = DirectX::Model::CreateFromCMO(DirectXResources::m_d3dDevice.Get(), fileName, *m_EffectFactory);
}
