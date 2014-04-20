#include <stdint.h>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>

static const int64_t COIN = 100000000;

int static generateMTRandom(unsigned int s, int range)
{
    boost::mt19937 gen(s);
    boost::uniform_int<> dist(1, range);
    return dist(gen);
}

int64_t static GetBlockBaseValue(int nHeight)
{
    int64_t nSubsidy = 0;

    int StartOffset;
    int WormholeStartBlock;
    int mod = nHeight % 36000;
    if (mod != 0) mod = 1;
    int epoch = (nHeight / 36000) + mod;

    long wseed = 5299860 * epoch; // Discovered: 1952, Atomic number: 99 Melting Point: 860

    StartOffset = generateMTRandom(wseed, 35820);
    WormholeStartBlock = StartOffset + ((epoch - 1)  * 36000); // Wormholes start from Epoch 2


    if(epoch > 1 && nHeight >= WormholeStartBlock && nHeight < WormholeStartBlock + 180)
    {
        nSubsidy = 2973 * COIN;
    }
    else
{
    if (nHeight == 1) nSubsidy = 10747 * COIN;
    else if (nHeight <= 72000) nSubsidy = 1024 * COIN;
    else if(nHeight <= 144000) nSubsidy = 512 * COIN;
    else if(nHeight <= 288000) nSubsidy = 256 * COIN;
    else if(nHeight <= 432000) nSubsidy = 128 * COIN;
    else if(nHeight <= 576000) nSubsidy = 64 * COIN;
    else if(nHeight <= 864000) nSubsidy = 32 * COIN;
    else if(nHeight <= 1080000) nSubsidy = 16 * COIN;
    else if (nHeight <= 1584000) nSubsidy = 8 * COIN;
    else if (nHeight <= 2304000) nSubsidy = 4 * COIN;
    else if (nHeight <= 5256000) nSubsidy = 2 * COIN;
    else if (nHeight <= 26280000) nSubsidy = 1 * COIN;

}

    return nSubsidy;
}

using namespace boost::python;
BOOST_PYTHON_MODULE(einsteinium_subsidy)
{
    def("GetBlockBaseValue", GetBlockBaseValue);
}
