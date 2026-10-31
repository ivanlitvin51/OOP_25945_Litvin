add_test([=[HypoBasicTest.IntegerArguments]=]  D:/NSU/OOP/hw_05/build/tests/hypo_tests.exe [==[--gtest_filter=HypoBasicTest.IntegerArguments]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HypoBasicTest.IntegerArguments]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[D:/NSU/OOP/hw_05/tests/test_hypo.cpp:11]==]
    WORKING_DIRECTORY [==[D:/NSU/OOP/hw_05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[HypoBasicTest.DoubleArguments]=]  D:/NSU/OOP/hw_05/build/tests/hypo_tests.exe [==[--gtest_filter=HypoBasicTest.DoubleArguments]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HypoBasicTest.DoubleArguments]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[D:/NSU/OOP/hw_05/tests/test_hypo.cpp:26]==]
    WORKING_DIRECTORY [==[D:/NSU/OOP/hw_05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[HypoRandomTest.RangeCheck]=]  D:/NSU/OOP/hw_05/build/tests/hypo_tests.exe [==[--gtest_filter=HypoRandomTest.RangeCheck]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HypoRandomTest.RangeCheck]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[D:/NSU/OOP/hw_05/tests/test_hypo.cpp:40]==]
    WORKING_DIRECTORY [==[D:/NSU/OOP/hw_05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[ExpectVsAssertDemo.FailingDemonstration]=]  D:/NSU/OOP/hw_05/build/tests/hypo_tests.exe [==[--gtest_filter=ExpectVsAssertDemo.DISABLED_FailingDemonstration]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ExpectVsAssertDemo.FailingDemonstration]=]
  PROPERTIES
    DISABLED YES
    DEF_SOURCE_LINE [==[D:/NSU/OOP/hw_05/tests/test_hypo.cpp:83]==]
    WORKING_DIRECTORY [==[D:/NSU/OOP/hw_05/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(hypo_tests_TESTS [==[HypoBasicTest.IntegerArguments]==] [==[HypoBasicTest.DoubleArguments]==] [==[HypoRandomTest.RangeCheck]==] [==[ExpectVsAssertDemo.FailingDemonstration]==])
