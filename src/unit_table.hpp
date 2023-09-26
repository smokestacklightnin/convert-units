#ifndef UNIT_TABLE
#define
#include <string>
#include <unordered_map>
namespace unittable {
class unittable {
 public:
  float get_converstion(const float &to_convert);
  float get_unit_conversion(const float &to_convert);
  void add_unit(std::string from_id, std::string to_id, float factor);
 private:
  bool dfs();
  bool dfs_util(std::string id);
  unordered_map<std::string, unordered_map<std::string, float>> m_table;
  unordered_map < std::string, float> m_visited;
}
}
#endif
