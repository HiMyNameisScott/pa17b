#ifndef H_FORWARDLIST
#define H_FORWARDLIST
#include <iterator>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iomanip>
#include <cassert>

/// ---------------------------------------------------------------------------
/// A ForwardList is a container that supports fast insertion and removal of
/// elements from anywhere in the container. Fast random access is not
/// supported. It is implemented as a singly-linked list.
///
/// Adding, removing, and moving the elements within the list, or across several
/// lists, does not invalidate the iterators currently referring to other
/// elements in the list. However, an iterator or reference referring to an
/// element is invalidated when the corresponding element is removed (via
/// erase()) from the list.
/// ---------------------------------------------------------------------------

class ForwardList
{
protected:
    /// A ForwardList node.
    struct Node
    {
        int info{};
        Node *link{};
    };

public:
    /// An iterator for ForwardList containers.
    class Iterator
    {
    public:
        // member types (required to integrate with standard library)
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using difference_type = std::ptrdiff_t;
        using pointer = Node *;
        using reference = value_type &;

        Iterator(pointer ptr = nullptr) : current(ptr) {}
        reference operator*() const { return current->info; }
        pointer operator->() { return current; }
        Iterator &operator++()
        {
            current = current->link;
            return *this;
        }

        friend bool operator==(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs.current == rhs.current;
        }

        friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs.current != rhs.current;
        }

    private:
        pointer current; ///< The current node.
    };

    // member types
    using value_type = int;
    using size_type = std::size_t;
    using reference = value_type &;
    using iterator = Iterator;

    // ctors
    ForwardList();
    ForwardList(const ForwardList &other);
    ForwardList(const std::initializer_list<value_type> &ilist);
    // dtor
    virtual ~ForwardList();
    // copy assignment
    ForwardList &operator=(const ForwardList &rhs);

    // iterators
    iterator begin() const { return iterator(first); }
    iterator end() const { return iterator(); }

    // capacity
    bool empty() const { return begin() == end(); }
    size_type size() const { return count; }

    /// Clears the contents
    void clear();
    /// Inserts a value before pos
    iterator insert(iterator pos, const value_type &value);
    /// Erases an element at pos
    iterator erase(iterator pos);

protected:
    Node *first{};     ///< pointer to the head node
    size_type count{}; ///< number of nodes in list
};

/** NON-MEMBER FUNCTIONS **/

/// Equality comparison operator.
bool operator==(const ForwardList &lhs, const ForwardList &rhs);

/// Inequality comparison operator.
bool operator!=(const ForwardList &lhs, const ForwardList &rhs);

///
std::ostream &operator<<(std::ostream &output, const ForwardList &list);

#endif