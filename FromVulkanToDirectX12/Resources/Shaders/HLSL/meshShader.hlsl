struct VertexOutput
{
	float3 Position : POSITION;
	float3 Normal : NORMAL;

	/// Shader view position
    float4 svPosition : SV_POSITION;

	/// Camera view position.
    float3 viewPosition : VIEW_POSITION;


	/// TBN (tangent, bitangent, normal) transformation matrix.
    float3x3 TBN : TBN;


	/// Vertex UV
    float2 uv : TEXCOORD;
};

struct Camera
{
	/// Camera transformation matrix.
    float4x4 view;

	/**
	*	Camera inverse view projection matrix.
	*	projection * inverseView.
	*/
    float4x4 invViewProj;
};

cbuffer CameraBuffer : register(b0)
{
    Camera camera;
};

struct Object
{
	/// Object transformation matrix.
    float4x4 transform;
};
cbuffer ObjectBuffer : register(b1)
{
    Object object;
};

struct Meshlet
{
	/*
	uint vertCount;
	uint primCount;
	float3 Vertices[MaxVertexCount];
	uint3 Indices[MaxTriangleCount];*/
	
    uint32_t vertexCount;
    uint32_t vertexOffset;
    uint32_t primitivesCount;
    uint32_t primitivesOffset;
};

StructuredBuffer<Meshlet> meshlets : register(t5);
StructuredBuffer<float3> vertexBufferPositions : register(t6);
StructuredBuffer<uint> vertexIndices : register(t7);
StructuredBuffer<uint> primitiveIndices : register(t8);

[outputtopology("triangle")]
[numthreads(128, 1, 1)]
void mainMS(
    uint grpid : SV_GroupID,
    uint grpTid : SV_GroupThreadID,
    out vertices VertexOutput outVerts[128],
    out indices uint3 outIndices[128] 
)
{
    Meshlet meshlet = meshlets[grpid];
    SetMeshOutputCounts(meshlet.vertexCount, meshlet.primitivesCount);
	
	if(grpTid < meshlet.vertexCount)
    {
        uint vertexIndex = vertexIndices[meshlet.vertexOffset + grpTid];
        float4 pos = float4(vertexBufferPositions[vertexIndex], 1.0f);
		
        const float4 worldPosition4 = mul(pos, object.transform);
        outVerts[grpTid].Position = worldPosition4.xyz / worldPosition4.w;
        outVerts[grpTid].svPosition = mul(worldPosition4, camera.invViewProj);
        outVerts[grpTid].viewPosition = float3(camera.view._14, camera.view._24, camera.view._34);
		
        const float3 normal = normalize(mul((float3x3) object.transform, pos.xyz));
        const float3 tangent = normalize(mul((float3x3) object.transform, pos.xyz));
        const float3 bitangent = cross(normal, tangent);
		
		// HLSL uses row-major constructor: transpose to get TBN matrix.
        outVerts[grpTid].TBN = transpose(float3x3(tangent, bitangent, normal));


		//---------- UV ----------
        outVerts[grpTid].uv = pos.xy;
    }
	
	if(grpTid < meshlet.primitivesCount)
    {
        uint packedIndices = primitiveIndices[meshlet.primitivesOffset + grpTid];
        outIndices[grpTid] = uint3(packedIndices & 0x3FF,
			(packedIndices >> 10) & 0x3FF,
			(packedIndices >> 20) & 0x3FF);
    }
	
	
	/*
	if (gtid == 0)
		m = meshlets[gid];

	GroupMemoryBarrierWithGroupSync(); 

	SetMeshOutputCounts(m.vertCount, m.primCount);
	
	if (gtid < m.primCount)
	{
		outTriangles[gtid] = m.Indices[gtid];
	}

	if (gtid < m.vertCount)
	{
		VertexOutput vout;
		vout.Position = m.Vertices[gtid];
		vout.Normal = float3(0, 0, 1);
		outVertices[gtid] = vout;
	}*/
}