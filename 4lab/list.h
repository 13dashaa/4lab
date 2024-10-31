//#pragma once
//#include "PoliticalEducator.h"
//#include <iostream>
//#include <iomanip>
//#include <vector>
//
//using namespace std;
//template <typename T>
//class Node
//{
//public:
//    T data;
//    Node* next;
//    Node* prev;
//    Node(T data = T(), Node* prev = nullptr, Node* next = nullptr) {
//        this->data = data;
//        this->next = next;
//        this->prev = prev;
//    }
//};
//template <typename T>
//class List
//{
//    Node<T>* head;
//    Node<T>* tail;
//    int Size;
//public:
//    List();
//    List(int n, T value);
//    ~List();
//
//    void push_back(T data);
//    void push_front(T data);
//    int GetSize() { return Size; };
//    T& front();
//    T& back();
//    void pop_front();
//    void pop_back();
//    void clear();
//    void show() const;
//    List<T> search(const std::string& name = "",
//        const std::string& surname = "",
//        int year_of_birth = -1,
//        const std::string& speciality = "",												//специальность
//        const std::vector<std::string>& scientific_works = {},
//        const std::string& position = "",
//        const std::string& party_name = "",
//        const std::vector<std::string>& autobiography = {},
//        const std::vector<std::string>& works = {});
//    /*class Iterator {
//    private:
//        Node<T>* current;
//
//    public:
//        Iterator(Node<T>* node) : current(node) {}
//
//        T& operator*() { return current->data; }
//        Iterator& operator++() {
//            current = current->next;
//            return *this;
//        }
//        bool operator!=(const Iterator& other) const {
//            return current != other.current;
//        }
//    };*/
//    T& operator[](const int index);
//
//
//    friend std::istream& operator>><T>(std::istream& is, List<T>& list);
//
//    friend std::ostream& operator <<<T>(std::ostream& os, const List<T>& list);
//};
