//
// Created by ajun on 3/28/24.
//

#ifndef EX03_ENUM_SEASON_H
#define EX03_ENUM_SEASON_H


#include <string>
#include <utility>
#include <vector>

class Season {
private:
    int id;
    std::string n;
    inline Season(int id, std::string n) : id(id), n(std::move(n)) {};
    static const Season* VALUES[];
public:
    static const Season Winter, Spring, Summer, Autumn;
    static Season get(int i);
    static size_t size();
    static const Season* values();

    [[nodiscard]] std::string name() const;
    [[nodiscard]] int index() const;
};


#endif //EX03_ENUM_SEASON_H
