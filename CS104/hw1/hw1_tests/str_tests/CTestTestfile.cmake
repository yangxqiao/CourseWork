# CMake generated Testfile for 
# Source directory: /home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests
# Build directory: /home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(StrTestConstructorTests.DefaultConstructor "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestConstructorTests.DefaultConstructor")
add_test(StrTestConstructorTests.CharArrayConstructor "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestConstructorTests.CharArrayConstructor")
add_test(StrTestConstructorTests.NullInputConstructor "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestConstructorTests.NullInputConstructor")
add_test(StrTestConstructorTests.StrConstructor "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestConstructorTests.StrConstructor")
add_test(StrTestOpAssign.AssignStr "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpAssign.AssignStr")
add_test(StrTestOpAssign.AssignSelf "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpAssign.AssignSelf")
add_test(StrTestOpAssign.NullData "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpAssign.NullData")
add_test(StrTestOpAssign.AssignCharArrayToNull "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpAssign.AssignCharArrayToNull")
add_test(StrTestOpAssign.AssignCharArray "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpAssign.AssignCharArray")
add_test(StrTestOpPlus.AddTwoStrings1 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpPlus.AddTwoStrings1")
add_test(StrTestOpPlus.AddSelf "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpPlus.AddSelf")
add_test(StrTestOpPlus.AddCharArray "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestOpPlus.AddCharArray")
add_test(StrTestRelationalOps.Equals "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestRelationalOps.Equals")
add_test(StrTestRelationalOps.Neq "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestRelationalOps.Neq")
add_test(StrTestRelationalOps.LessThanGreaterThan "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestRelationalOps.LessThanGreaterThan")
add_test(StrTestPlusEq.PlusEqStr "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestPlusEq.PlusEqStr")
add_test(StrTestPlusEq.PlusEqCharArray "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestPlusEq.PlusEqCharArray")
add_test(StrTestPlusEq.PlusEqSelf "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestPlusEq.PlusEqSelf")
add_test(StrTestSize.ConstructorSizes "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestSize.ConstructorSizes")
add_test(StrTestSize.AdditionSizes "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestSize.AdditionSizes")
add_test(StrTestSize.SizeTracking "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestSize.SizeTracking")
add_test(StrTestIndexing.NormalIndex "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestIndexing.NormalIndex")
add_test(StrTestIndexing.IndexOutOfRange "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestIndexing.IndexOutOfRange")
add_test(StrTestIOStream.PrintTest "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_tests" "--gtest_filter=StrTestIOStream.PrintTest")
add_test(StrRuntime.Concatenate "/home/cs104/CS_104/hw-xiaoyanq/hw1/hw1_tests/str_tests/str_runtime_tests" "--gtest_filter=StrRuntime.Concatenate")
