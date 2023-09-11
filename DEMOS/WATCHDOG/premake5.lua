project "EVOC_WDT"
	kind "ConsoleApp"
	language "C"
	cdialect "C17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.c"
	}
	
	includedirs
	{
		"%{IncludeDir.EVOC}"
	}
	
	libdirs
	{
		"%{LinkDir.EVOC}"
	}
	
	links
	{
		"BPI41-x64.lib"
	}

    debugenvs
    {
      "path=" .. os.getenv("path") .. ";" .. "%{dllDir.EVOC}"
    }
	
	postbuildcommands {"{COPY} %{IncludeDir.EVOC}/config.ini  %{cfg.targetdir}" }

    filter "system:windows"
        systemversion "latest"
        
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
        staticruntime "off"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
        staticruntime "on"
