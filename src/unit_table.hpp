#ifndef UNIT_TABLE
#define UNIT_TABLE
#include <string>
#include <unordered_map>
namespace unittable {
class unittable {
 public:
  float get_converstion(std::string from_id, std::string to_id, const float &to_convert);
  float get_unit_conversion(std::string from_id, std::string to_id);
  void add_unit(std::string from_id, std::string to_id, float factor);
 private:
  bool dfs();
  bool dfs_util(std::string id);
  std::unordered_map<std::string, std::unordered_map<std::string, float>> m_table;
  std::unordered_map < std::string, float> m_visited;
};
}
#endif
