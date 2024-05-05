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

include 'cngine/thirdparty/GLFW'


project 'cngine'
    location 'cngine'
    kind 'SharedLib'
    language 'C++'
    targetdir('bin/' .. outputdir .. '/%{prj.name}')
    objdir('bin-int/' .. outputdir .. '/%{prj.name}')

    pchheader 'cgpch.h'
    pchsource 'cngine/src/cgpch.cpp'

    files {
        '%{prj.name}/src/**.h',
        '%{prj.name}/src/**.cpp'
    }
    includedirs {
        '%{prj.name}/thirdparty/spdlog/include',
        '%{prj.name}/src',
        '%{IncludeDir.GLFW}'
    }
    links {
        'GLFW',
        'opengl32.lib'
    }

    filter 'system:windows'
        cppdialect 'C++17'
        staticruntime 'On'
        systemversion 'latest'

        defines {
            'CG_PLATFORM_WINDOWS',
            'CG_BUILD_DLL'
        }

        postbuildcommands {
            ('{COPY} %{cfg.buildtarget.relpath} ../bin/' .. outputdir .. '/Sandbox')
        }

    filter 'configurations:Debug'
        defines 'CG_DEBUG'
        symbols 'On'
    
    filter 'configurations:Release'
        defines 'CG_RELEASE'
        optimize 'On'

    filter 'configurations:Dist'
        defines 'CG_DIST'
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
        'cngine/src'
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
        symbols 'On'
    
    filter 'configurations:Release'
        defines 'CG_RELEASE'
        optimize 'On'

    filter 'configurations:Dist'
        defines 'CG_DIST'
        optimize 'On'