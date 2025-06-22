#pragma once

class Attachment final {
private:
	size_t m_allocationSize;
	Attachment* m_next;

public:
	explicit Attachment(size_t allocationSize);
	size_t getAllocationSize() const;
	Attachment* getNext() const;
	void setAllocationSize(size_t allocationSize);
	void setNext(Attachment* next);
};

void* operator new(size_t size);

void operator delete(void* pointer);

void printAttachments()