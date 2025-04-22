#pragma once
#ifndef USEFUL_SHELL_H
#define USEFUL_SHELL_H

#define USEFUL_SHELL_API __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

	USEFUL_SHELL_API int get_current_directory(char* buffer, size_t size);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <filesystem>

class UsefulShell
{
public:
	USEFUL_SHELL_API static std::filesystem::path get_current_directory();
};

#endif // __cplusplus

#endif // USEFUL_SHELL_H