#pragma once
#ifndef _H_SHADER_SOURCE
#define _H_SHADER_SOURCE

#include <string>

	
namespace Visualizer
{

// Read the Vertex Shader code from the file
static std::string VertexShaderCode_Render
= "#version 330 core\n\
		  \
			uniform mat4 modelViewProj;\n\
			in vec3 position;\n\
			in vec4 colors;\n\
			smooth out vec4 color;\n\
			 \
			void main()\
			{\
				color = colors;\
				gl_Position = modelViewProj * vec4(position, 1.0);\n\
			} "
	;
	
// Read the Fragment Shader code from the file
static std::string FragmentShaderCode_Render
= "#version 330 core\n\
	  	\
			smooth in vec4 color;\n\
			uniform vec4 uColor;\n\
			out vec4 out_color;\n\
			\
			void main()\
			{\
				out_color = color;\
			} ";


// Read the Fragment Shader code from the file
static std::string FragmentShaderCode_Render2
= "#version 330 core\n\
	  	\
			smooth in vec4 color;\n\
			uniform vec4 uColor;\n\
			uniform bool fill; \n\
			out vec4 out_color;\n\
			\
			void main()\
			{\
				if(fill)\
				   out_color = color;\
				else\
					out_color = vec4(0.7f, 0.7f, 0.7f, 0.7f);\
			} ";

// Read the Fragment Shader code from the file
static std::string FragmentShaderCode_Render2_ToneMap
= "#version 330 core\n\
\
smooth in vec4 color;\
uniform vec4 uColor;\
uniform bool fill;\
uniform bool tonemap;\
uniform float invWhitePoint;\
uniform float invGamma;\
out vec4 out_color;\
\
void main()\
{\
	if(fill) {\
		out_color = color;\
		if (tonemap) out_color.rgb = pow(invWhitePoint*out_color.rgb,vec3(invGamma));\
	} else {\
		out_color = vec4(0.7f, 0.7f, 0.7f, 0.7f);\
	}\
} ";


// Read the Fragment Shader code from the file
static std::string FragmentShaderCode_Line_Render
		= "#version 330 core\n\
	  	\
			smooth in vec4 color;\n\
			uniform vec4 uColor;\n\
			out vec4 out_color;\n\
			\
			void main()\
			{\
				out_color = vec4(1.0f,0.0f,0.0f,1.0f);\
			} ";

}

#endif //_H_SHADER_SOURCE