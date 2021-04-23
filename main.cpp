#include <iostream>
#include "sol2/include/sol/sol.hpp"



static void hello_sol()
{
	std::cout << "Hello from sol" << std::endl;
}

int main(void)
{
	std::cout << "Hello, World !" << std::endl;

	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::coroutine, sol::lib::string, sol::lib::os, sol::lib::math, sol::lib::table, sol::lib::io, sol::lib::debug);

	lua["hello"] = &hello_sol;

	auto res = lua.safe_script(R"(hello())");

	return 0;
}