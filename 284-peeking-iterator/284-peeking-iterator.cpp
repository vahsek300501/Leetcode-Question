/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int m_next;
    bool m_hasnext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    m_hasnext = Iterator::hasNext();
	    if (m_hasnext) m_next = Iterator::next();
	}

	int peek() {
        return m_next;
	}

	int next() {
	    int t = m_next;
	    m_hasnext = Iterator::hasNext();
	    if (m_hasnext) m_next = Iterator::next();
	    return t;
	}

	bool hasNext() const {
	    return m_hasnext;
	}
};