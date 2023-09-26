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
  void add_unit(const std::string &from_id, const std::string &to_id, float factor);
 private:
  std::unordered_map< std::string, std::map< std::string,  float >> m_table;
};
}
#endif
