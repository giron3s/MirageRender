#ifndef WAVEFRONT_FILE_H
#define WAVEFRONT_FILE_H

// std includes
#include <string>
#include <vector>
#include <map>

// mirage includes
#include "../math/vec3.h"
#include "../math/vec2.h"

namespace mirage
{

	// ---------------------------------------------------------------------------
	// WavefrontFace
	// ---------------------------------------------------------------------------

	class WavefrontFace
	{
	public:
		std::vector<int> points;
		std::vector<int> normals;
		std::vector<int> texcoords;
		std::string material;

		WavefrontFace(const std::string & material = "NULL") :
			points(3),
			normals(3),
			texcoords(3),
			material(material)
		{

		}
	};

	// ---------------------------------------------------------------------------
	// WavefrontMaterial
	// ---------------------------------------------------------------------------

	class WavefrontMaterial
	{
	public:
		uint16_t illum; // Illumination mode
		std::string KdText; // Diffuse texture
		std::string KsText; // Specular texture
		std::string KeText; // Emissive texture
		vec3 Ka; // Ambient color
		vec3 Kd; // Diffuse color
		vec3 Ks; // Specular color
		vec3 Ke; // Emissive color
		double Ns; // Specular exponent
		double Ni; // Index of refraction
		double Fr; // Fresnel reflectance

		WavefrontMaterial(
			const uint16_t illum = 0,
			const std::string & KdText = "",
			const std::string & KsText = "",
			const std::string & KeText = "",
			const vec3 & Ka = vec3(),
			const vec3 & Kd = vec3(),
			const vec3 & Ks = vec3(),
			const vec3 & Ke = vec3(),
			const double Ns = 100.0f,
			const double Ni = 1.0f,
			const double Fr = 0.75f
		) :
			illum(illum),
			KdText(KdText),
			KsText(KsText),
			KeText(KeText),
			Ka(Ka),
			Kd(Kd),
			Ks(Ks),
			Ke(Ke),
			Ns(Ns),
			Ni(Ni),
			Fr(Fr)
		{

		}
	};

	// ---------------------------------------------------------------------------
	// WavefrontMesh
	// ---------------------------------------------------------------------------

	class WavefrontMesh
	{
	public:
		std::vector<WavefrontFace> faces;
		bool hasNormals;
		bool hasTexcoords;

		WavefrontMesh() :
			faces(0),
			hasNormals(false),
			hasTexcoords(false)
		{

		}
	};

	// ---------------------------------------------------------------------------
	// WavefrontFile
	// ---------------------------------------------------------------------------

	class WavefrontFile
	{
	public:
		WavefrontFile(const std::string & filePath = "NULL");
		void loadObj(const std::string & filePath);
		void loadMtl(const std::string & filePath);
		const std::vector<vec3> & getPoints() const;
		const std::vector<vec3> & getNormals() const;
		const std::vector<vec2> getTexcoords() const;
		const std::map<std::string, WavefrontMesh> & getMeshes() const;
		const std::map<std::string, WavefrontMaterial> & getMaterials() const;
	private:
		std::string m_objFilePath;
		std::string m_mtlFilePath;
		std::vector<vec3> m_points;
		std::vector<vec3> m_normals;
		std::vector<vec2> m_texcoords;
		std::map<std::string, WavefrontMesh> m_meshes;
		std::map<std::string, WavefrontMaterial> m_materials;
	};

}

#endif // WAVEFRONT_FILE_H