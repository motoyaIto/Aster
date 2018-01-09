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

	std::unique_ptr<Obj3D>* m_FildCube;//床
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//ビュー行列
	DirectX::SimpleMath::Matrix m_view;//ビュー行列(カメラを基準とした座標系に変換)

	DirectX::SimpleMath::Vector3 m_pos;//カメラの位置(eyepos)
	DirectX::SimpleMath::Vector3 m_targetPos;//参照点(見る場所 refpos)
	DirectX::SimpleMath::Vector3 m_upvec;//上方向ベクトル(カメラの上側を指す)

	//プロジェクション行列(射影行列)
	DirectX::SimpleMath::Matrix m_proj;//プロジェクション行列(ビュー行列をもとにスクリーン中央を基準とした座標系に変換)
	
	float m_fovY;//縦の写す範囲(垂直方向視野角)
	float m_aspect;//縦横の比率(アスペクト比)
	float m_nearClip;//手前の表示限界距離(ニアクリップ)
	float m_farClip;//奥の表示限界距離

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
};