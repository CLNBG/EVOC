project("EVOC_SPI")
kind("ConsoleApp")
language("C")
cdialect("C17")

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

files({
	"%{wks.location}/NMROSCore/src/NMROSCore/Utils/SPI/SPI.h",
	"%{wks.location}/NMROSCore/src/NMROSCore/Utils/SPI/SPI.cpp",
	"src/spi_test.cpp",
})

includedirs({
	"%{IncludeDir.EVOC}",
	"%{wks.location}/NMROSCore/src/NMROSCore/Utils/SPI",
})

libdirs({
	"%{LinkDir.EVOC}",
})

links({
	"BPI41-x64.lib",
})

defines({
	"PC_VENDOR_YX",
})

debugenvs({
	"path=" .. os.getenv("path") .. ";" .. "%{dllDir.EVOC}",
})

postbuildcommands({ "{COPY} %{IncludeDir.EVOC}/config.ini  %{cfg.targetdir}" })

filter("system:windows")
systemversion("latest")

filter("configurations:Debug")
runtime("Debug")
symbols("on")
staticruntime("off")

filter("configurations:Release")
runtime("Release")
optimize("on")
staticruntime("on")
