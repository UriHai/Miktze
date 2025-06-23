#include "Miktze.h"

#include <iostream>
#include <memory>
#include <string>

using std::bad_alloc;
using std::cout;
using std::endl;
using std::string;

Attachment* attachments = nullptr;

Attachment::Attachment(size_t AllocationSize) : m_allocationSize(AllocationSize), m_next(nullptr) {
    // Left blank intentionally
}

size_t Attachment::getAllocationSize() const {
    return m_allocationSize;
}

Attachment* Attachment::getNext() const {
    return m_next;
}

void Attachment::setAllocationSize(size_t allocationSize) {
    m_allocationSize = allocationSize;
}

void Attachment::setNext(Attachment* next) {
    m_next = next;
}

void* operator new(size_t size) {
    Attachment* newAttachment = (Attachment*)(malloc(sizeof(*newAttachment) + size));
    if (!newAttachment) {
        throw bad_alloc();
    }

    newAttachment->setAllocationSize(size);
    newAttachment->setNext(nullptr);

    if (!attachments) {
        attachments = newAttachment;
    } else {
        Attachment* node = attachments;
        while (node->getNext()) {
            node = node->getNext();
        }
        node->setNext(newAttachment);
    }
    return (void*)(newAttachment + 1);
}

void operator delete(void* pointer) {
    if (!attachments || !pointer) {
        throw BadFree();
    }
    Attachment* attachment = (Attachment*)pointer - 1;
    Attachment* node = attachments;

    if (node == attachment) {
        attachments = attachments->getNext();
        free(attachment);
        return;
    }
    while (node) {
        if (node->getNext() == attachment) {
            node->setNext(attachment->getNext());
            free(attachment);
            return;
        }
        node = node->getNext();
    }
    throw BadFree();
}

void printAttachments() {
    Attachment* node = attachments;
    while (node) {
        cout << "Address: " << node + 1 << " Size: " << node->getAllocationSize() << endl;
        node = node->getNext();
    }
}

BadFree::BadFree() {
    cout << "Cannot free memory that was not allocated using malloc" << endl;
}
