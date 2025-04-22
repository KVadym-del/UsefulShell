#include "pch.h"
#include "UsefulShell.h"


USEFUL_SHELL_API std::filesystem::path UsefulShell::get_current_directory()
{
	boost::static_wstring<MAX_PATH> buffer;
	GetCurrentDirectoryW(MAX_PATH, buffer.data());
	return std::filesystem::path(buffer.data());
}

USEFUL_SHELL_API int get_current_directory(char* buffer, size_t size)
{
	std::string current_directory = UsefulShell::get_current_directory().string();
	if (current_directory.size() >= size)
	{
		return -1;
	}

	const gsl::span<char> buffer_span(buffer, size);

	std::copy_if(
		current_directory.begin(),
		current_directory.end(),
		buffer_span.begin(),
		[](char c) { return c != '\0'; }
	);

	buffer[current_directory.size()] = '\0';
	return 0; 
}
