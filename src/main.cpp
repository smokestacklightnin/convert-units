#include <iostream>
#include "unit_table.hpp"
int main() {
  std::cout << "Units" << std::endl;
  unittable::unittable U;
  U.add_unit("ft", "in", 12);
  U.add_unit("mi", "ft", 5280);
  U.add_unit("in", "cm", 2.54);
  U.add_unit("m", "cm", 100);
  U.add_unit("km", "m", 1000);
  std::cout << U.get_unit_conversion("mi", "km") << '\t' << 1.60934 << std::endl;
  return 0;
}
