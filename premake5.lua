workspace 'cngine'
    architecture 'x64'
    configurations {
        'Debug',
        'Release',
        'Dist'
    }

outputdir = '%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir['GLFW'] = 'cngine/thirdparty/GLFW/include'
IncludeDir['GLAD'] = 'cngine/thirdparty/GLAD/include'
IncludeDir['imgui'] = 'cngine/thirdparty/imgui'
IncludeDir['glm'] = 'cngine/thirdparty/glm'
IncludeDir["stb_image"] = "cngine/thirdparty/stb_image"

include 'cngine/thirdparty/GLFW'
include 'cngine/thirdparty/GLAD'
include 'cngine/thirdparty/imgui'


project 'cngine'
    location 'cngine'
    kind 'StaticLib'
    language 'C++'
    cppdialect 'C++17'
    staticruntime 'On'

    targetdir('bin/' .. outputdir .. '/%{prj.name}')
    objdir('bin-int/' .. outputdir .. '/%{prj.name}')

    pchheader 'cgpch.h'
    pchsource 'cngine/src/cgpch.cpp'

    files {
        '%{prj.name}/src/**.h',
        '%{prj.name}/src/**.cpp',
        '%{prj.name}/thirdparty/glm/**.hpp',
        '%{prj.name}/thirdparty/glm/**.inl',
        "%{prj.name}/thirdparty/stb_image/**.h",
		"%{prj.name}/thirdparty/stb_image/**.cpp",
    }

    defines
    {
        '_CRT_SECURE_NO_WARNINGS'
    }
    includedirs {
        '%{prj.name}/thirdparty/spdlog/include',
        '%{prj.name}/src',
        '%{IncludeDir.GLFW}',
        '%{IncludeDir.GLAD}',
        '%{IncludeDir.imgui}',
        '%{IncludeDir.glm}',
        "%{IncludeDir.stb_image}"
    }
    links {
        'GLFW',
        'GLAD',
        'imgui',
        'opengl32.lib'
    }

    filter 'system:windows'
        staticruntime 'On'
        systemversion 'latest'

        defines {
            'CG_PLATFORM_WINDOWS',
            'CG_BUILD_DLL',
            'GLFW_INCLUDE_NONE'
        }
 

    filter 'configurations:Debug'
        defines 'CG_DEBUG'
        buildoptions "/MDd"
        symbols 'On'
    
    filter 'configurations:Release'
        defines 'CG_RELEASE'
        buildoptions "/MD"
        optimize 'On'

    filter 'configurations:Dist'
        defines 'CG_DIST'
        buildoptions "/MD"
        optimize 'On'

project 'Sandbox'
    location 'Sandbox'
    kind 'ConsoleApp'
    language 'C++'
    targetdir('bin/' .. outputdir .. '/%{prj.name}')
    objdir('bin-int/' .. outputdir .. '/%{prj.name}')
    files {
        '%{prj.name}/src/**.h',
        '%{prj.name}/src/**.cpp'
    }
    includedirs {
        'cngine/thirdparty/spdlog/include',
        'cngine/src',
        '%{IncludeDir.glm}',
        "cngine/thirdparty",
    }
    links {
        'cngine'
    }

    filter 'system:windows'
        cppdialect 'C++17'
        staticruntime 'On'
        systemversion 'latest'

        defines {
            'CG_PLATFORM_WINDOWS'
        }

    filter 'configurations:Debug'
        defines 'CG_DEBUG'
        buildoptions "/MDd"
        symbols 'On'
    
    filter 'configurations:Release'
        defines 'CG_RELEASE'
        buildoptions "/MD"
        optimize 'On'

    filter 'configurations:Dist'
        defines 'CG_DIST'
        buildoptions "/MD"
        optimize 'On'