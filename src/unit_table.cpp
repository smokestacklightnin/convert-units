#include "unit_table.hpp"

void unittable::unittable::add_unit(std::string from_id, std::string to_id, float factor) {
  this->m_table[from_id][to_id] = factor;
  this->m_table[to_id][from_id] = 1. / factor;
}

float unittable::unittable::get_converstion(std::string from_id, std::string to_id, const float &to_convert) {
  return to_convert * this->get_unit_conversion(from_id, to_id);
}

float unittable::unittable::get_unit_conversion(std::string from_id, std::string to_id) {
  return 0;
}
