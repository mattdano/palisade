/**
 * @file distributiongenerator.h This code provides basic structure for distribution generators. This should be inherited by all other distribution generators.
 * @author  TPOC: contact@palisade-crypto.org
 *
 * @copyright Copyright (c) 2019, New Jersey Institute of Technology (NJIT)
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef LBCRYPTO_MATH_DISTRIBUTIONGENERATOR_H_
#define LBCRYPTO_MATH_DISTRIBUTIONGENERATOR_H_

#include <chrono>
#include <memory>
#include <mutex>
#include <random>
#include <thread>
#include "backend.h"

//#define FIXED_SEED // if defined, then uses a fixed seed number for reproducible results during debug. Use only one OMP thread to ensure reproducibility

namespace lbcrypto {

/**
* @brief Abstract class describing generator requirements.
*
* The Distribution Generator defines the methods that must be implemented by a real generator.
* It also holds the single PRNG, which should be called by all child class when generating a random number is required.
*
*/

class PseudoRandomNumberGenerator {
public:
	static std::mt19937 &GetPRNG () {

		// initialization of PRNGs
		if (!m_flag) {
#if defined(FIXED_SEED)
			//TP: Need reproducibility to debug NTL.
			std::cerr << "**FOR DEBUGGING ONLY!!!!  Using fixed initializer for PRNG. Use a single thread only!" << std::endl;
			std::mt19937 *gen;
			gen = new std::mt19937(1);
			gen->seed(1);
			m_prng.reset(gen);
			m_flag = true;
#else
#pragma omp critical
			{
				m_flag = true;
			}
#pragma omp parallel
			{
				m_prng.reset(new std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count()+std::hash<std::thread::id>{}(std::this_thread::get_id())));
			}
#endif
		}

		return *m_prng;

	}

private:

	// flag for initializing the PRNGs for each thread
	static bool 							m_flag;

	static std::shared_ptr<std::mt19937> 	m_prng;
#if !defined(FIXED_SEED)
	// avoid contention on m_prng 
    #pragma omp threadprivate(m_prng)
#endif
};

// Base class for Distribution Generator by type
template<typename VecType>
class DistributionGenerator {
public:
	DistributionGenerator () {}
	virtual ~DistributionGenerator() {}
};

} // namespace lbcrypto

#endif // LBCRYPTO_MATH_DISTRIBUTIONGENERATOR_H_
