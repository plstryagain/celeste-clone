#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

namespace plstryagain {

namespace utils {

std::filesystem::file_time_type get_file_timestamp(const std::filesystem::path& file_path);
bool is_file_exists(const std::filesystem::path& file_path);
std::uintmax_t get_file_size(const std::filesystem::path& file_path);
std::vector<std::byte> read_file(const std::filesystem::path& file_path);

} // namespace utils

} // namespace plstryagain