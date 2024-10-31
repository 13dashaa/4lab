#include "List2.h"
#include "PoliticalEducator.h"


// Реализация методов класса List
template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
List<T>::List(int n, T value) : List() {
    while (Size != n) {
        push_front(value);
    }
}

template<typename T>
List<T>::~List() {
    while (Size != 0) {
        pop_back();
    }
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        tail = head = new Node<T>(data);
    }
    else {
        tail->next = new Node<T>(data, tail);
        tail = tail->next;
    }
    Size++;
}

template<typename T>
void List<T>::push_front(T data) {
    if (head == nullptr) {
        tail = head = new Node<T>(data);
    }
    else {
        head->prev = new Node<T>(data, nullptr, head);
        head = head->prev;
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index) {
    int counter = 0;
    Node <T>* current = this->head;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->next;
        counter++;
    }
}

template<typename T>
T& List<T>::front() {
    return head->data;
}

template<typename T>
T& List<T>::back() {
    return tail->data;
}

template<typename T>
void List<T>::pop_front() {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    Size--;
}

template<typename T>
void List<T>::pop_back() {
    Node <T>* temp = tail;
    tail = tail->prev;
    delete temp;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    Size--;
}

template<typename T>
void List<T>::clear() {
    while (Size != 0) {
        pop_front();
    }
}

template<typename T>
void List<T>::show() const {
    Node <T>* current = this->head;
    while (current != nullptr) {
        std::cout << current->data;
        current = current->next;
        if (current) {
            std::cout << " ";
        }
    }
}

template<typename T>
List<T> List<T>::search(const std::string& name, const std::string& surname, int year_of_birth, 
    const std::string& speciality, const std::vector<std::string>& scientific_works,
    const std::string& position, const std::string& party_name, 
    const std::vector<std::string>& autobiography, const std::vector<std::string>& works)
{
    List<T> results;
    Node<T>* current = head;
    while (current != nullptr) {
        if ((name.empty() || current->data.GetName() == name) &&
            (surname.empty() || current->data.GetSurname() == surname) &&
            (year_of_birth == -1 || current->data.Get_year_of_birth() == year_of_birth) &&
            (speciality.empty() || dynamic_cast<Teacher*>(&current->data)->GetSpeciality() == speciality) &&
            (scientific_works.empty() || dynamic_cast<Teacher*>(&current->data)->GetScientificWorks() == scientific_works) &&
            (position.empty() || dynamic_cast<Teacher*>(&current->data)->GetPosition() == position) &&
            (party_name.empty() || dynamic_cast<Party_member*>(&current->data)->GetParty_name() == party_name) &&
            (autobiography.empty() || dynamic_cast<Party_member*>(&current->data)->GetAutobiography() == autobiography) &&
            (works.empty() || dynamic_cast<PoliticalEducator*>(&current->data)->GetPoliticalWorks() == works))
        {
            results.push_back(current->data);
        }
        current = current->next;
    }

    return results;

}
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
//    for (const T& elem : vec) {
//        os << elem << " ";
//    }
//    return os;
//}