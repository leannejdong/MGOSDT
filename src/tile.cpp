#include "tile.hpp"

Tile::Tile(Bitmask const & content, unsigned int width) : _content(content), _width(width) {}

Tile::Tile(Bitmask const & samples, Bitmask const & features, unsigned int id) {

}

Tile::Tile() {};
Tile::~Tile() {};

Tile & Tile::operator=(Tile const & other) {
    this -> _content = other._content;
    this -> _width = other._width;
    return * this;
};

bool Tile::operator==(Tile const & other) const {
    return (this -> _width == other._width) && (this -> _content == other._content);
}

bool Tile::operator!=(Tile const & other) const {
    return !(* this == other);
}

size_t Tile::hash() const {
    size_t seed = this -> _width;
    seed ^= this -> _content.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
}

unsigned int Tile::size() const { return this -> _content.size(); }

void Tile::resize(unsigned int new_size) { this -> _content.resize(new_size); }

Bitmask & Tile::content() { return this -> _content; }
void Tile::content(Bitmask const & _new_content) { this -> _content = _new_content; }

unsigned int Tile::width() const { return this -> _width; }
void Tile::width(unsigned int _new_width) { this -> _width = _new_width; }

std::string Tile::to_string() const {
    if (this -> _content.size() == 0) { return "Empty"; }

    std::stringstream stream;
    // for (unsigned int i = 0; i < this -> _content.size(); ++i) {
    //     stream << (int)(this -> _content.get(i));
    //     if (((i + 1) % this -> _width) == 0 && i < this -> _content.size() - 1) {
    //         stream << std::endl;
    //     }
    // }
    stream << this -> _width;
    stream << " : ";
    stream << this -> _content.to_string();
    return stream.str();
}