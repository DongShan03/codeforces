workspace "CodeForces"
    configurations { "Debug", "Release" }
    language "C++"
    location "build"
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"


project "CodeForces"
    kind "ConsoleApp"
    language "C++"
    targetdir "build/%{cfg.buildcfg}"
    files { "**.hpp", "**.cpp", "headers/**.hpp" }
