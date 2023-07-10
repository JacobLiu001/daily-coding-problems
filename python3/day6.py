# An XOR linked list is a more memory efficient doubly linked list. 
# Instead of each node holding next and prev fields, 
# it holds a field named both, which is an XOR of the next node and the previous node. 
# Implement an XOR linked list; 
# it has an add(element) which adds the element to the end, 
# and a get(index) which returns the node at index.

# If using a language that has no pointers (such as Python), 
# you can assume you have access to get_pointer and dereference_pointer functions 
# that converts between nodes and memory addresses.

from typing import NewType
Ptr = NewType("Ptr", int)  # Make it so that Ptr is a custom type which holds an int
NULL: Ptr = 0  # NULL pointer has the value 0.


class XorLinkedListElement:
    mapper = dict()  # To support dereference_pointer(addr)
    def __init__(self, payload = None, both = None) -> None:
        self.payload = payload
        self.both = both
        XorLinkedListElement.mapper[id(self)] = self
    
    def __repr__(self) -> str:
        return f"XorLinkedListElement(payload = {self.payload}, both = {self.both})"

def get_pointer(x: XorLinkedListElement) -> int:
    return id(x)

def dereference_pointer(addr: int) -> XorLinkedListElement:
    return XorLinkedListElement.mapper[addr]


class XorLinkedList:
    def __init__(self) -> None:
        self.head: Ptr = NULL
        self.end: Ptr = NULL
        self.length: int = 0
    
    def add(self, payload):
        newNode = XorLinkedListElement(payload, self.end)
        newPtr = get_pointer(newNode)
        if self.head == NULL:
            self.head = newPtr
        if self.end != NULL:
            dereference_pointer(self.end).both ^= newPtr
        self.end = newPtr
        self.length += 1
    
    def __iter__(self):
        prev: Ptr = NULL
        cur: Ptr = self.head

        while cur != NULL:
            yield dereference_pointer(cur).payload
            cur, prev = dereference_pointer(cur).both ^ prev, cur
    
    def get(self, index: int) -> XorLinkedListElement:
        # In production code you would raise IndexError
        assert index >= 0 and index < self.length, "Index out of range"
        
        prev: Ptr = NULL
        cur: Ptr = self.head

        while index:
            index -= 1
            cur, prev = dereference_pointer(cur).both ^ prev, cur

        return dereference_pointer(cur)


def main():
    l = XorLinkedList()
    l.add(15)
    l.add(20)
    l.add(30)
    for x in l:
        print(x)
    
    print(l.get(1))


if __name__ == "__main__":
    main()