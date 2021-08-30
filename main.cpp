#include <iostream>
#include <fc/crypto/private_key.hpp>

int main() {
    auto key = fc::crypto::private_key::generate<fc::ecc::private_key_shim>();
    auto pub_key = key.get_public_key();
    auto raw_pub_key = std::get<0>(pub_key._storage).serialize();

    return 0;
}
