
#include <cassert>

auto main() -> int {
	//static_assert(4 == 5, "So sad");
	//assert(4 == 5);
	auto sum = 0;
	for (auto loopIntegter = 0; loopIntegter <= 100; ++loopIntegter) {
		sum += loopIntegter;
	}
}
