#include "ForwardList.h"
// ctors

ForwardList::ForwardList()
{
    first = nullptr;
    count = 0;
};


ForwardList::ForwardList(const ForwardList &other)
{
    *this = other;
};

ForwardList::ForwardList(const std::initializer_list<value_type> &ilist){
    if (ilist.size() > 0) {
        Node* last{};
        std::initializer_list<value_type>::iterator it = ilist.begin();

        first = new Node{ *it, nullptr};
        last = first;

        for (++it; it != ilist.end(); ++it){
            last->link = new Node{ *it, nullptr };
            last = last->link;
        }

        count = ilist.size();
    }
};

// dtor
ForwardList::~ForwardList(){ clear(); };

// copy assignment
ForwardList &ForwardList::operator=(const ForwardList& rhs)
{
  if (this != &rhs ){
    while (size() <rhs.size()) {
        insert(begin(), 0);
    }

    while (size() > rhs.size()){
        erase(begin());
    }

    std::copy(rhs.begin(), rhs.end(), begin());
  }

  return *this;
};

/// Clears the contents
void ForwardList::clear()
{
    while (!empty()) {
        erase(begin());
    }

    assert(first == nullptr);
    assert(count == 0);
};

/// Inserts a value before pos
ForwardList::iterator ForwardList::insert(ForwardList::iterator pos, const ForwardList::value_type &value)
{
   Node *node = new Node{value, nullptr};   // Node to become inserted

   if(pos == begin() || empty()) {
    
        node->link = first;                 // insert before first
        first = node;                       // update first pointer

   } else {

        Node* previous = first;
        Node* current = first->link;

        while (current != nullptr && current != pos.operator->()) {
            previous = current;
            current = current->link;
        }

        node->link = previous->link;
        previous->link = node;

   }
   count ++;

   return iterator{ node };
};

/// Erases an element at pos
ForwardList::iterator ForwardList::erase(ForwardList::iterator pos){
    if (empty()) {
        pos = end();
    } else if (pos == begin()) {
        //case 1: item to be deleted is first node of the list
        const Node* tmp = first;
        pos = iterator(first->link);
        first = first->link;
        delete tmp;
        --count;
    } else {
        //case 2: item to be deleted is somewhere in the list
        Node* previous = first;             // trailing pointer
        Node* current = first->link;        // traversal pointer

        // this loop will trail the list looking for the node before pos
        while (current != nullptr && current != pos.operator->()) {
            previous = current;             
            current = current->link;
        }

        if (current != nullptr){
            pos = iterator(current->link);  // node following the erased node
            previous->link = current->link; // remove the node from the list
            delete current;                 // reclaim mem
            current = nullptr;              // no dangling pointers
            --count;

        }
        
    }

    return pos;
};

/** NON-MEMBER FUNCTIONS **/

/// Equality comparison operator.
bool operator==(const ForwardList &lhs, const ForwardList &rhs){
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};

/// Inequality comparison operator.
bool operator!=(const ForwardList &lhs, const ForwardList &rhs){
    return !(lhs == rhs);
};
