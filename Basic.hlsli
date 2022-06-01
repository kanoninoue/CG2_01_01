//定数バッファ用データ構造体（マテリアル）
cbuffer ConstBufferDataMaterial : register(b0)
{
	float4 color; //色(RGBA)
};

//頂点シェーダ―の出力構造体
//(頂点シェーダ―からピクセルシェーダ―へのやり取りに使用する)
struct VSOutput
{
	//システム用頂点座標
	float4 svpos : SV_POSITION;
	//uv値
	float2 uv : TEXCOORD;
};
