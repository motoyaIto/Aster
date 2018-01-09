//
// Game.h
//

#pragma once

#include "StepTimer.h"

#include "DirectXResources//Obj3D//Obj3D.h"

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <Effects.h>
#include <Model.h>
#include <SimpleMath.h>
#include <CommonStates.h>
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	std::unique_ptr<Obj3D>* m_FildCube;//��
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//�r���[�s��
	DirectX::SimpleMath::Matrix m_view;//�r���[�s��(�J��������Ƃ������W�n�ɕϊ�)

	DirectX::SimpleMath::Vector3 m_pos;//�J�����̈ʒu(eyepos)
	DirectX::SimpleMath::Vector3 m_targetPos;//�Q�Ɠ_(����ꏊ refpos)
	DirectX::SimpleMath::Vector3 m_upvec;//������x�N�g��(�J�����̏㑤���w��)

	//�v���W�F�N�V�����s��(�ˉe�s��)
	DirectX::SimpleMath::Matrix m_proj;//�v���W�F�N�V�����s��(�r���[�s������ƂɃX�N���[����������Ƃ������W�n�ɕϊ�)
	
	float m_fovY;//�c�̎ʂ��͈�(������������p)
	float m_aspect;//�c���̔䗦(�A�X�y�N�g��)
	float m_nearClip;//��O�̕\�����E����(�j�A�N���b�v)
	float m_farClip;//���̕\�����E����

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
};