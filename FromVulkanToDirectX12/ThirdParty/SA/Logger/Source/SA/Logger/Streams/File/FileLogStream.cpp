// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <filesystem>

#include <Streams/File/FileLogStream.hpp>

namespace SA
{
	FileLogStream::FileLogStream(const std::string& _fileFullPath) noexcept
	{
		CreateLogFile(_fileFullPath);
	}

	FileLogStream::~FileLogStream() noexcept
	{
		mHandle.close();
	}

	void FileLogStream::CreateLogFile(const std::string& _fileFullPath)
	{
		const size_t pathIndex = _fileFullPath.find_last_of("/\\");
	
		std::string filePath;
		std::string fileName;

		// Should create directory?
		if (pathIndex != std::string::npos)
		{
			filePath = _fileFullPath.substr(0u, pathIndex);
			fileName = _fileFullPath.substr(pathIndex);

			std::filesystem::create_directories(filePath);
		}
		else
			fileName = _fileFullPath;


		// Has extension?
		std::string fileExt;
		const size_t extIndex = _fileFullPath.rfind('.');

		if (extIndex != std::string::npos)
		{
			fileExt = _fileFullPath.substr(extIndex);
			fileName = fileName.substr(0u, extIndex);
		}


		// Log file already exists? Create backup.
		if (std::filesystem::exists(_fileFullPath))
		{
			// Query old file time info.
			DateTime backupStat = DateTime::FileStats(_fileFullPath);

			std::filesystem::rename(_fileFullPath.c_str(), (filePath + fileName + "_backup-" + ToString(backupStat) + fileExt).c_str());
		}

		mHandle.open(_fileFullPath, std::ios::out);
	}


	void FileLogStream::Flush()
	{
		mHandle.flush();
	}

	void FileLogStream::Output(const Log& _log)
	{
		mHandle << ToWString(_log) << std::endl;
	}
}
