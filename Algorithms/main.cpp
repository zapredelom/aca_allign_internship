#include <chrono>
#include <iostream>
#include <random>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "DynamicProgramming.hpp"
#include "HashTable.h"
#include "Measurer.hpp"
void merge_sort(std::vector<int>& v, int begin, int end);
void merge(std::vector<int>& v, int begin, int mid, int end);

void sort(std::vector<int>& v) { merge_sort(v, 0, int(v.size())); }

void buble_sort(std::vector<int>& v, int begin, int end) {
    for (int i = begin; i < end; i++) {
        for (int j = i; j < end; j++) {
            if (v[i] >= v[j])
                std::swap(v[i], v[j]);
        }
    }
}

void merge_sort(std::vector<int>& v, int begin, int end) {
    if (end - begin <= 128) {
        buble_sort(v, begin, end);
        return;
    }

    int mid = begin + (end - begin) / 2;

    merge_sort(v, begin, mid);
    merge_sort(v, mid, end);
    merge(v, begin, mid, end);
}

void merge(std::vector<int>& v, int begin, int mid, int end) {
    int index1 = begin;
    int index2 = mid;
    std::vector<int> tmp;
    while (index1 < mid && index2 < end) {
        if (v[index1] < v[index2]) {
            tmp.push_back(v[index1]);
            index1++;
        } else {
            tmp.push_back(v[index2]);
            index2++;
        }
    }
    while (index1 < mid) {
        tmp.push_back(v[index1++]);
    }
    while (index2 < end) {
        tmp.push_back(v[index2++]);
    }
    for (int i : tmp) {
        v[begin] = i;
        begin++;
    }
}
bool isValidNumber(const std::string& numstr) {
    if (numstr.size() > 3)
        return false;
    bool isLeadingZero = numstr.size() > 1 && numstr[0] == '0';
    if (isLeadingZero)
        return false;
    int value = 0;
    int ten = 1;
    for (size_t i = numstr.size() - 1; i >= 0; --i) {
        if (numstr[i] < '0' || numstr[i] > '9')
            return false;
        value += ten * (numstr[i] - '0');
        ten *= 10;
    }
    if (value > 255)
        return false;
    return true;
}
bool IsValidIp(const std::string& ip) {
    auto DotCount = std::count_if(begin(ip), end(ip), [](char ch) { return ch == '.'; });
    // alternatively can be writen
    // auto DotCount = std::count(begin(ip), end(ip), '.');
    if (DotCount != 3)
        return false;
    std::string current = "";
    int currentIndex = 0;
    do {
        if (ip[currentIndex] != '.') {
            current += ip[currentIndex];
        } else {
            if (!isValidNumber(current))
                return false;
            current = "";
        }
        currentIndex++;
    } while (currentIndex < ip.size());
    return true;
}

int main() {
    HashTable<std::string, std::hash<std::string>> t;
    for (int i = 0; i < 200; i++) {
        t.insert(std::to_string(i));
    }

    t.for_each([](const auto& v) { std::cout << v << " "; });

    std::cout<<"\n\n\n\n";
    HashTable<std::string, std::hash<std::string>> t2 = t;
        t.clear();
    t2.for_each([](const auto& v) { std::cout << v << " "; });

}