/* OSQP TESTER MODULE */

/* THE CODE FOR MINIMAL UNIT TESTING HAS BEEN TAKEN FROM
   http://www.jera.com/techinfo/jtns/jtn002.html */

#include <stdio.h>

#include "minunit.h"
#include "osqp.h"
#include "osqp_tester.h"

// Include tests
#include "lin_alg/test_lin_alg.h"
#include "solve_linsys/test_solve_linsys.h"
#include "basic_qp/test_basic_qp.h"
#include "basic_qp2/test_basic_qp2.h"
#include "non_cvx/test_non_cvx.h"
#include "primal_dual_infeasibility/test_primal_dual_infeasibility.h"
#include "primal_infeasibility/test_primal_infeasibility.h"
#include "unconstrained/test_unconstrained.h"
#include "update_matrices/test_update_matrices.h"

#ifdef USE_GTEST
#include <gtest/gtest.h>
#endif

int tests_run = 0;


static char* all_tests() {
  mu_run_test(test_lin_alg);
  mu_run_test(test_solve_linsys);
  mu_run_test(test_basic_qp);
  mu_run_test(test_basic_qp2);
  mu_run_test(test_non_cvx);
  mu_run_test(test_primal_infeasibility);
  mu_run_test(test_primal_dual_infeasibility);
  mu_run_test(test_unconstrained);
  mu_run_test(test_update_matrices);
  return 0;
}


#ifdef USE_GTEST
// Tests for pure Catkin Build
TEST(OSQP, runAllTests) {  // NOLINT
  char *result = all_tests();
  ASSERT_EQ(result, nullptr);
}

#else
int main(void) {
  char *result = all_tests();

  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
#endif
