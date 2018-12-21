#pragma once

#include <chrono>
#include <cstddef>

namespace rai
{
// Network variants with different genesis blocks and network parameters
enum class moore_networks
{
	// Low work parameters, publicly known genesis key, test IP ports
	moore_test_network,
	// Normal work parameters, secret beta genesis key, beta IP ports
	moore_beta_network,
	// Normal work parameters, secret live key, live IP ports
	moore_live_network
};
rai::moore_networks const moore_network = moore_networks::ACTIVE_NETWORK;
std::chrono::milliseconds const transaction_timeout = std::chrono::milliseconds (1000);
}
