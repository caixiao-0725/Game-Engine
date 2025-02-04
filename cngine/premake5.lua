project 'cngine'
    kind 'StaticLib'
    language 'C++'
    cppdialect 'C++17'
    staticruntime 'On'

    targetdir("%{wks.location}/bin/" .. outputdir .. '/%{prj.name}')
    objdir('%{wks.location}/bin-int/' .. outputdir .. '/%{prj.name}')

    pchheader 'cgpch.h'
    pchsource 'src/cgpch.cpp'

    files {
        'src/**.h',
        'src/**.cpp',
        'thirdparty/glm/**.hpp',
        'thirdparty/glm/**.inl',
        "thirdparty/stb_image/**.h",
		"thirdparty/stb_image/**.cpp",
    }

    defines
    {
        '_CRT_SECURE_NO_WARNINGS',
        "GLFW_INCLUDE_NONE"
    }
    includedirs {
        'thirdparty/spdlog/include',
        'src',
        '%{IncludeDir.GLFW}',
        '%{IncludeDir.GLAD}',
        '%{IncludeDir.imgui}',
        '%{IncludeDir.glm}',
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.yaml_cpp}"
    }
    links {
        'GLFW',
        'GLAD',
        'imgui',
        'opengl32.lib',
        "yaml-cpp"
    }

    filter 'system:windows'
        systemversion 'latest'

        defines {
        }
 

    filter 'configurations:Debug'
        defines 'CG_DEBUG'
        runtime 'Debug'
        symbols 'On'
    
    filter 'configurations:Release'
        defines 'CG_RELEASE'
        runtime 'Release'
        optimize 'On'

    filter 'configurations:Dist'
        defines 'CG_DIST'
        runtime 'Release'
        optimize 'On'
