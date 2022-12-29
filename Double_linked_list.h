#include <iostream>

template<class T>
class DLL {
public:
    class Node {
    public:
        T val;
        Node *next, *prev;

        Node();
        Node(const T&);
    };

private:
    Node *head, *tail;

    void set_null();
    void set_not_null();

public:

    DLL();

    Node* begin() const;

    bool empty();

    void push_front(const T&);
    void push_back(const T&);

    void pop_front();
    void pop_back();

    void push(Node*, const T&);
    void pop(Node*);

    Node* find(const T&);

    void erase(const T&);

    template<class> friend std::ostream& operator<<(std::ostream&, const DLL&);

    template<class> friend DLL operator+(const DLL&, const DLL&);

    void sort();
};

template<class T>
void DLL<T>::set_null() {
    if (!head->next || !tail->prev) {
        head->next = nullptr;
        tail->prev = nullptr;
    }
}

template<class T>
void DLL<T>::set_not_null() {
    if (head->next && !tail->prev)
        tail->prev = head->next;
    if (!head->next && tail->prev)
        head->next = tail->prev;
}

template<class T>
typename DLL<T>::Node* DLL<T>::begin() const {
    return head->next;
}

template<class T>
DLL<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
}

template<class T>
DLL<T>::Node::Node(const T & val_) {
    val = val_;
    next = nullptr;
    prev = nullptr;
}

template<class T>
DLL<T>::DLL() {
    head = new Node();
    tail = new Node();
}

template<class T>
bool DLL<T>::empty() {
    return !head->next;
}

template<class T>
void DLL<T>::push_front(const T & val) {
    Node* v = new Node(val);
    v->next = head->next;
    if (v->next)
        v->next->prev = v;
    head->next = v;
    set_not_null();
}

template<class T>
void DLL<T>::push_back(const T & val) {
    Node* v = new Node(val);
    v->prev = tail->prev;
    if (v->prev)
        v->prev->next = v;
    tail->prev = v;
    set_not_null();
}

template<class T>
void DLL<T>::pop_front() {
    Node* v = head->next;
    head->next = head->next->next;
    head->next->prev = nullptr;
    delete v;
    set_null();
}

template<class T>
void DLL<T>::pop_back() {
    Node *v = tail->prev;
    tail->prev = tail->prev->prev;
    tail->prev->next = nullptr;
    delete v;
    set_null();
}

template<class T>
void DLL<T>::push(DLL::Node * v, const T& val) {
    Node* u = head;
    while (u->next != v)
        v = v->next;
    Node* w = new Node(val);
    w->next = u->next;
    u->next = w;
    set_not_null();
}

template<class T>
void DLL<T>::pop(DLL::Node * v) {
    Node* u = head;
    while (u->next != v)
        u = u->next;
    u->next = u->next->next;
    delete v;
    set_null();
}

template<class T>
typename DLL<T>::Node* DLL<T>::find(const T & val) {
    for (auto v = this->begin(); v; v = v->next)
        if (v->val == val)
            return v;
    return nullptr;
}

template<class T>
void DLL<T>::erase(const T & val) {
    pop(find(val));
}

template<class T>
std::ostream &operator<<(std::ostream & out, const DLL<T> & l) {
    for (auto v = l.begin(); v; v = v->next)
        out << v->val << " ";
    return out;
}

template<class T>
DLL<T> operator+(const DLL<T> & l1, const DLL<T> & l2) {
    auto ret = l1;
    for (auto v = l2.begin(); v; v = v->next)
        ret.pushBack(v->val);
    return ret;
}
