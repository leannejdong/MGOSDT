#ifndef INDEX_H
#define INDEX_H

#include <math.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>
#include <tbb/scalable_allocator.h>
//#include <simdpp/simd.h>

#ifdef INCLUDE_OPENCL
#include <opencl/cl.hpp>
#endif

#include "integrity_violation.hpp"
#include "bitmask.hpp"

// @note: vector type used for representing GPU floating point vector
using blasvector = boost::numeric::ublas::vector<float>;
// @note: vector type used for representing GPU mask
using blasmask = boost::numeric::ublas::vector<bitblock>;

// Container used to store prefix sums of vectors which help accelerate our calculations
// multiple vectors are stored in this container so that ranges don't need to be recomputed for each vector
class Index {
public:
    static void precompute();
    void benchmark() const;

    Index();
    // @param source: vector of floating points to sum over (efficiently)
    Index(std::vector< std::vector< float > > const & source);
    ~Index();

    // @param indicator: mask of bits indicating which elements are relevant to the vector sum
    // @returns the total of all elements associated to bits that were set to 1
    void sum(Bitmask const & indicator, float * accumulator) const;

    // @returns string representation of original floating points (used for inspection)
    std::string to_string() const;

private:
    // Copy of the original floating points
    std::vector< float > source;
    // precomputed representation of the floating point vector
    std::vector< std::vector< float > > prefixes;
    // Number of floating points represented in the source vector
    unsigned int size;
    unsigned int width;
    // Threshold of queries beyond which a parallel sum is executed
    unsigned int parallel_threshold;
    // Number of blocks expected in bitmask
    unsigned int num_blocks;

    // Initialize the OpenCL implementation to perform our sum in parallel
    void initialize_kernel();

    // @param indicator: array of blocks of bits indicating which elements are relevant to the vector sum
    // @returns the total of all elements associated to bits that were set to 1
    // @note: This implementation uses look-up to precomputed values of the run-length-code for fast sums
    void block_sequential_sum(bitblock * blocks, float * accumulator) const;
    void block_sequential_sum(rangeblock block, unsigned int offset, float * accumulator) const;

    // @param indicator: array of blocks of bits indicating which elements are relevant to the vector sum
    // @returns the total of all elements associated to bits that were set to 1
    // @note: This implementation computes run-length-code for fast sums
    void bit_sequential_sum(Bitmask const &indicator, float *accumulator) const;

    // @param indicator: array of blocks of bits indicating which elements are relevant to the vector sum
    // @returns the total of all elements associated to bits that were set to 1
    // @note this implementation uses OpenCL kernels to sum in parallel
    void parallel_sum(bitblock * blocks, float * accumulator, bool blocking = true, bool profile = false) const;

    // @param source: The original vector of floats used in computation
    // @modifies prefixes: writes the prefix sums into this vector
    void build_prefixes(std::vector< std::vector< float > > const & source, std::vector< std::vector< float > > & prefixes);
#ifdef INCLUDE_OPENCL
    static cl::Device device;
    static cl::Platform platform;
    static cl::Context context;
    static cl::Program program;
    static cl::CommandQueue queue;
    static unsigned int group_size;

    cl::Buffer data_buffer;

    void initialize_driver(void);

    void set_platform(int index = 0);
    void set_device(cl::Platform platform, int index, bool display = false);
#endif
};
#endif