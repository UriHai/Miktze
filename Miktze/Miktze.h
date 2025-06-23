#pragma once

class Attachment final {
private:
	size_t m_allocationSize;
	Attachment* m_next;

public:
	/**
	 * @brief								Attachment constructor
	 *
	 * @param allocationSize		[IN]	Allocation size
	 */
	explicit Attachment(size_t allocationSize);

	// Get Allocation size
	size_t getAllocationSize() const;

	// Get next Allocation
	Attachment* getNext() const;

	// Set Allocation size
	void setAllocationSize(size_t allocationSize);

	// Set next Allocation
	void setNext(Attachment* next);
};

/**
 * @brief									"new" operator - dynamically allocate memory
 *
 * @param size						[IN]	Allocation size
 * @return									Pointer to the allocated memory
 */
void* operator new(size_t size);

/**
 * @brief									"delte" operator - free dynamically allocated memory
 *
 * @param size						[IN]	Pointer to the allocation
 */
void operator delete(void* pointer);

// Print addresses and sizes of all Allocations
void printAttachments();

class BadFree {
public:
	// BadFree error constructor
	BadFree();
};