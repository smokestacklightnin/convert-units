#include <stack>
#include "unit_table.hpp"
#include <iostream>
#include <string>
void unittable::unittable::add_unit(const std::string &from_id, const std::string &to_id, float factor) {
  std::hash<std::string> str_hash;
  size_t from_id_hash(str_hash(from_id)), to_id_hash(str_hash(to_id));
  this->m_table[from_id_hash][to_id_hash] = factor;
  this->m_table[to_id_hash][from_id_hash] = 1. / factor;
}

float unittable::unittable::get_converstion(const size_t &from_hash, const size_t &to_hash, const float &to_convert) {
  return to_convert * this->get_unit_conversion(from_hash, to_hash);
}
float unittable::unittable::get_converstion(const std::string &from_id, const std::string &to_id, const float &to_convert) {
  std::hash<std::string> str_hash;
  size_t to_hash(str_hash(to_id)), from_hash(str_hash(from_id));
  return get_converstion(from_hash, to_hash, to_convert);
}


float unittable::unittable::get_unit_conversion(const std::string &from_id, const std::string &to_id) {
  std::hash<std::string> str_hash;
  size_t to_hash(str_hash(to_id)), from_hash(str_hash(from_id));
  return get_unit_conversion(from_hash, to_hash);
}

float unittable::unittable::get_unit_conversion(const size_t &from_hash, const size_t &to_hash) {
  std::unordered_map <size_t, std::pair<float, size_t >> m_visited;   // value and parent
  std::stack<size_t> m_stack;
  size_t prev_unit(from_hash), curr_unit;
  m_stack.push(from_hash);
  float output(-1.);

  while (!m_stack.empty()) {
    curr_unit = m_stack.top();
    m_stack.pop();
    m_visited[curr_unit] = std::pair<float, size_t>(this->m_table[prev_unit][curr_unit], prev_unit);
    prev_unit = curr_unit;

    for (std::map<size_t, float>::iterator it = this->m_table[curr_unit].begin(); it != this->m_table[curr_unit].end(); it++) {
      if (m_visited.find(it->first) == m_visited.end()) {
        m_stack.push(it->first);
      }
    }

    if (curr_unit == to_hash) {
      output = 0.; // success
      break;
    }
  }

  if (output == 0.) {
    prev_unit = m_visited[curr_unit].second;
    output = 1.0;

    while (curr_unit != from_hash) {
      output *=  this->m_table[prev_unit][curr_unit];
      curr_unit = prev_unit;
      prev_unit = m_visited[prev_unit].second;
    }
  }

  return output;
}
