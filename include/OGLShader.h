#include "ShaderBase.h"
#include "glad\glad.h"

class OGLShader : public ShaderBase
{
public:
	friend class OGLRenderer;
	OGLShader(const string& vertex, const string& fragment, const string& geometry = "", const string& domain = "", const string& hull = "");
	~OGLShader();

	void ReloadShader() override;

	bool LoadSuccess() const {
		return programValid == GL_TRUE;
	}

	int GetProgramID() const {
		return programID;
	}

	static void	PrintCompileLog(GLuint object);
	static void	PrintLinkLog(GLuint program);

protected:
	void	DeleteIDs();

	GLuint	programID;
	GLuint	shaderIDs[ShaderStages::SHADER_MAX];
	int		shaderValid[ShaderStages::SHADER_MAX];
	int		programValid;
};
