#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T data = T(), Node* prev = nullptr, Node* next = nullptr)
        : data(data), next(next), prev(prev) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int Size;
public:
    List();
    List(int n, T value);
    ~List();
    void push_back(T data);
    void push_front(T data);
    int GetSize() { return Size; };
    T& front();
    T& back();
    void pop_front();
    void pop_back();
    void clear();
    void show() const;
    List<T> search(const std::string& name = "", 
        const std::string& surname = "", 
        int year_of_birth = -1,
        const std::string& speciality = "", const std::vector<std::string>& scientific_works = {},
        const std::string& position = "", const std::string& party_name = "",
        const std::vector<std::string>& autobiography = {}, const std::vector<std::string>& works = {});
    T& operator[](const int index);
    template <typename U>
    friend std::istream& operator>>(std::istream& is, List<U>& list);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
};
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);