#pragma once

#define LOG_ERROR(expr, file, line, function) std::cerr << "Assertion failed: " << expr << "\nFile: " << file << "\nLine: " << line << "\nFunction: " << function << std::endl;
#define VERIFY(expr) if (!static_cast<bool>(expr)) { LOG_ERROR(#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__); }
#define TODO() LOG_ERROR("TODO", __FILE__, __LINE__, __PRETTY_FUNCTION__)