#ifndef UNIT_TABLE
#define UNIT_TABLE
#include <string>
#include <map>
#include <unordered_map>
namespace unittable {
class unittable {
 public:
  float get_converstion(const std::string &from_id, const std::string &to_id, const float &to_convert);
  float get_unit_conversion(const std::string &from_id, const std::string &to_id);
  float get_converstion(const size_t &from_hash, const size_t &to_hash, const float &to_convert);
  float get_unit_conversion(const size_t &from_hash, const size_t &to_hash);
  void add_unit(const std::string &from_id, const std::string &to_id, float factor);
 private:
  std::unordered_map<size_t, std::map<size_t, float>> m_table;
};
}
#endif
