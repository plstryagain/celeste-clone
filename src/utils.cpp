#include "utils.h"
#include <fstream>


namespace plstryagain {

namespace utils {

std::filesystem::file_time_type get_file_timestamp(const std::filesystem::path& file_path)
{
    return std::filesystem::last_write_time(file_path);
}

bool is_file_exists(const std::filesystem::path& file_path)
{
    return std::filesystem::exists(file_path);
}

std::uintmax_t get_file_size(const std::filesystem::path& file_path)
{
    return std::filesystem::file_size(file_path);
}

std::vector<std::byte> read_file(const std::filesystem::path& file_path)
{
    std::ifstream file{file_path, std::ios::binary | std::ios::ate};
    if (!file) {
        throw std::runtime_error(file_path.u8string() + ": " + std::strerror(errno));
    }
    auto end = file.tellg();
    file.seekg(0, std::ios::beg);
    auto size = static_cast<size_t>(end - file.tellg());

    if (size == 0) {
        return {};
    }
    std::vector<std::byte> buffer{size};
    if (!file.read(reinterpret_cast<char*>(buffer.data()), buffer.size())) {
        throw std::runtime_error(file_path.u8string() + ": " + std::strerror(errno));
    }
    return buffer;
}

} // namespace utils

} // namespace plstryagain