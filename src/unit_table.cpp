#include <stack>
#include "unit_table.hpp"
#include <iostream>
void unittable::unittable::add_unit(const std::string &from_id, const std::string &to_id, float factor) {
  this->m_table[from_id][to_id] = factor;
  this->m_table[to_id][from_id] = 1. / factor;
}

float unittable::unittable::get_converstion(const std::string &from_id, const std::string &to_id, const float &to_convert) {
  return to_convert * this->get_unit_conversion(from_id, to_id);
}

float unittable::unittable::get_unit_conversion(const std::string &from_id, const std::string &to_id) {
  std::unordered_map <  std::string, std::pair< float,  std::string >> m_visited;   // value and parent
  m_visited.clear();
  std::stack<std::string> m_stack;
  std::string prev_unit(from_id), curr_unit("");
  m_stack.push(from_id);
  float output = -1.;

  while (!m_stack.empty()) {
    curr_unit = m_stack.top();
    m_stack.pop();
    m_visited[curr_unit] = std::pair<float, std::string>(this->m_table[prev_unit][curr_unit], prev_unit);
    prev_unit = curr_unit;

    for (auto it = (this->m_table)[curr_unit].begin(); it != (this->m_table)[curr_unit].end(); it++) {
      if (m_visited.find(it->first) == m_visited.end()) {
        m_stack.push(it->first);
      }
    }

    if (curr_unit == to_id) {
      output = 0.; // success
      break;
    }
  }

  if (output == 0) {
    prev_unit = m_visited[curr_unit].second;
    output = 1.0;

    while (curr_unit != from_id) {
      output *=  this->m_table[prev_unit][curr_unit];
      curr_unit = prev_unit;
      prev_unit = m_visited[prev_unit].second;
    }
  }

  return output;
}
