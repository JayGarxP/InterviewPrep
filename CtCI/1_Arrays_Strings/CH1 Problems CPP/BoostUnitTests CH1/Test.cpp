#define BOOST_TEST_MODULE chOneTests
/*
Using Boost-test to unit test Cracking the Coding Interview solutions

https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-boost-test-for-cpp?view=vs-2019
I used the vcpkg setup; make sure to run cmd: vcpkg integrate install
 this will simplify your life greatly, you wont have to manually link to standalone boost libraries EVERY single project you make
*/
//#include <boost/test/included/unit_test.hpp> //standalone

#include <boost/test/unit_test.hpp> // precompiled

//BOOST_AUTO_TEST_CASE(myTestCase)
//{
//  BOOST_TEST(1 == 1);
//  BOOST_TEST(true);
//}