#ifndef METRICS_HH
#define METRICS_HH

#include <memory>
#include <iostream>

struct AllocationMetrics
{
	uint32_t totalAllocated = 0;
	uint32_t totalFreed = 0;

	uint32_t CurrentUsage() { return totalAllocated - totalFreed; }
};

inline static AllocationMetrics s_AllocationMetrics;

static void PrintMemoryUsage()
{
	std::cout << "Memory Usage " << s_AllocationMetrics.CurrentUsage() << " Bytes\n";
}

inline void *operator new(size_t size)
{
	s_AllocationMetrics.totalAllocated += size;
	std::cout << "Allocating " << size << " Bytes\n";
	PrintMemoryUsage();
	return malloc(size);
}
inline void operator delete(void *memory, size_t size)
{
	s_AllocationMetrics.totalFreed += size;
	std::cout << "Freeing " << size << " Bytes\n";
	PrintMemoryUsage();
	free(memory);
}



#endif //..