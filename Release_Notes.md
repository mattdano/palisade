9/12/2019: PALISADE v1.6.0 is released

* Significantly simplifies/automates the PALISADE build/installation process. Now we use CMake.
* Serialization/deserialization is now much faster (by 3x to 10x). Both binary and JSON formats are supported.
* By default, PALISADE compiles w/o external dependencies in Linux and Windows, i.e., NTL/GMP is now optional for these OSes.
* The performance in Windows is now as fast as in Linux (4x to 7x times faster than previously).
* Applies several low-level optimizations, and fixes some bugs.

3/20/2019: PALISADE v1.5.0 is released

* Fixes the vulnerability found in https://eprint.iacr.org/2017/785 (PKC'19) for the PRE schemes based on BGV/BFV 
* Adds PRE modes for BGV/BFV that are secure under honest re-reencryption attacks (recommended security for practical use)
* Adds support for splitting lattice trapdoor sampling into offline and online phases (used by digital signatures, IBE, and ABE constructions)
* Fixes bugs related to the multi-threaded mode of operation

02/11/2018: PALISADE v1.4.1 is released

Fixes a bug affecting the IBE and CP-ABE implementations (some unit tests for IBE/CP-ABE were entering in an infinite loop in about 10% of the runs).

12/31/2018: PALISADE v1.4.0 is released

* Adds the Gentry-Peikert-Vaikuntanathan (GPV) digital signature scheme
* Adds the GPV identity-based encryption scheme
* Adds the Zhang-Zhang ciphertext-policy attribute-based encryption scheme
* Includes Genise-Micciancio (Eurocrypt'18) lattice trapdoor sampling algorithms and their improvements/generalizations
* Fixes bugs that were brought to our attention

11/26/2018: PALISADE v1.3.1 is released

* Improves performance of BFVrns
* Improves performance of Number Theoretic Transform
* Fixes a bug affecting the demo-cross-correlation demo
* Fixes other bugs that were brought to our attention

10/17/2018: PALISADE v1.3.0 is released

* Added support for the security levels/tables specified by the HomorphicEncryption.org security standard to all variants of the BFV scheme
* Optimized the packed encoding (batching)
* Simplified the signatures of classes and methods at multiple layers
* Fixed bugs that were brought to our attention

6/15/2018: PALISADE v1.2 is released

PALISADE v1.2 provides several important advancements and improvements to the library.  Most notably, we provide:

* The Bajard-Eynard-Hasan-Zucca RNS variant of the BFV scheme is added to the library
* The implementation of the Halevi-Polyakov-Shoup RNS variant of the BFV scheme is significantly improved
* Large multiplicative depths (up to 100 and higher) for both RNS variants are now supported.
* Several low-level optimizations, e.g., in Number Theoretic Transform and NTL multiprecision math backend, are implemented.
* Multiple improvements in plaintext encodings.
* Software engineering improvements: extended batteries of unit tests, cleaner design of the matrix class, better CryptoContext wrapper, etc.
* Fixes for bugs which have been brought to our attention.

1/29/2018: PALISADE v1.1.1 is released

PALISADE v1.1.1 includes bug fixes and minor optimizations:

* Fixes minor bugs in NativeInteger and multiprecision backends (BigInteger)
* Deals properly with a low-probability rounding error in BFVrns
* Fixes a compilation error on some CentOS systems
* Improves the performance of NativeInteger
* Fixes a couple of other minor bugs

12/29/2017: PALISADE v1.1 is released

PALISADE v1.1  includes the following new capabilities, library enhancements, and optimizations:

* New efficient homomorphic scheme: BFVrns
* Newly supported homomorphic operations for multi-depth computations
* Type checking, type safety, and improved error handling
* Faster/more capable Gaussian sampling
* NTL integration as a new option for the multiprecision arithmetic backend
* And more...

07/15/2017: PALISADE v1.0 is released
