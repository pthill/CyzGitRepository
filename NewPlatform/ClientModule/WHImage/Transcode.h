#pragma once

#include <string>
using namespace std;

class Transcode
{
public:
	static void Unicode_to_UTF8(const wchar_t* in, size_t len, std::string& out);
	static void UTF8_to_Unicode(const char* in, size_t len, std::wstring& out);

	static void ANSI_to_Unicode(const char* in, size_t len, std::wstring& out);
	static void Unicode_to_ANSI(const wchar_t* in, size_t len, std::string& out);

	static void UTF8_to_ANSI(const char* in, size_t len, std::string& out);
	static void ANSI_to_UTF8(const char* in, size_t len, std::string& out);
};
