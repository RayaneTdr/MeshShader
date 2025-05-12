// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <cwchar>

#include <Preprocessors/FileName.hpp>

namespace SA::Intl
{
	const wchar_t* FileNameFromPath(const wchar_t* _filePath) noexcept
	{
		// Remove characters until last backslash.
		const wchar_t* fileName = std::wcsrchr(_filePath, '\\');

		if (!fileName) // No backslash found.
			fileName = _filePath;
		else
			fileName += 1; // Remove last '\\' found.


		// Remove characters until last slash.
		if (const wchar_t* filePathNoSlash = std::wcsrchr(fileName, '/'))
		{
			// Remove last '/' found.
			fileName = filePathNoSlash + 1;
		}

		return fileName;
	}
}
