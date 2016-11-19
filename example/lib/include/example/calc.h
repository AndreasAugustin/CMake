
/**
 * @author andy
 * @copyright (c) 2016 andy. All rights reserved.
 */

#ifndef EXAMPLE_LIB_INCLUDE_EXAMPLE_CALC_H_
#define EXAMPLE_LIB_INCLUDE_EXAMPLE_CALC_H_

namespace Example {

class Calc {
 public:
  template<typename T>
      T add(T summand1, T summand2) const;
};

} /* namespace Example */

#endif  // EXAMPLE_LIB_INCLUDE_EXAMPLE_CALC_H_
