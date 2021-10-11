workspace "shared_ptr"
	configurations { "Debug", "Release" }
	startproject "test"
	system "Windows"
	architecture "x64"

project "shared_ptr"
	kind "StaticLib"
	language "C++"
	location "src"

	targetdir "bin/shared_ptr"
	objdir "bin-obj/shared_ptr"

	files "src/shared_ptr.hpp"

	vpaths
	{
		["src"] = "shared_ptr.hpp"
	}

project "test"
	kind "ConsoleApp"
	language "C++"
	location "test"

	targetdir "bin/test"
	objdir "bin-obj/test"
	includedirs "src"

	files "test/test.cpp"

	vpaths
	{
		["src"] = "test.cpp"
	}

