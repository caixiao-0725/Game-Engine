project 'Sandbox'
    kind 'ConsoleApp'
    language 'C++'
    targetdir("%{wks.location}/bin/" .. outputdir .. '/%{prj.name}')
    objdir('%{wks.location}/bin-int/' .. outputdir .. '/%{prj.name}')

    files {
        'src/**.h',
        'src/**.cpp'
    }
    includedirs {
        '%{wks.location}/cngine/thirdparty/spdlog/include',
        '%{wks.location}/cngine/src',
        "%{wks.location}/cngine/thirdparty",
        '%{IncludeDir.glm}',
        "%{IncludeDir.entt}",
    }
    links {
        'cngine'
    }

    filter 'system:windows'
        cppdialect 'C++17'
        staticruntime 'On'
        systemversion 'latest'

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
