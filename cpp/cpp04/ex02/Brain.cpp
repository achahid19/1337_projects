#include "Brain.hpp"

Brain::Brain( void ) {
    std::cout << BLUE;
    std::cout << "[ Brain ]: Default Constructor Called";
    std::cout << RESET_COLOR << std::endl;
}

Brain::Brain( const Brain& other ) {
    std::cout << BLUE;
    std::cout << "[ Brain ]: Copy Constructor Called";
    std::cout << RESET_COLOR << std::endl;
    *this=(other);
}

const Brain& Brain::operator=( const Brain& other ) {
    (void)other;
    std::cout << BLUE;
    std::cout << "[ Brain ]: Copy Assignment Called";
    std::cout << RESET_COLOR << std::endl;
    if (this == &other) return *this;
    for (size_t i = 0; i < IDEAS; i++) {
        this->setIdea(i, other.getIdea(i));
    }
    return *this;
}

Brain::~Brain( void ) {
    std::cout << BLUE;
    std::cout << "[ Brain ]: Destructor Called";
    std::cout << RESET_COLOR << std::endl;
}

void    Brain::setIdea( size_t index, const std::string& idea ) {
    ideas[index] = idea;
}

const std::string& Brain::getIdea( size_t index ) const {
    return ideas[index];
}
