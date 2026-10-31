add_test([=[HypoBasicTest.IntValues]=]  /Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests/hypo_tests [==[--gtest_filter=HypoBasicTest.IntValues]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HypoBasicTest.IntValues]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/tests/test_hypo.cpp:6]==]
    WORKING_DIRECTORY [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[HypoRandomTest.RangeCheck]=]  /Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests/hypo_tests [==[--gtest_filter=HypoRandomTest.RangeCheck]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HypoRandomTest.RangeCheck]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/tests/test_hypo.cpp:12]==]
    WORKING_DIRECTORY [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[ExpectVsAssert.ExpectFailsAndContinues]=]  /Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests/hypo_tests [==[--gtest_filter=ExpectVsAssert.ExpectFailsAndContinues]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ExpectVsAssert.ExpectFailsAndContinues]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/tests/test_hypo.cpp:23]==]
    WORKING_DIRECTORY [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[ExpectVsAssert.AssertFailsAndStops]=]  /Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests/hypo_tests [==[--gtest_filter=ExpectVsAssert.AssertFailsAndStops]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ExpectVsAssert.AssertFailsAndStops]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/tests/test_hypo.cpp:29]==]
    WORKING_DIRECTORY [==[/Users/ivanlitvin/NSU/OOP/hw_05/steps/step_5_3/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(hypo_tests_TESTS [==[HypoBasicTest.IntValues]==] [==[HypoRandomTest.RangeCheck]==] [==[ExpectVsAssert.ExpectFailsAndContinues]==] [==[ExpectVsAssert.AssertFailsAndStops]==])
